#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <string.h>

#define PORT 80
#define BUFFER_SIZE 1024

// Flag to keep track of whether the server should be running
volatile int server_running = 1;

// Function for the thread that listens for user input
void* command_listener(void* arg) {
    char command[100];
    while (1) {
        fgets(command, sizeof(command), stdin);

        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "quit") == 0) {
            server_running = 0;
            break;
        } else {
            printf("Unknown command: %s\n", command);
        }
    }
    return NULL;
}


int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    
    // Create a new socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Define the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        printf("\nWaiting for a connection...\n");

        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        char buffer[1000*BUFFER_SIZE] = "<!DOCTYPE html>\n<h1>HallgrimuerEggertsson.COM er í vinnslu</h1>";
        write(new_socket , buffer , strlen(buffer));
        printf("Hello message sent to client\n");
        
        close(new_socket);
    }
    
    return 0;
}

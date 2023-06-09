git add .
sleep 0.2
git commit -m "$1"
sleep 0.2
git push -u origin master
sleep 0.5
expect "Username for 'https://github.com':"
send "lord-hellgrim"
sleep 0.5
expect "Username for 'https://github.com':"
send "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"
echo "uploaded to github, probably"


git add .
git commit -m "$1"
git push -u origin master
expect "Username for 'https://github.com':\r"
send -- "lord-hellgrim"
expect Password for "'https://lord-hellgrim@github.com':\r"
send -- "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"


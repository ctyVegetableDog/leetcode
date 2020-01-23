# Read from the file words.txt and output the word frequency list to stdout.
#it should be worked, but it says rbash: ./prog.sh: Permission denied

chmod 777 words.txt
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk -F " " '{print $2 " " $1}'

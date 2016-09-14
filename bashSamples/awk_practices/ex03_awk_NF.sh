
echo 1 2 3 4 5 | awk '{ print "Number of fields (NF\= ", NF }'
echo "1 2\n 3 4\n5" | awk '{ print "Number of records (NR) = ", NR }'

# run by: awk -f <filename>
BEGIN {
    sum=0
    for (i=1 ; i < 10; i++) {
        sum += i
        print sum, "+=", i
    }
}

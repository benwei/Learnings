# run by: awk -f <filename>
BEGIN {
    var1="555"
    price_base = 1.1
    sum = price_base * var1
    print var1," x ", price_base," = ", sum
}

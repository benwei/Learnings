
src_file="$1"
match="$2"
list_line=5

# argument parsing with conditions
if [ -n "$3" ]; then
    list_line=$((0 + $3))
    if [ ! $list_line -gt 0 ]; then
        echo "list line should be great than 0"
        exit 1
    fi
fi

if [ ! -f "$src_file" -o ! -n "$match" ] ; then
    echo "`basename ${0}`: <target file> <match word> [list line]"
    exit 1
fi

# main
cat $src_file | awk "
  /$match/ { lines = $list_line }
  { if (lines > 0) { print; --lines; } }
 "
exit $? 

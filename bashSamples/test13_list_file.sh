
if [ ! -n "$1" ] ; then
    echo "list file extension name with .git in target path\nsyntax: <target path>"
    exit 1
fi
ls $1 | grep "\.git$" | while read dirname ; do echo $dirname ; done

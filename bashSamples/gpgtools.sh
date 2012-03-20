#!/bin/sh

cmd="$1"
src="$2"
dst="$3"

syntax()
{
	echo "syntax: <-e|-d> <src> <dst>"
}

encode_file()
{
# encrypt data with gpg extension name
gpg --output "$dst" --sign "$src"
return $?
}

decode_file()
{
# decrypt data and output to test.txt
gpg --output "$dst" --decrypt "$src"
return $?
}

# main
if [ "x$cmd" = "x" -o "x$src" = "x" -o "x$dst" = "x" ]; then
	syntax
	exit 1;
fi
ret=0
case $cmd in
-e*)
encode_file
ret=$?
;;
-d*)
decode_file
ret=$?
;;
*)
syntax
;;
esac
exit $ret

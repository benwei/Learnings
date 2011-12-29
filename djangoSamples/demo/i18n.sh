#!/bin/sh

ACTION="$1"
TARGET="$2"

usage() {
	echo "syntax: <initial <path>|update|compile>"
}

case $ACTION in
initial)
	django-admin.py makemessages -l zh_TW "$TARGET"
	ret=$?
;;
u*|update)
	django-admin.py makemessages -a 
	ret=$?
;;
c*|compile)
	django-admin.py compilemessages 
	ret=$?
;;
*)
	usage
	ret=1
;;
esac
exit $ret

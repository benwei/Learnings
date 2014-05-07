#!/bin/sh
verbose=0

opt="$1"

if [ "$opt" = "-v" ] ; then
	verbose=1;
fi

find . | while read fn ; do
if [ ! -d "$fn" ] ; then
	case $fn in
	*.js|*.sh)
	line=`cat $fn | wc -l | sed -e 's/[ ]*//g'` ;
	fn=`echo $fn | sed -e 's/^[./]*//g'`
	echo "$fn: $line" ;
	;;
	*)
	if [ "$verbose" -gt 0 ]; then
	echo "skip file $fn"
	fi
	;;
	esac
fi ;
done

#!/bin/sh
find . | while read fn ; do
if [ ! -d "$fn" ] ; then
	 case $fn in
	 *.js|*.sh)
	 line=`cat $fn | wc -l | sed -e 's/[ ]*//g'` ;
	 fn=`echo $fn | sed -e 's/^[./]*//g'`
	 echo "$fn: $line" ;
	 ;;
	 esac
fi ;
done

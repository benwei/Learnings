#!/bin/sh
find . | while read fn ; do
if [ ! -d "$fn" ] ; then
	 line=`cat $fn | wc -l | sed -e 's/[ ]*//g'` ;
	 fn=`echo $fn | sed -e 's/^[./]*//g'`
	 case $fn in
	 *.js|*.sh)
	 echo "$fn: $line" ;
	 ;;
	 esac
fi ;
done

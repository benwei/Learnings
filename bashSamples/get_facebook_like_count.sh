#!/bin/sh
# this is a snippet of hackerspace
source_url="https://www.facebook.com/TaipeiHackerspace"
url="http://api.facebook.com/restserver.php?method=links.getStats&urls=$source_url"
# TBM: count be optimaized cut with sed command
wget -O - $url 2>/dev/null | grep total | cut -d">" -f2 | cut -d"<" -f1
exit $?

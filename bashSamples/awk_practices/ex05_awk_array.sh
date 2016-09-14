bn=`basename $0`
cat ${bn%%.sh}.txt | awk -f ${bn%%.sh}.awk

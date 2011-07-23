#!/bin/bash

reponame="$1"
if [ "x$reponame" = "x" ]; then
	echo "missing reponame in argument 1. example: $0 demo.git"
	exit
fi

if [ -d "$reponame" ]; then
	echo "$reponame was existed. Skip to create."
	exit
fi

echo "creating $reponame ..."
mkdir -p $reponame
cd $reponame/
git init --bare
cd ..
sudo chown -R git:git $reponame
echo "done $reponame list..."
ls -rD $reponame

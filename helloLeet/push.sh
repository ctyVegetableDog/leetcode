#!/bin/sh

git add .
git commit -m "$1"
git checkout master
git merge dev -m "merge"
git push origin master
git checkout dev

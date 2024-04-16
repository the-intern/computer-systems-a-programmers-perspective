#!/bin/bash

ssh -T git@theintern

git add -A
git commit -m "$*"
git push 


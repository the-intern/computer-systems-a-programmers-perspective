#!/bin/bash

clear
ls
gcc -c main.c -o main.o
gcc -c byte_rep.c -o byte_rep.o
gcc main.o byte_rep.o -o program
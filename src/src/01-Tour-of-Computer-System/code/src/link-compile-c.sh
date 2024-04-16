#!/bin/bash

gcc -c main.c -o main.o
gcc -c message.c -o message.o
gcc -c krfahren.c -o krfahren.o
gcc main.o message.o krfahren.o -o program
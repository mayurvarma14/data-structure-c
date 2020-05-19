#!/bin/bash
mkdir $1
cd $1
touch main.c $1.c $1.h Makefile
printf "all: main.c $1.c $1.h\n" >>Makefile
printf "\tgcc main.c -o $1" >>Makefile
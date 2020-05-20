#!/bin/bash
case "$1" in
  create)
    mkdir $2
    cd $2
    touch main.c $2.c $2.h Makefile
    printf "all: main.c $2.c $2.h\n" >>Makefile
    printf "\tgcc main.c -o $2" >>Makefile
    ;;
  memory)
    valgrind --leak-check=full ./$2
    ;;

  *)
    printf "Usage: $0 {create|memory}\n"
    printf "\t create\t <project name>\t\tCreates new project\n"
    printf "\t memory\t <program path>\t\tChecks for memory leak\n"
    ;;
esac
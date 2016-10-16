#!/bin/bash
gcc -c StackImplementation.c
gcc -c StackDriver.c
gcc -o StackDriver StackImplementation.o  StackDriver.o
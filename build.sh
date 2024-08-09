#!/bin/bash

CC=clang
SRC=main.c
OUT=main

$CC $SRC -o $OUT -std=c2x
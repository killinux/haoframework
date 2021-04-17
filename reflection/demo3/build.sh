#!/bin/sh
#https://blog.csdn.net/guotianqing/article/details/79777273

#gcc -shared -fPIC -o libtest.so test.c
gcc -g -shared -fPIC -o libmodule.so module.c
gcc -g test.c -lmodule -L. -o test

gcc -g dongtai.c -ldl -o dongtai

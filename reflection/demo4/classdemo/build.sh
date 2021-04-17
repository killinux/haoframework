#!/bin/sh
#https://blog.csdn.net/lwj1396/article/details/5204484
g++ -g -shared -fPIC -o libtriangle.so triangle.cpp
g++ -std=c++11 -g main.cpp -ldl -o main

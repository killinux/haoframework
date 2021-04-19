#!/bin/sh
g++ -g -shared -fPIC -o libhello.so hello.cpp
g++ -std=c++11 -g main.cpp -ldl -o main

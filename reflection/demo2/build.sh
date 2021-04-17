#!/bin/sh
#g++ -g -std=c++11  reflection.cpp  main.cpp -I. -L. -o main

# the base of reflec
g++ -std=c++11 -fPIC -shared -o libreflection.so reflection.cpp -I. 


#in linux
g++ -std=c++11 -fPIC -shared -o libclassa.so TestClassA.cpp -I.
g++ -std=c++11 -fPIC -shared -o libclassb.so TestClassB.cpp -I.
g++ -std=c++11 -fPIC -shared -o libclassc.so TestClassC.cpp -I.

# the interface, This will change frequently
#g++ -std=c++11 -fPIC -shared -o libpre_interface.so PreInterface.cpp  -I. -Wl,--copy-dt-needed-entries -lclassa -lclassb -L.
#g++ -std=c++11 -fPIC -shared  PreInterface.cpp -lclassa -lclassb -L. -I. -Wl,-rpath=./ -o libpre_interface.so
g++ -std=c++11 -fPIC -shared  PreInterface.cpp -lclassa -lclassb -L. -I. -o libpre_interface.so
#g++ -std=c++11 -fPIC -shared  PreInterface.cpp -lclassa -lclassb -lclassc -L. -I. -o libpre_interface.so

#in mac:
#g++ -std=c++11 -fPIC -shared -o libclassa.so TestClassA.cpp -I. -L. -lreflection
#g++ -std=c++11 -fPIC -shared -o libclassb.so TestClassB.cpp -I. -L. -lreflection

# the main
#g++ -g -std=c++11   main.cpp -I. -L. -lclassa -lclassb -lreflection -o main
#g++ -g -std=c++11   main.cpp -I. -L. -lpre_interface -lclassa -lclassb -lreflection -o main
g++ -g -std=c++11 -Wl,--copy-dt-needed-entries  main.cpp -I. -L.  -lreflection -lpre_interface  -o main
#注意：这个有顺序问题,-Wl,--copy-dt-needed-entries 要写在前面

#ifndef __TestClass__
#define __TestClass__

#include <map>
#include <iostream>
#include <string>
using namespace std;

// test class
class TestClass {
public:
    virtual void m_print() = 0; 
//    void m_print() {
//        cout<<"hello TestClass"<<endl;
//    };
};
//REGISTER(TestClass);

#endif

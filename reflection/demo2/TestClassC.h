#ifndef __TestClassA__
#define __TestClassA__
#include <TestClass.h>
#include <reflection.h>
#include <iostream>
using namespace std;
class TestClassC : public TestClass 
{
public:
    void m_print(); 
};

REGISTER(TestClassC);

#endif

#ifndef __TestClassA__
#define __TestClassA__
#include <TestClass.h>
#include <reflection.h>
#include <iostream>
using namespace std;
class TestClassA : public TestClass 
{
public:
    void m_print(); 
//    void m_print() {
//        cout<<"hello TestClassA"<<endl;
//    };
};

// brief 创建类实例的回调函数
//TestClassA* createObjTestClassA {
//        return new TestClassA;
//}

REGISTER(TestClassA);

#endif

#ifndef __TestClassB__
#define __TestClassB__
#include <TestClass.h>
#include <reflection.h>
#include <iostream>
//TestClassB {
using namespace std;
class TestClassB : public TestClass{

public:
    void m_print(); 
//    void m_print() {
//        cout<<"hello TestClassB"<<endl;
//    };
};

//// brief: 创建类实例的回调函数
//TestClassB* createObjTestClassB() {
//        return new TestClassB;
//}
//
//// 注册动作类的全局实例
//RegisterAction g_creatorRegisterTestClassB("TestClassB",(PTRCreateObject)createObjTestClassB);

REGISTER(TestClassB);
#endif

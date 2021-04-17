#include <map>
#include <iostream>
#include <string>
#include <reflection.h>
#include <TestClass.h>
#include <main.h>
#include <stdio.h>
using namespace std;

//// test class
//class TestClass {
//public:
//    void m_print() {
//        cout<<"hello TestClass"<<endl;
//    };
//};
//REGISTER(TestClass);

int main(int argc,char* argv[]) {
    cout << "argv 1: "<<  argv[1] << endl;
    //TestClass* ptrObj=(TestClass*)ClassFactory::getInstance().getClassByName("TestClassA");
    TestClass* ptrObj=(TestClass*)ClassFactory::getInstance().getClassByName(argv[1]);
    if( NULL == ptrObj){
        printf("hao: error --> can not find the class : %s \n please check the config \n" , argv[1]);
    }else{
        ptrObj->m_print();
    }
}

// 工厂类的定义
#include <map>
#include <iostream>
#include <string>
using namespace std;
typedef void* (*PTRCreateObject)(void);
class ClassFactory {
private:  
    map<string, PTRCreateObject> m_classMap ;  
    ClassFactory(){}; //构造函数私有化
    
public:   
    void* getClassByName(string className);  
    void registClass(string name, PTRCreateObject method) ;  
    static ClassFactory& getInstance() ;  
};

// 工厂类的实现

// brief: 获取工厂类的单个实例对象  
ClassFactory& ClassFactory::getInstance(){
    static ClassFactory sLo_factory;  
    return sLo_factory ;  
}

// brief: 通过类名称字符串获取类的实例
void* ClassFactory::getClassByName(string className){
    map<string, PTRCreateObject>::const_iterator iter;  
    iter = m_classMap.find(className) ;  
    if ( iter == m_classMap.end() )  
        return NULL ;  
    else  
        return iter->second() ;  
}  

// brief: 将给定的类名称字符串和对应的创建类对象的函数保存到map中
void ClassFactory::registClass(string name, PTRCreateObject method){
    m_classMap.insert(pair<string, PTRCreateObject>(name, method)) ;  
}
class RegisterAction {
public:
    RegisterAction(string className,PTRCreateObject ptrCreateFn) {
        ClassFactory::getInstance().registClass(className, ptrCreateFn);
    }
};
#define REGISTER(className)                                             \
    className* objectCreator##className(){                              \
        return new className;                                           \
    }                                                                   \
    RegisterAction g_creatorRegister##className(                        \
        #className,(PTRCreateObject)objectCreator##className)


// test class
class TestClass {
public:
    void m_print() {
        cout<<"hello TestClass"<<endl;
    };
};
REGISTER(TestClass);

int main(int argc,char* argv[]) {
    TestClass* ptrObj=(TestClass*)ClassFactory::getInstance().getClassByName("TestClass");
    ptrObj->m_print();
}

#include <iostream>
using namespace std;
void printA(int a)
{
     cout << a << endl;          
}
 
int main(){
	std::function<void(int a)> func;
	func = printA;
	func(2);
}

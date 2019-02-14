#include<iostream>
using namespace std;

class Parent{
public:
	Parent(){
		printf("call Parent()\n");
	}
	Parent(const Parent& p) = delete;
public:
	void Test_call(){
		printf("Test_call\n");
	}
};

struct Son: private Parent{
public:
	int a;
	Son(){
		printf("call Son()\n");	
	}
	Son(const Son& s): Parent(s), a(s.a){
	}
};

// class SonS: protected Son{
// public:
// 	SonS(){
// 		printf("call SonS()\n");	
// 		Test_call();
// 	}
// };


int main(int argc, char* argv[]){
	Son s;
	Son s2 (s);
	return 0;
}

#include <iostream>
#include <string>
using namespace std;
    
class A{
    int age;
    string name;
    
public:
    A(int a, string n): age(a), name(n)
    {
        printf("initializer with age:%d, name:%s \n", a, n.c_str());
    }
};    

int main(int argc, const char* argv[]){
    A* a1 = new A(28, "ridehuang");    
    delete a1;
    char* p = (char*)malloc(sizeof(A));
    A* a2 = new (p) A(28, "qiqi");
    free(p);
    return 0;
}

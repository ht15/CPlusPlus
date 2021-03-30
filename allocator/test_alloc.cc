#include <iostream>

int main(int argc, const char* argv[]){
    unsigned int sz = 10;
    int* p = new int(10);
    std::cout << *p << std::endl;
    delete p;
    return 0;
}

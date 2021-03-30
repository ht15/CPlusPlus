#include <iostream>

namespace ht {
namespace { // 匿名名字空间功能上相当于static
    int i = 2;
}
void Test(){
    std::cout << i << std::endl;
}
}

//namespace {
//    int j = 0; // 产生二义性，应和外部的名字不冲突J
//}
int j;

int main(){
    using ht::Test;
    Test();
    return 0;
}

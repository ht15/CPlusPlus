#include <iostream>
/*
引用不是对象所以不存在const引用，只存在指向const的引用；
但是，存在const指针(顶层const)，也存在指向const的指针(底层const)
*/
using namespace std;

int main(int argc, char* argv[]) {
    const int a = 1;
    const int &ref_a = a;

    int b = 2;
    const int &ref_b = b; // 从汇编来看，这边是对地址赋值，所以ref_b能够随b的值改变而改变

    b = 3;

    int c = ref_b; // 从汇编来看，这边是值拷贝
    // ref_b = 4; 编译器检查禁止了常量引用的赋值, 直接改汇编代码还是可以通过ref_b修改值的

    b = 4;

    cout << c << endl;
    cout << ref_b << endl;

    const int *d = &b;
    cout << *d << endl;
    return 0;
}

#include <iostream>
#include <memory>

class Test{
};

void clear_test(Test* t){
    std::cout << t << std::endl;
}

int main(int argc, const char* agrv[]){
    Test t;
    std::cout << &t << std::endl;
    std::shared_ptr<Test> sp(&t, clear_test); // shared_ptr默认使用delete清除绑定的指针，可以指定特殊的删除器来让智能指针指向栈内存。
    std::cout << sp.get() << std::endl;
    return 0;
}

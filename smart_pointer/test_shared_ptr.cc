#include <iostream>
#include <memory>

class Test{
public:
    int a;
};

void clear_test(Test* t){
    std::cout << "destroy: " << t << std::endl;
}

void TestGet(Test &t){
    Test _t;
    _t.a = 1000;
    std::cout << "inner: " << &_t << std::endl;
    std::shared_ptr<Test> sp(&_t, clear_test); // shared_ptr默认使用delete清除绑定的指针，可以指定特殊的删除器来让智能指针指向栈内存。
    std::cout << sp.use_count() << std::endl;
    std::cout << "inner,get: " << sp.get() << std::endl;
    t = *sp.get();
    std::cout << sp.use_count() << std::endl;
}

int main(int argc, const char* agrv[]){
    Test t;
    t.a = 10;
    TestGet(t);
    std::cout << "outside: " << t.a << std::endl;
    return 0;
}

#include <iostream>

class Base{
public:
    virtual void Name(){
        std::cout << "base" << std::endl;
    }
};


class Derive: public Base {
public:
    void Name(){
        std::cout << "derive" << std::endl;
    }
};

int main(int argc, const char* argv[]){
    Derive di;
    Base *b = &di;
    Derive* d = static_cast<Derive*>(b);
    d->Name();
    auto d1 = dynamic_cast<Derive*>(b); // dynamic_cast的类必须是多态的
    d1->Name();
    return 0;
}

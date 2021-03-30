#include <iostream>
#include <memory>
#include <string>

class Car{
public:
    std::string name;

    Car(std::string n);
};

Car::Car(std::string n){
    name = n;
}

template <typename T>
void print_type(T &&t){
    std::cout<<typeid(t).name()<<std::endl;
}

int main(int argc, const char* argv[]){
    std::unique_ptr<Car> c_p(new Car("baoma")); // unique_ptr没有make_shared<>
    auto func = std::bind([](const decltype(c_p)& c){std::cout << c->name << std::endl;}, std::move(c_p)); // 使用bind来使lambda表达式用move语义
    std::cout << typeid(func).name() << std::endl; 
    func();
    return 0;
}

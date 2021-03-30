#include <iostream>
#include <string> //随便不包含string头文件也能正常编译，但那是因为iostream头文件中间接引用了string，所以正确做法是加上string头文件。另外g++ -H选项可以列出某个文件引入了哪些头文件

class Student {

public:
    std::string name;
    int age;

    Student(std::string str, int a):name(str), age(a){
        std::cout << "address of agrs str: " << &str << std::endl;;
    }

    Student(const Student &s):name(s.name), age(s.age) {
    }
    
    Student(Student &&s) noexcept;

    void printf(){
        std::cout << name << std::endl << age << std::endl;
    }
};

Student::Student(Student &&s) noexcept // 如果不使用noexcept关键字，编译器可能不会使用move构造函数
    :name(std::move(s.name)), age(s.age) // 这里使用string的移动构造函数来给name赋值, move将会获得对象的一个右值引用，move意味着除了对它赋值或者销毁，我们将不再使用它
{
    std::cout << "use move constuct" << std::endl;
}

int main(int argc, const char* argv[]){
    std::string str = "huangtao";
    std::cout << "address of str: " << &str << std::endl;;
    Student s0(str, 28);
    std::cout << "address of s0.str: " << &s0.name << std::endl;;

    Student s1(std::move(s0));
    s1.printf();
    return 0;
}

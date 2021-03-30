#include <functional>
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "test_template.h"

int getOne() {
    return 1;
}

struct getTwo {
    getTwo() {}
    int operator()(int a) {
        return 2;
    }
};

//template<typename T>
std::ostringstream& getName(std::ostringstream& os) {
    return os;
}

template<typename T, typename... Args>
std::ostringstream& getName(std::ostringstream& os, T& t, const Args&... args){
    os << t;
    return getName(os, args...);
}
    

// 特例化之前一定要声明
template < typename T , typename... args>
class Function; //通过这边声明只有一个参数

template < class Ret, typename... Args0 >
class Function <Ret(Args0...)> { //偏特化，此处必须只有一个参数Ret(Args0)
// }

// template < class Ret, class Args0 >
// class Function {
    //构造虚基类以存储任意可调用对象的指针
    struct callable_base {
        virtual Ret operator()(Args0... a0) = 0;
        virtual struct callable_base *copy() const = 0;
        virtual ~callable_base(){};
    };
    struct callable_base *base;

    template < typename T >
    struct callable_derived : public callable_base {
        T f;
        callable_derived(T functor) : f(functor) {}
        Ret operator()(Args0... a0) {
            return f(a0...);
        }
        struct callable_base *copy() const {
            return new callable_derived< T >(f);
        }
    };

public:
    template < typename T >
    Function(T functor) : base(new callable_derived< T >(functor)) {std::cout << typeid(functor).name() << std::endl;}
    Function() : base(nullptr) {}
    // 实际调用存储的函数
    Ret operator()(Args0... arg0) {
        std::ostringstream os;
        std::cout << "type of args: " << std::endl;
        std::cout << typeid(Ret).name() << ":  "<< getName(os, arg0...).str() << std::endl;
        return (*base)(arg0...);
    }

    Function(const Function &f) {
        std::cout << "copy construct" << std::endl;
        base = f.base->copy();
    }
    Function &operator=(const Function &f) {
        std::cout << "assign construct" << std::endl;
        delete base;
        base = f.base->copy();
        return *this;
    }

    ~Function() {
        std::cout << "delete current base callable object" << std::endl;
        delete base;
    }
};

template<typename T1=std::string, typename T2=int>
class Book;
//extern template class Book<std::string, int>;


template <typename T>
class ReturnVal {
    T v;
public:
    T get_val(){
        return v;
    }
};

template <typename T>
T fun_get_ret_val(T i){
    return i;
}

int main() {
    // basic function
    Function< int() > getNumber(getOne);
    std::cout << getNumber() << std::endl;
    
    getTwo two = getTwo();
    class Function< int(int) > getNumber1(two);
    std::cout << getNumber1(3) << std::endl;

    Book<> book(std::string("C++ Primer"), 100); // <>不带类型参数，相当于使用偏特化
    book.Printf();

    ReturnVal<int> rv;
    std::cout << "test ReturnVal: " << rv.get_val() << std::endl;
    std::cout << "test fun get val: " << fun_get_ret_val(3) << std::endl;
    return 0;
}

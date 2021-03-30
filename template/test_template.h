#include <iostream>
template<typename T1, typename T2>
class Book{
    T1 name;
    T2 price;
public:
    Book(T1 n, T2 p);
    void Printf();
};

template<typename T1,typename T2>
Book<T1, T2>::Book(T1 n, T2 p){
    name = n;
    price = p;
}

template<typename T1,typename T2>
void Book<T1, T2>::Printf(){
    std::cout<<name<<std::endl;
    std::cout<<price<<std::endl;
}

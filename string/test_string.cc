#include <iostream>
#include <typeinfo>
#include <memory>
using namespace std;

namespace std{
namespace test0
{
template<typename T1, typename T2>
class MyT
{
};
}
}

namespace test1{
class TCBASE {

};

template<typename T1, typename T2, typename T3>
class TC: public TCBASE {
};
}

void print_split_line()
{
    cout << "===================" << endl;
}

void test_type_info(); // typeid的使用
void test_different_between_typeid_and_decltype();
void test_concat();
void test_iterator();

int main()
{
    test_type_info();
    test_different_between_typeid_and_decltype();
    test_concat();
    test_iterator();
    return 0;
}

void test_type_info()
{
    string a = "A";
    test1::TC<int, char, std::test0::MyT<double, bool> >tc;
    cout << typeid("A").name() << endl;
    cout << typeid("B").name() << endl;

    cout << typeid(a).name() << endl;

    cout << typeid(tc).name() << endl;

    cout << typeid(typeid(a).name()).name() << endl;

    cout << a.size() << endl; // 不会复制 "A"中的空字符 '\0'
    /*
    Result of MAC_PRO:
    A2_c    -> Array with length 2, and content is character. 可以看出字符字面值是Array
    A2_c    -> Array with length 2, and content is character
    NSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEE    -> 参考typeid(tc).name()的解析
    N5test12TCIicNSt5test03MyTIdbEEEE    -> \
        N(namespace)5(命名空间名字长度)test1(命名空间名字)2(类型长度)TC(类型名字)\
        I(后跟模板参数)i(int类型)c(character类型)NSt5test03MyTIdb(第三个template类型，此类型为 std中的test0命令空间中的MyT, MyT模板参数为double和bool)
    PKc     -> Ptr with const character 指向字符常量的指针
    */

}

class Base
{
public :
    virtual void print() { std::cout << "from base class\n"; }
};

class Derived : public Base
{
public :
    void print() override { std::cout << "from derived class \n"; }
};

void test_different_between_typeid_and_decltype()
{
    print_split_line();
    std::shared_ptr< Base > d = std::make_shared< Derived >();
    std::cout << typeid( *( d.get() ) ).name() << "\n";
    std::cout << typeid( decltype( *( d.get() ) ) ).name() << "\n";
}

void test_concat()
{
    print_split_line();
    string s1 = "hello";
    string s2 = " world\n";
    string s3;
    s3.reserve(100);
    s3.append(s1);
    s3.append(s2);
    cout << "after concat: " << s3 << endl;
}

void test_iterator()
{
    print_split_line();
    string s("hello world\n");
    for ( auto &c: s)
    {
        c = toupper(c);
    }

    cout << "after toupper: " << s << endl;

    for ( decltype(s.size()) index = 0; index != s.size(); index++)
    {
        cout << s[index] << "\t";
    }
    cout << endl;

    for ( auto it = s.begin(); it != s.end(); it++)
    {
        *it = tolower(*it);
    }
    cout << "after tolower: " << s << endl;
}
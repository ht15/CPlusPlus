#include <iostream>
int main(){
    int a = 1;
    int b = 2;
    int *p_a = &a;
    std::cout << p_a << std::endl;
    p_a = &b;
    std::cout << p_a << std::endl;
    return 0;
}
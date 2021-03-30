#include <iostream>
using namespace std;

namespace ht {
    int i = 0;
    int j = 1;
    
    class Input {
    public:
        int v;
        Input(int i){
            v = i;
        }
    };

    void display(Input i) {
        cout << "in display" << i.v << endl;
    }
}
int j = 0; // 和ht::j具有二义性

void test(){
    using namespace ht; //在该函数作用域内有效
    i++;
}

int main(int argc, char* argv[]){
    //using namespace ht; 具有二义性
    test();
    cout << ht::i << endl;
    cout << j << endl;

    ht::Input input(2);
    display(input); // 实参为类类型时，函数查找范围包括类类型所在的名字空间
    return 0;
}

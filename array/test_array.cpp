#include <iostream>
#include <vector>

int main(int argc, const char* argv[]){
    constexpr int row = 3, col = 3; // 声明为常量表达式
    int array[row][col];
    int cnt = 0;
    for(auto &r: array) // 一定要使用引用类型，要不然r的类型就是int(*)[col]，对指针遍历就会出错
        for(auto &c: r){
            cnt++;
            c = cnt;
        }
    
    for (auto p=array; p != array+row;p++){ // p的类型为int(*)[col]
        for(auto q=(*p); q != (*p)+col; q++){ // q的类型为int*
            std::cout<< *q << std::endl;
        }
    }

    std::vector<int> vec(*array, *array + col);
    for(auto i=vec.begin();i!=vec.end();i++){ // c++程序应该尽量使用不等于，因为不等于是每个容器类型都实现了的操作符
        std::cout << *i << std::endl;
    }
    return 0;
}

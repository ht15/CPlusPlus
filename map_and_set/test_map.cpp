#include <iostream>
#include <map>

int main(int argc, const char* argv[]) {
    std::map<int, int> t;
    t.insert({7,7});
    std::cout << t.begin()->second << std::endl;
    t.insert({7,77}); // 不能更新值
    std::cout << (*(t.begin())).second << std::endl; // .的优先级更高，所以要使用括号
    return 0;
}

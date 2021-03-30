#include <stdio.h>

class Actress {
public:
    Actress(int h, int w, int a):height(h),weight(w),age(a){};

    virtual void desc() {
        printf("height:%d weight:%d age:%d\n", height, weight, age);
    }

    virtual void name() {
        printf("I'm a actress\n");
    }

    int height; // 身高
    int weight; // 体重
    int age;    // 年龄（注意，这不是数据库，不必一定存储生日）
};

int main(){
    Actress a = Actress(1,1,1);
    a.name();
    return 0;
}

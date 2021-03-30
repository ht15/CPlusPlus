#include <stdio.h>

int* call_loop(int i, int a, int b, int c, int d, int e, int f, int g, int h) {
    int j;
    int a1=a;
    int a2=b;
    int a3=c;
    int a4=d;
    int a5=e;
    int a6=f;
    int a7=g;
    int a8=h;
    for(j=0; j<i; j++) {
        printf("this is num:%d\n", j);
    }
    return &j;
}

int main(){
    int i = 10;
    int a, b, c, d, e, f, g, h;
    int *j;
    j = call_loop(i, a, b, c, d ,e, f, g, h);
    printf("before, j add: %p\n", j);
    j += 12;
    printf("after, j add: %p\n", j); 
    printf("i add: %p\n", &i);
    *j = 24;
    printf("after detect i is %d\n", i);
    return 0;
}

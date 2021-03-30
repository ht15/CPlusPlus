#include <stdio.h>

int* call_loop(int i) {
    int j;
    int a = i;
    int b = i;
    for(j=0; j<i; j++) {
        printf("this is num:%d\n", j);
    }
    return &j;
}

int main(){
    int i = 10;
    int *j;
    j = call_loop(i);
    printf("before, j add: %p\n", j);
    j += 12;
    printf("after, j add: %p\n", j); 
    printf("i add: %p\n", &i);
    *j = 24;
    printf("after detect i is %d\n", i);
    return 0;
}

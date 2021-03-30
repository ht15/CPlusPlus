#[g++的各个编译选项](http://noahsnail.com/2019/05/14/2019-05-14-C++%E6%BA%90%E6%96%87%E4%BB%B6%E5%88%B0%E5%8F%AF%E6%89%A7%E8%A1%8C%E7%A8%8B%E5%BA%8F/)
- 预处理-E

如```g++ -E main.c -o main.ii```

- 编译-S

如```g++ -S main.ii -o main.s``` 

- 汇编-c 

如```g++ -c main.s -o main.o```

- 链接

如```g++ main.o -o main```


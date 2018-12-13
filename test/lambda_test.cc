#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int x = 100;
	auto fun = [&](const int &x){
		printf("%d\n", x);
	};
	fun(x);
	return 0;
}
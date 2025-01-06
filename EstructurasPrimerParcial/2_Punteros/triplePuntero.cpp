#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main(){
	int a,b,c,*pa,*pb,*pt;
	a=3;
	pa=&a;
	cout<<*pa<<endl;
	b=4;
	pb=&b;
	cout<<*pb<<endl;
	pt=&c;
	*pt=-5;
	cout<<*pt<<endl;
	c=5 * *pa;
	cout<<*pt<<endl;
	cout<<c<<endl;
}

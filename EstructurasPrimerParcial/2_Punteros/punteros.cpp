#include <iostream>
#include <string>

using namespace std;

int main(){
	int *punt;
	int x;
	int y;
	punt = &x;
	*punt = 4;
	punt = &y;
	*punt = 8;
	printf("%d,%d",x,y);
	cout<<endl<<*punt;
}

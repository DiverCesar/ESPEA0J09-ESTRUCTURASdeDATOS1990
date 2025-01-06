#include <iostream>

using namespace std;

int main(){
	int x, tabla[100];
	for (x=100;x>0;x--){
		tabla[x] = x;
	}
	for (x=100;x>0;x--){
		cout<<tabla[x]<<endl;
	}
}

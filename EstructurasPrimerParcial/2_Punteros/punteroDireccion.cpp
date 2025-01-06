#include <iostream>

using namespace std;
int main(){
	int *pNum = NULL;
	
	pNum = new int;
	*pNum = 34;
	cout <<"Direccion: "<<pNum<<endl;
	cout<<"valor "<<*pNum<<endl;
	delete pNum;

}

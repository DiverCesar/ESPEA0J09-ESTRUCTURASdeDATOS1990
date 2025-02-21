#include <vector>
#include <cstdlib>
#include <ctime>
#include<iostream>

using namespace std;

int main(){
	const int SIZE=10;
	vector<int> numbers(SIZE);
	srand(time(NULL));
	
	for(int &num:numbers){
		num=rand()%100+1;
	}
	cout<<"Elementos del vector: "<<endl;
	for(const int &num:numbers){
		cout<<num<<" ";
	}
	
}

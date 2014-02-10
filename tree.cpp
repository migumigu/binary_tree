#include<iostream>
#include<fstream>
#include"binary_tree.h"

using namespace std;

int main()
{
	int aa,bb;
	ifstream inData;
    inData.open("data100");

	Binary_tree<int> L;
    while(inData){
	inData>>aa;
		L.insert(aa);
	}
//	Binary_node<int> * k;
//	k = L.xungen();
    cout<<"the hight of the tree is "<<L.height()<<endl;
	cout<<"the size of the tree is "<<L.size()<<endl;
	L.print();
//	L.clear();
	cout<<endl;
    cout<<L.height()<<endl; 
	return 0;
}
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int b,c,d=0,e=0;
	for(int i=9;i>=1;i/=2){
		b = i%2;
		c = b*pow(10,d);
		e += c;
		d++;
		cout<< e <<endl;
	}
	cout << e;
} 

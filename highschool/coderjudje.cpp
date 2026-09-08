#include<iostream>
using namespace std;
int rand(long long a,long long b)
{
	if(a==1)
		return b+1;
	else if(a%2==0)
		return rand(a/2,b+a);
	else 
		return rand(a*3+1,b+a);
}
int main()
{
	long long x1=0,n;
	cin >> n;
	cout << rand(n,x1) << endl;
	return 0;
}
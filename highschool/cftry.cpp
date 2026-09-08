#include<iostream>
using namespace std;
int add(int x,int y)
{
	if(y<10)
		return x+y;
	else
		return add(x+y%10,y/10);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	string str;
	int n,tmp;
	cin >> n;
	while(n--)
	{
		cin >> str;
		cin >> tmp;
		if(!(add(0,tmp)%2))
			cout << str << endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d=1;
	cin >> a >> b >> c;
	if((a&&b)==1)
	{
		if(c)
		{
			cout << "AND" << endl;
			d=0;
		}
	
	}
	else if(!c)
	{
		cout << "AND" << endl;	
		d=0;
	}
		
	if((a||b)==1)
	{
		if(c)
		{
			cout << "OR" << endl;
			d=0;
		}
	}
	else if(!c)
	{
		cout << "OR" << endl;
		d=0;
	}
		
	if((a&&b)!=(a||b))
	{
		if(c)
		{
			cout << "XOR" << endl;
			d=0;
		}
		
	}
	else if(!c)
	{
		cout << "XOR" << endl;
		d=0;
	}
	if(d)
		cout << "IMPOSSIBLE" <<endl;
	
}
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second

float mk_delta(int a1,int a2,int b1,int b2)
{
	return a1*b2-a2*b1;
}

int main()
{
	float delta,delta_x,delta_y;
	pair<int,int> a,b,c;
	cout << "input function1" << endl;
	cin >> a.F >> b.F >> c.F;
	cout << "input b1 function2" << endl;
	cin >> a.S >> b.S >> c.S;
	
	delta = mk_delta(a.F,a.S,b.F,b.S);
	delta_x = mk_delta(c.F,c.S,b.F,b.S);
	delta_y = mk_delta(a.F,a.S,c.F,c.S);
	
	cout << "X=" << delta_x/delta << "\nY=" << delta_y/delta << endl; 
}

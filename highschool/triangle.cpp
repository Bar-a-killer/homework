#include<bits/stdc++.h>
using namespace std;
#define f first 
#define s second

float mk_delta(int a1,int a2,int b1,int b2)
{
	return a1*b2-a2*b1;
}

int main()
{
	pair<int,int> a,b,c,vector_i,vector_j;
	cout << "input fist pos" << endl;
	cin >> a.f >> a.s;
	cout << "input second pos" << endl;
	cin >> b.f >> b.s;
	cout << "input third pos" << endl;
	cin >> c.f >> c.s;
	
	vector_i.f = a.f-b.f;
	vector_i.s = a.s-b.s;
	vector_j.f = a.f-c.f;
	vector_j.s = a.s-c.s;
	
	cout << "the ans:" << mk_delta(vector_i.f,vector_i.s,vector_j.f,vector_j.s)/2 << endl;
	
}

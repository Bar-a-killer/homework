#include<bits/stdc++.h>
using namespace std;
vector<string> vim;
int N,Q;
void out()
{
	for(int j=0;j<N;j++)
	{
		cout << vim[j] << endl;
	}
}
void read()
{
	string tmp;
	for(int j=0;j<N;j++)
	{	
		getline(cin,tmp);
		vim.push_back(tmp);
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	
	
	cin >> N >> Q;
	
	string reset;
	string movement;
	int i,l,r,p;
	string tmp;
	cin.ignore();
	read();
	for(int j=0;j<Q;j++)
	{
		cin >> movement;
		if(movement == "cut")
		{
			tmp.clear();
			cin >> i >> l >> r;
			tmp = tmp.assign(vim[i],l,r-l+1);
			reset = reset.assign(vim[i],0,l);
			reset = reset.append(vim[i],r+1,vim[i].length()-r);
			vim[i] = reset;
		}
		else if(movement == "paste")
		{
			cin >> i >> p;
			vim[i].insert(p,tmp);
		}
	}
	out();
}
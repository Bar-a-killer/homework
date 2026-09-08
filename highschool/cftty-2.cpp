#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	set<string> vec;
	int n,j;
	cin >> n;
	string tmp;
	while(n--)
	{
		cin >> tmp;
		if(!vec.count(tmp))
		{
			vec.insert(tmp);
			cout << "OK" << endl;
		}
		else
		{
			j=1;
			tmp+=to_string(j);
			while(vec.count(tmp))
			{
				tmp.pop_back();
				tmp+=to_string(++j);
			}
			vec.insert(tmp);
			cout << tmp << endl;
		}	
	}
}
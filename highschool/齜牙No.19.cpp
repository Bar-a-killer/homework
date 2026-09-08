#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
	stack<int> inside;
	int next,que;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		next = 1;
		cin >> n;
		for(int j=0;j<n;j++)
		{
			cin >> que;
			while(next <= n+1)
			{
				//cout << 'a' << endl;
				if(!inside.empty() && inside.top() == que)
				{
					inside.pop();
					break;
				}
				else
				{
					inside.push(next);
					next++;
				}
			}
		}
		if(inside.size()!= 0)
		{
			cout << "No" << endl;
			while (!inside.empty()) {
				//cout << inside.top(); 
				inside.pop();
			}
				
		}
		else
			cout << "Yes" << endl;
	}
}
			
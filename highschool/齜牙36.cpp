#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,mod,input;
	stack<int> stack;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> mod;
		if(mod-1 == 0)
		{
			cin >> input;
			stack.push(input);
		}
		else
		{
			if(stack.size()!=0)
			{
				cout << stack.top() << endl;
				stack.pop();
			}
			else
				cout << "empty!" << endl;
		}
	}
}
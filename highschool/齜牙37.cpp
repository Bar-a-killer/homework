#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	queue<int> queue;
	int num,mod;
	while(n--)
	{
		cin >> mod;
		if(mod==1)
		{
			cin >> num;
			queue.push(num);
		}
		else
		{
			if(!queue.size())
			{
				cout << "empty!" << endl;
				continue;
			}
			cout << queue.front() << endl;
			queue.pop();
		}
	}
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n,det=1;
	long long mt;
	cin >> n;
	stack<int> dark;
	while(n--)
	{
		cin >> mt;
		if(mt > 0)
		{
			dark.push(mt);
		}
		else if(mt < 0)
		{
			if(dark.size() == 0)
			{
				cout << "lose light light" << endl;
				dark.push(mt);
				det = 0;
				break;
			}
			else if(dark.top() != -mt)
			{
				cout << "lose light light" << endl;
				dark.push(mt);
				det = 0;
				break;
			}
			else
				dark.pop();
		}
	}
	if(dark.size() == 0)
	{
		cout << "weed" << endl;
	}
	else if(det)
	{
		cout << "lose light light" << endl;
	}


}
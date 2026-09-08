#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	int birdpos[n];
	int head = n-1;
	for(int i=1;i<n;i++){
		birdpos[i] = i-1;
	}
	birdpos[0] = -1;
	int m;
	int mod,pos;
	int next,nnext;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> mod >> pos;
		pos--;
		if(mod == 0)
		{
			if(pos == head)
				head = birdpos[pos];
			for(int j=0;j<n;j++)
			{
				if(birdpos[j]==pos)
				{
					if(birdpos[pos] == -1)
					{
						birdpos[j] = -1;
						break;	
					}
					birdpos[j] = birdpos[pos];
					cout << "aa: " << birdpos[6] << endl;
					break;
				}	
			}
		}
		else if(mod == 1 && birdpos[pos] != -1)
		{
			for(int j=0;j<n;j++)
			{
				if(pos == head)
					head = birdpos[pos];
				if(birdpos[j]==pos)
				{
					next = birdpos[pos];
					nnext = birdpos[next];
					birdpos[j] = next;
					birdpos[pos] = nnext;
					birdpos[next] = pos;
					break;
				}
			}
		}
	}
	stack<int> tmp;
	for(int i=0;i<n-1;i++)
	{
		tmp.push(head);
		head = birdpos[head];
	}
	for(int i=0;i<n-1;i++)
	{
		cout << tmp.top()+1 << endl;
		tmp.pop();
	}

}
#include<bits/stdc++.h>
using namespace std;
vector<queue<int>> llist;
int hadout=0;
void output(queue<int> que)
{
	while(que.size() != 0 && que.front() != 0)
	{
		//cout << ":" << que.front() << ":";
		if(que.front() > 0)
		{
			cout << " " << que.front();
			hadout = 1;
			que.pop();
		}
		else
		{
			output(llist[-que.front()]);
			que.pop();
		}
			
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	string move;
	int L,M,last=0;
	cin >> m >> n;
	queue<int> tmp;
	m++;
	for(int i=0;i<m;i++)
		llist.push_back(tmp);
	while(n--)
	{
		cin >> move;
		cin >> L;
		switch(move[0])
		{
			case 'A':
				cin  >> M;
				llist[L].push(M);
				break;
			case 'L':
				if(llist[L].size() == 0)
					cout << "queue " << L << " is empty!" << endl;
				else
					llist[L].pop();
				break;
			case 'J':
				cin >> M;
				llist.push_back(llist[L]);
				llist.back().push(0);
				while (!llist[L].empty()) llist[L].pop();
				llist[M].push(last-m);
				last--;
				break;
		}
	}
	for(int i=1;i<m;i++)
	{
		cout << "queue " << i << ":";
		output(llist[i]);
		if(hadout == 0)
			cout << " empty!";
		cout << endl;
		hadout = 0;
	}
}
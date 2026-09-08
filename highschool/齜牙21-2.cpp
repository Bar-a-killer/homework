#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	int pos[n+1];
	int data[n+1];
	for(int j=1;j<=n;j++)
	{
		pos[j] = j;
		data[j] = j;
	}
	int m;
	int mod,po,tmp;
	cin >> m;
	int k = 1;
	for(int i=0;i<m;i++)
	{
		// cout << i << ":";
		// for(int j=1;j<=n;j++)
			// cout << data[j] << " ";
		// cout << endl;
		cin >> mod >> po;
		if(mod == 1)
		{
			while(pos[po]-k > 0 && data[pos[po]-k] == 0)
				k++;
			if(pos[po]-k == 0)
				continue;
			tmp=data[pos[po]-k];
			swap(data[pos[po]],data[pos[po]-k]);
			swap(pos[po],pos[tmp]);
			k=1;
		}
		else if(mod == 0)
		{
			data[pos[po]]=0;
			
			pos[po] = 0;
		}
		
		
	}
	for(int j=1;j<=n;j++)
		if(data[j] != 0 && j != n)
			cout << data[j] << " ";
		else if(data[j] != 0)
			cout << data[j];
	cout << endl;
}
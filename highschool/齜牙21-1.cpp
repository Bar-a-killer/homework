#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n,m;
	cin >> n;
	int birdpos[n];
	int *thepos[n];
	for(int i=0;i<n;i++){
		birdpos[i] = n-i;
		thepos[i] = birdpos+i;
	}
	int mod,pos;
	int *ptmp;
	int tmp,next=1;
	int end = n-1;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		cin >> mod >> pos;
		//cout << i << endl;
		pos = pos-1;
		if(mod && *thepos[pos] != birdpos[end])
		{
			while(0==*(thepos[pos]+next))
				next++;
			tmp = *thepos[pos];
			*(thepos[pos]+next) = tmp;
			*thepos[pos] = *(thepos[pos]+next);
			ptmp = thepos[pos];
			thepos[pos] = thepos[*(thepos[pos]+next)];
			thepos[*(thepos[pos]+next)] = ptmp;
		}
		if(!mod)
		{
			*thepos[pos] = 0;
			if(birdpos[end] == 0)
				end--;
		}
			
		next=1;
	}
	for(int i=n-1;i>=0;i--)
		if(birdpos[i]!=0)
			cout << birdpos[i] << ' ';
	cout << endl;
}
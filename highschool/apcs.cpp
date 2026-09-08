#include <bits/stdc++.h>
using namespace std;
#define Waimai ios::sync_with_stdio(false),cin.tie(0)
#define FOR(x,a) for(int x=0;x<a;x++)
int main ()
{
	Waimai;
	int x=0,y=0;
	char trash;
	scanf("%d %d",&x,&y);
	x=2*x-1;
	char a[x/2];
	int poslen=(x+1)/2;
	int aPos[poslen];
	FOR(i,poslen)
		aPos[i]=i;
	while(y--)
	{
		FOR(i,x)
		{
			if(i%2==0)
				cin >> trash;
			else
				cin >> a[(i-1)/2];	
		}
		FOR(i,poslen)
		{
			if(a[aPos[i]]==45)
				aPos[i]++;
			else if(a[aPos[i]-1]==45)
				aPos[i]--;
		}
		
	}
	FOR(i,poslen)
		printf("%d ",aPos[i]+1);
	return 0;
}

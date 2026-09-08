#include <bits/stdc++.h>
using namespace std;
#define Waimai ios::sync_with_stdio(false),cin.tie(0)
#define FOR(x,a,b) for(int x=a;x<=b;x++)
int main(void){
	string a;
	int x=0,y=0;
	
	FOR(i,0,148)
	{
		getline(cin,a);
		FOR(j,0,27)
		{
			//if(a[j] == ' ')
			//{
				if(a[j]=='¤ý') x++; 
				else if(a[j]=='2')y++;
			//}
		}
	}
	printf("¨k:%d ¤k:%d",x,y);
} 

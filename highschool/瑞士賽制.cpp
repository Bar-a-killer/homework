#include<bits/stdc++.h>
using namespace std;
#define FOR for(int i=0;i<2*n;i++)
int n,r,q;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);	
	cin >> n >> r >> q;
	vector< pair <int,int> > number(2*n);
	int ptr[2*n];
	FOR cin >> number[i].first;
	FOR {
		cin >> number[i].second; 
		ptr[i]=number[i].second;
	}
	
	
	while(r--)
	{
		sort(number.begin(),number.end());
		for(int i=0;i<2*n;i+=2)
		{
			number[i].second<number[i+1].second ? number[i+1].first++ : number[i].first++;
		}
	}
	sort(number.begin(),number.end());
	FOR if(ptr[i]==number[q-1].second)
	        printf("%d",i+1);
} 

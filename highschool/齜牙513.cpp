#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main(){
	int n;
	cin >> n;
	stack<pair<int,int>> datas;
	pair<int,int> ptmp;
	long tmp,tmp1;
	long maxx=0;
	
	ptmp.F = 0;
	ptmp.S = 0;
	datas.push(ptmp);
	
	for(int i=1;i<=n;i++){
		cin >> tmp;
		
		while(datas.size() != 1 && datas.top().F > tmp)
		{
			tmp1 = datas.top().F;
			while(datas.size() != 1 && datas.top().F == tmp1)
				datas.pop();
			maxx = max(maxx,(i-datas.top().S-1)*tmp1);
		}
		ptmp.F = tmp;
		ptmp.S = i;
		datas.push(ptmp);
	}
	while(datas.size() != 1)
	{
		tmp1 = datas.top().F;
		datas.pop();
		maxx = max(maxx,long((n-datas.top().S))*tmp1);
	}
	cout << maxx << endl;
}
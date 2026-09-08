#include<bits/stdc++.h>
using namespace std;
string datas;

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	
	string test;
	cin >> datas;
	int N,Q;
	cin >> N >> Q;
	cin >> test;
	long T,X;
	int ans;
	long k;
	map<long,pair<long,int> > tle;
	vector<int> cycle;
	for(int i=Q;i>0;i--)
	{		
		cin >> T >> X;
		ans = test[X-1];
		k=0;
		// if(tle.find(X) != tle.end())
		// {
			// k = tle[X].first;
			// if(k<=T)
			// {
				// ans = tle[X].second;			
			// }
			// else
				// k=0;
		// }
		cycle.push_back(int(ans));
		for(int j=k;j<T;j++)
		{
			if(datas[ans-65]==ans-65)
			{
				break;
			}
			
			ans = datas[ans-65];
			if(ans!=cycle.front())
			{
				cycle.push_back(ans);
			}
			else
			{
				ans = cycle[T%cycle.size()];
				break;
			}
		}
		cycle.clear();
		
		// if(k<T)0
		// {
			// tle[X].first = T;
			// tle[X].second = ans;
		// }
		printf("%c\n",ans);
	}
}
	
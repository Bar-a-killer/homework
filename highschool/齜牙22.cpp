#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int T,N;
	deque<int> datas;
	cin >> T;
	int tmp,uja1,uja2,uja3,ans=0,pos = 1;
	while(T--)
	{
		cin >> N;
		while(N--)
		{
			cin >> tmp;
			datas.push_back(tmp);
		}
//		datas.push_back(0);
		uja1 = datas[0];
		uja2 = 0;
		uja3 = datas[1];
		while(datas.size() > 1)
		{
			uja1=datas.front();
			datas.pop_front();
			do
			{
				cout << "out-" << uja1 << ":" << uja2 << ":" << uja3 << "pos:" << pos << " " << datas[pos] <<endl; 
				ans++;
				uja2 = max(uja3,uja2);
				pos++;
				uja3 = datas[pos];
			}while(uja1>=uja2 && uja3>=uja2 && pos < datas.size());
			pos = 1;
			uja2 = 0;
		}
		cout << ":" << ans << endl;
		ans = 0;
		while(!datas.empty()) datas.pop_back(); 
	}
}

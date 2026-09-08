#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int T,N,M,K;
	vector<set<int>> china;
	set<int> stmp;
	deque<pair<int,int>> vetmp;
	int tmp;
	string mode;
	pair<int,int> ptmp,outputpair;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cout << "Line #" << i+1 << endl;
		cin >> N;
		for(int j=0;j<N;j++)
		{
			cin >> K;
			for(int k=0;k<K;k++)
			{
				cin >> tmp;
				stmp.insert(tmp);
			}
			china.push_back(stmp);	
		}
		cin >> M;
		outputpair.first = -1;
		int vetmplen=0;
		int newdata=1;
		for(int j=0;j<M;j++)
		{
			//if(j==10||j==11)
			//	cout<<outputpair.first<< " " << vetmp.front().first << endl;
			if(outputpair.first == -1)
			{
				cin >> mode;
				cin >> tmp;
				for(int k=0;k<N;k++)
				{
					if(china[k].count(tmp))
					{
						china[k].erase(tmp);
						outputpair.first = tmp;outputpair.second = k;
						break;
					}
				}
			}
			else
			{
				cin >> mode;
				if(mode[0] == 'E')
				{
					cin >> tmp;
					for(int k=0;k<N;k++)
					{
						if(china[k].count(tmp))
						{
							china[k].erase(tmp);
							ptmp.first = tmp;ptmp.second = k;
							vetmp.push_back(ptmp);
							vetmplen++;
							break;
						}
						else if(k+1==N)
						{
							ptmp.first = tmp;ptmp.second = k+newdata;
							vetmp.push_back(ptmp);
							newdata++;
							vetmplen++;
						}
					}
				}
				else if(mode[0] == 'D')
				{
					cout << outputpair.first << endl;
					while(vetmp.front().second == -1)
					{
						vetmp.pop_front();
						vetmplen--;
					}
					if(vetmplen == 0)
					{
						outputpair.first = -1;
						continue;
					}
					if(outputpair.second == vetmp.front().second)
					{
						outputpair.first = vetmp.front().first;
						vetmp.pop_front();
						vetmplen--;
					}
					else
					{
						for(int k=0;k<vetmplen;k++)
						{
							if(outputpair.second == vetmp[k].second)
							{
								vetmp[k].second = -1;
								outputpair.first = vetmp[k].first;
								break;
							}
							if(k+1 == vetmplen)
							{
								outputpair = vetmp.front();
								vetmp.pop_front();
								vetmplen--;
								break;
							}
						}
					}
				}
			}
		}
		china.clear();
		vetmp.clear();
	}
}
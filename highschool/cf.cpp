#include<bits/stdc++.h>
using namespace std;
#define FOR(x,a) for(int x = 0;x < a;x++)
vector<int> dataa;
vector<int> sorst; 
map<int,int> data_map;
set<int> nums;
int len;
void input()
{
	int n,tmp;
	cin >> n;
	len = n/2;
	n=n/2;
	while(n--)
	{
		cin >> tmp;
		dataa.push_back(tmp);
		nums.insert(n+1);
		nums.insert(len+n+1);	
	}
}

int sor()
{
	vector<int> tmp_data = dataa;
	sort(tmp_data.begin(),tmp_data.end());
	int min=1;
	FOR(i,len)
	{
		if(!nums.count(min))
			while(min < tmp_data[i] && !nums.count(min)) min+=1;
		if(min < tmp_data[i] && nums.count(tmp_data[i]))
		{
			data_map[tmp_data[i]] = min;
			nums.erase(min);
			nums.erase(tmp_data[i]);
		}
		else
			return 1;
		
		min++;
	}
	return 0;
}

void take_map()
{
	FOR(i,len)
	{
		sorst.push_back(data_map[dataa[i]]);
		sorst.push_back(dataa[i]);
	}
}

void output()
{
	FOR(i,2*len)
	{
		cout << sorst[i] << ' ';
	}
	cout << endl;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		input();
		if(!sor())
		{
			take_map();
			output();
		}
		else
			cout << -1 << endl;
		dataa.clear();
		sorst.clear(); 
		data_map.clear();
		nums.clear();
	} 
}
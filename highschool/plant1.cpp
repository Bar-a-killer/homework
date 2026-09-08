#include<bits/stdc++.h>
using namespace std;
vector<string> pool;
vector<vector<int> > player;
vector<vector<string> > hand_card;

int alive_player[4]={1,2,3,4};
void save_data()
{
	string tmp;
	int ttmp;
	for(int i=0;i<52;i++)
	{
		cin >> tmp;
		pool.push_back(tmp);
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<52;j++)
		{
			cin >> ttmp;
			player[i][ttmp] = j;
		}
	}

}
void give(int i)
{
	hand_card[i].push_back(pool.back());
	pool.pop_back();
}
int main()
{
	player.resize(52*4);
	hand_card.resize(52*4);
	save_data();
	for(int j=0;j<5;j++)
		for(int i=0;i<4;i++)
			give(i);
	printf("OK");
	system("pause");
	return 0;

}

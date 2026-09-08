#include<bits/stdc++.h>
using namespace std;

int arry[5]={3,54,7,8,61};
vector<int> arryv(arry,arry+5);
vector<int> pos;
int head=0,now=0;
int index;

int find_index(int now,int index)
{
	if(index > pos.size()-3)
		index = pos.size()-3;
	if(index<=0)
		return now;
	return find_index(pos[now],index-1);
}
int remove()
{
	if(index >= 2)
		pos[now] = pos[pos[now]];			
	else
		head = pos[now];	
}
int add()
{
	int tmp;
	cin >> tmp;
	arryv.push_back(tmp);
	pos.push_back(pos[now]);
	if(index >= 2)
		pos[now] = pos.size()-1;
	else
		head = pos.size()-1;
}
int post()
{
	if(now == 5)
		return 0;
	cout << now+1 << ' ';
	cout << arryv[now] << endl;
	now = pos[now];
	return post();
}

int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	
	int i=6; while(i--) pos.push_back(6-i);
	
	now = head;
	post();
	
	char act;
	int num;
	cout << "num:" << endl;
	cin >> num;
	while(num--)
	{
		cin >> act;
		cin >> index;
		
		now = find_index(head,index-2);
		if(act == 'r')
			remove();
		else if(act == 'a')
			add();		
		now = head;
	}
	cout << "ouput all:" << endl;
	
	now = head;
	post();
}


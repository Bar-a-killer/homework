#include<bits/stdc++.h>
using namespace std;
int N,Q;
vector<vector<int> > datas;
void set_data()
{
	//datas.resize(N*N);
	vector<int> tmp(N);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			tmp.push_back(0);
		}
		datas.push_back(tmp);
	}
}
void output()
{
	vector<int> tmp(N);
	for(int i=0;i<N;i++)
	{
		tmp = datas[i];
		printf("%d",tmp[0]);
		for(int j=1;j<N;j++)
		{
			printf(" %d",tmp[j]);
		}
		printf("\n");
	}
}
void drow_R(int i,int k)
{
	int j=0,l=0;
	if(i<N)
	{
		l=l+N-i;
	}
	else if(i>N)
	{
		j=j+i-N;
	}
	for(;j<N&&l<N;j++,l++)
		if(datas[j][l] < k)
			datas[j][l]=k;

}
void drow_L(int i,int k)
{
	int j=0,l=N-1;
	if(i<N)
	{
		l=i-1;
	}
	else if(i>N)
	{
		j+=i-N;
	}
	for(;j<N&&l>=0;j++,l--)
		if(datas[j][l] < k)
			datas[j][l]=k;
}

int main()
{
	
	cin >> N >> Q;
	set_data();
	int op,i,k;
	for(int j=0;j<Q;j++)
	{
		cin >> op >> i >> k;
		if(op == 1)
			drow_R(i,k);
		else if(op == 2)
			drow_L(i,k);
	}
	output();
}
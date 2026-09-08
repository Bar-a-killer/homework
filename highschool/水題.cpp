#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	string str;
	stringstream ss;
	int bigr,bigw,smally,smallw,drug,m;
	int eat;
	int drugging=0;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> bigr >> bigw >> smally >> smallw >> drug >> m;
		getline(cin,str);
		ss << str;
		while(ss >> eat)
		{
			if(drugging==1)
				m-=drug;
			switch (eat)
			{
				case 1:
					m+=bigr;
				case 2:
					m+=bigw;
				case 3:
					m-=smally;
				case 4:
				{
					m-=smallw;
					drugging=1;
				}
			}
			if(m<0)
			{
				printf("bye~Rabbit\n");
				drugging=3;
				break;
			}
			
			
		}
		if(drugging!=3)
			printf("%dg\n",m);
			
		ss.str("");
		ss.clear();
	}

}

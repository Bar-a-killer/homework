#include<bits/stdc++.h>
using namespace std;
int main()
{
	int output=0,total=0;
	int s,d;
	cin >> s >> d;
	int e[s];
	for(int i = 0;i < s;i++)
		cin >> e[i];
	sort(e,e+s);
	for(int i = 0;i < s;i++)
	{
		total += e[i];
		if(total <= d)
			output++;
		else
			break;
	}
	printf("%d\n",output);
	return 0;
}
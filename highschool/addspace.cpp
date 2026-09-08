#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	string str;
	str[0]=1;
	vector<string>  data;
	while(str[0]!='0')
	{
		cin >> str;
		data.push_back(str);
	}
	cout << "start here" << endl;
	data.pop_back();
	while(!data.empty())
	{
		str=data.back();
		int i=-1,a=0;
		while(str[i+1]!='\0')
		{
			i++;
			if(!a&&(str[i]>'z'||str[i]<'a'))
			{
				cout << ' ';
				a=1;
			}	
			cout << str[i];
		}
		cout << endl;
		data.pop_back();
	}
}
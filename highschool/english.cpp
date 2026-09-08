#include<bits/stdc++.h>
using namespace std;
bool compare(string a,string b){
	return a[0]>b[0];
}
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
	data.pop_back();
	sort(data.begin(),data.end(),compare);
	
	
	
	cout << "start here" << endl;
	
	while(!data.empty())
	{
		cout << data.back() << endl;
		data.pop_back();
	}
	system("pause");
	return 0;
} 

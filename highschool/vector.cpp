#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> S;
	int t,input,tr=0;
	string move;
	cin >> t;
	while(t--)
	{
		cin >> move;
		if(move == "add")
		{
			cin >> input;
			S.push_back(input);
		}
		else if(move == "show")
		{
			sort(S.begin(),S.end());
			cout << S.back() << endl;
		}
		else if(move ==  "delete")
		{
			cin >> input;
			vector<int>::iterator it;
			for(it = S.begin();it!=S.end();++it)
			{
				if(*it == input)
				{
					S.erase(it);
					it--;
					break;
				}
				
			}
		}
		
	}

} 

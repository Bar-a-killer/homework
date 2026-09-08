#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second > p2.second;
}

int main() {
	int T,n;
	pair<int,int> tmp;
	cin >> T;
	while(T--) {
		vector<pair<int,int>> dish;
		int total=0;
		int cook=0;
		cin >> n;
		while(n--) {
			cin >> tmp.F;
			cin >> tmp.S;
			dish.push_back(tmp);
		}
		sort(dish.begin(),dish.end(),cmp);
		
		for(pair<int,int> man : dish) {
			total = max(cook + man.F + man.S,total);
			cook += man.F;
		}
		cout << total << endl;
	}
}
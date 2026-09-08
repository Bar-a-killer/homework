#include<bits/stdc++.h>
using namespace std;

int main() {
	//ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		vector<int> stone;
		int n,tmp;
		cin >> n;
		while(n--) {
			cin >> tmp;
			stone.push_back(tmp);
		}
		tmp = stone.back();
		stone.pop_back();
		bool det = 1;
		int ans = 0;
		while(!stone.empty()) {
			if(det == (stone.back() < tmp) && stone.back() != tmp) {
				det = !det;
				ans++;
			}
			tmp = stone.back();
			stone.pop_back();
		}
		if(det)
			ans++;
		cout << ans << endl;
	}
}
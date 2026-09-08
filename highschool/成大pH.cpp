#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m,k,tmp;
	vector<int> ai;
	cin >> n >> m >> k;
	for(int i=0;i < n;i++) {
		cin >> tmp;
		ai.push_back(tmp);
	}
	int chain = 0;
	long long ans = 0,bot = 0;
	long long start,max_k=0;
	for(int i=0;i < m;i++) {
		start = chain;
		while(chain < n-1) {
			if(bot + ai[chain] <= k)
				bot += ai[chain];
			if(bot > k) {
				max_k = max(max_k,bot - ai[chain]);
				bot -= ai[start];
				start++;
			}
			chain++;
		}
		ans += max_k;
	}
	cout << ans;
}
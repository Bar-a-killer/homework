#include<bits/stdc++.h>
using namespace std;

int main() {
	int N,M;
	int T;
	long long dp[10001];
	
	cin >> T;
	while(T--) {
		for(int i=0;i<10001;i++)
			dp[i] = -1;
		cin >> N >> M;
		int w[N],v[N];
		long long ans = 0,l = 1;
		for(int i = 0; i<N; i++)
			cin >> w[i] >> v[i];
		for(int i = 0; i<N; i++) {
			for(int j = 10000; j >= v[i]; j--) {
				if(dp[j - v[i]] != -1 && dp[j] != -1)
					dp[j] = min(dp[j],dp[j - v[i]]+w[i]);
				else if(dp[j - v[i]] != -1)
					dp[j] = dp[j - v[i]]+w[i];
				if(v[i] == j) {
					if(dp[j] == -1)
						dp[j] = w[i];//cout << "check";
					else 
						dp[j] = min(dp[j],l*w[i]);
				}
				//if(dp[j] != -1)
					//cout << j << "/dp[j]:" << dp[j] << "/v[i]:" << v[i] << "/w[i]:" << w[i] << endl;
			}
		}
		for(int j = 100*N; j >= 0; j--) {
			if(dp[j] <= M && dp[j] >= 0)
				ans = max(ans,j*l);
		}
		cout << ans << endl;
	}
}
#include<bits/stdc++.h>
using namespace std;

int main() {
	int N,M,K;
	int T;
	
	cin >> T;
	while(T--) {
		cin >> N >> M >> K;
		long long dp[10001][K+1];
		for(int i = 0; i<10001; i++) {
			for(int j = 0;j<K+1 ; j++)
				dp[i][j] = 0;
		}
		int w[N],v[N];
		for(int i = 0; i<N; i++)
			cin >> w[i] >> v[i];
			
		int ww[10001][K];
		for(int i = 0; i<N; i++) {
			for(int j = 10000; j >= w[i]; j--) {
				
				if(dp[j - w[i]][K-1] != 0)
					for(int l = 0;l<K ; l++)
						dp[j - ww[j - w[i]][l] + w[i]][K] = max(dp[j - ww[j - w[i]][l] + w[i]][K],dp[j - w[i]][K] + v[i] - dp[j - w[i]][l]);
						
				if(dp[j - w[i]][K-1] == 0 && dp[j][K] <= dp[j - w[i]][K] + v[i]) {
					dp[j][K] = dp[j - w[i]][K] + v[i];
					copy(dp[j - w[i]], dp[j - w[i]]+K, dp[j]);
					for(int k = 0;k < K ; k++) {
						if(dp[j][k] == 0) {
							dp[j][k] = v[i];
							ww[j][k] = w[i];
							break;
						}
					}
				}
				
			}
		}
		
		
		long long ans = 0;
		for(int i = 0; i<=M ; i++)
			ans = max(ans,dp[i][K]);
		cout << ans << endl;
	}
}
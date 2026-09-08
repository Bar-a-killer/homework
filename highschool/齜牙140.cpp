#include <bits/stdc++.h>
using namespace std;

int main() {
	int mod = 1000007;
	int dp[100000][3];
	dp[0][0] = dp[0][1] = dp[0][2] = 1;
	long long l = 1;
	for(int i = 1;i < 100000;i++) {
		dp[i][0] = (l*dp[i-1][0] + l*dp[i-1][1] + l*dp[i-1][2])%mod;
		dp[i][1] = (l*dp[i-1][0] + l*dp[i-1][1]-1)%mod;
		dp[i][2] = (l*dp[i-1][0] + l*dp[i-1][2]-1)%mod;
	}
	int T,n;
	cin >> T;
	while(T--) {
		cin >> n;
		cout << (l*dp[n-1][0] + l*dp[n-1][1] + l*dp[n-1][2])%mod << endl;
	}
}
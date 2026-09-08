#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define For(i,x) for(int i = 0;i < x;i++)
typedef pair<int,int> Pt;
bool cmp(Pt a,Pt b) {
	return a.F < b.F;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	vector<Pt> coin;
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        Pt tmp;
        bool dp[200*100] = {0};
        For(i, N) {
            cin >> tmp.F >> tmp.S;
            coin.pb(tmp);
        }
        dp[0] = 1;
        
        
        for(int i = 0;i < N;i++) {
        	for(int k = M;k >= 1;k--) {
        		for(int j = coin[i].S;j >= 1 ;j--) {
        			if(k - j*coin[i].F >= 0)
        				dp[k] = dp[k - j*coin[i].F] || dp[k];
        		}
        		//cout << k << " : " << dp[k] << endl;
        	}
        }
        
        
        
        if (dp[M])
            cout << "Yes" << endl;
        else
            cout << "No"  << endl;
        For(i,N) {
            dp[0] = 0;
            dp[1] = 0;
        }
        coin.clear();
    }
    return 0;
}
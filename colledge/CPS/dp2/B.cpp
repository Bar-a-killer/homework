#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
pii dp[1<<20];

signed main() {
    int n;
    cin >> n;
    int limit;
    cin >> limit;
    int people[22];
    for(int i = 0;i < n;i++) cin >> people[i];
    for(int i = 0;i < 1<<n;i++) {
        dp[i].first = n+3;
        dp[i].second = 0;
    }
    dp[0].first = 0;dp[0].second = limit;
    for(int s = 1;s < 1<<n;s++) {
        for(int i = 0;i < n;i++) {
            if(!(s & 1<<i)) continue;
            int from = s^(1<<i);
            auto [a,b] = dp[from];
            if(b+people[i] <= limit) b+=people[i];
            else {
                a++;b = people[i];
            }
            if(dp[s].first > a) {
                dp[s] = {a,b};
            } else if(dp[s].first == a) {
                dp[s].second = min(dp[s].second,b);
            }
        }
    }
    cout << dp[(1<<n)-1].first << "\n";
}
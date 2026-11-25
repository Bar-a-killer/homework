#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    int ans = 0;
    vector<int> prime(n+100,0);
    for(int i = 1;i < n+100;i++) {
        for(int j = i;j < n+100;j+=i) {
            prime[j] ++;
        }
    }
    for(int i = 1;i < n;i++) {
        ans += prime[i] * prime[n-i];
    }
    cout << ans << endl;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    map<int,int> d;
    for(int i = 0;i < n;i++) {
        int tmp;cin >> tmp;
        if(d.find(tmp) == d.end()) {
            d[tmp] = 1;
        } else d[tmp]++;
    }
    int ans = 0;
    for(auto& pair : d) {
        int x = pair.first;int a = pair.second;
        if(x > a) ans += a;
        else ans += a-x; 
    }
    cout << ans << endl;
}
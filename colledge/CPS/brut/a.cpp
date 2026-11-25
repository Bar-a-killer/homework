#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    while(cin >> n) {
        int ans = 0;
        vector<pair<int,int>> ansvec;
        for(int y = n+1;y <= 2*n;y++) {
            if(y*n%(y-n)) continue;
            ans ++;
            ansvec.push_back({(y*n/(y-n)),y});
        }
        cout << ans << endl;
        for(auto i : ansvec) {
            cout << "1/" << n << " = 1/" << i.first << " + 1/" << i.second << endl;
        }
    }
}

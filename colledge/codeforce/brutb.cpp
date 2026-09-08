#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n+1);
        for(int i = 1; i <= n; i++) cin >> p[i];
        
        long long ans = 0;
        for(int l = 1; l <= n; l++){
            int mn = p[l], mx = p[l], g = p[l];
            for(int r = l; r <= n; r++){
                mn = min(mn, p[r]);
                mx = max(mx, p[r]);
                g = __gcd(g, p[r]);
                if(mx - mn == g) ans++;
            }
        }
        cout << ans << "\n";
    }
}
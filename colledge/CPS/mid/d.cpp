#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main() {
    int n,k;cin >> n >> k;
    vector<int> dt(n);
    for(auto &i:dt) cin >> i;
    int l = 0;int r = 1e16;
    while(l < r) {
        int mid = (l+r)/2;
        int cnt = 0;
        int ll = 0;
        int sum = 0;
        for(int i = 0;i < n;i++) {
            sum += dt[i];
            while(sum > mid) {
                sum -= dt[ll];
                ll++;
            }
            cnt += i-ll+1;
        }
        if(cnt >= k) r = mid;
        else l = mid+1;
    }
    cout << l << endl;
}

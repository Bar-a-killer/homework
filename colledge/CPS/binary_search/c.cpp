#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,m;
    cin >> n >> m;
    int mx = 0;
    int mxele = 0;
    vector<int> L(n);
    for(auto& i:L) {
        cin >> i;
        mx += i+1;
        mxele = max(mxele,i);
    }
    int l = mxele,r = mx+1;
    while(l < r) {
        int mid = (l+r) / 2;
        int cnt = 0;
        int nowlen = mid;
        for(auto i:L) {
            nowlen += 1+i;
            if(nowlen > mid) {
                cnt++;
                nowlen = i; 
            }
        }
        if(cnt > m) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}

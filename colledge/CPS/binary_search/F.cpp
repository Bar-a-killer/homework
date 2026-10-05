#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,q;
    cin >> n >> q;
    vector<int> A;
    vector<int> diff;
    for(int i = 1;i <= n;i++) {
        int tmp;cin >> tmp;
        A.push_back(tmp);
        diff.push_back(tmp-i);
    }
    A.push_back((int)3e18+1);
    diff.push_back((int)3e18-n);
    while(q--) {
        int tmp;cin >> tmp;
        int pos = lower_bound(diff.begin(),diff.end(),tmp)-diff.begin();
        int ans = A[pos]-diff[pos]+tmp-1;
        cout << ans << endl;
    }
}

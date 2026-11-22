#include <algorithm>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int solve() {
    int n;cin >> n;
}
signed main() {
    int n,k;cin >> n >> k;
    vector<int> datas(n);
    int mix = 0;
    for(auto &i:datas) {
        cin >> i;
        mix += i;
    }
    int l = *max_element(datas.begin(),datas.end()),r = mix;
    while(l < r) {
        int mid = (l+r) / 2;
        int cnt = 0;
        int cnt2 = 1;
        for(auto i:datas) {
            if(cnt+i>mid) {
                cnt2++;
                cnt = 0;
            } 
            cnt+=i;
        }
        if(cnt2 > k) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,k;cin >> n >> k;
    vector<int> dt(n+1);
    for(int i = 1;i <= n;i++) {
        int a,b;cin >> a >> b;
        dt[i-1] = a+b;
    }
    vector<int> a;
    for(int i = 1;i < n;i++) {
        a.push_back(dt[i]-dt[i-1]);
    }
    vector<int> p;
    p.push_back(0);
    n--;
    for(int i = 0;i < n;i++) {
        p.push_back(p.back()+a[i]);
    }
    vector<int> pp;pp.push_back(0);
    for(int i = 0;i <= n;i++) {
        pp.push_back(pp.back()+p[i]);
    }
    vector<int> ppp;ppp.push_back(0);
    for(int i = 0;i <= 1+n;i++) {
        ppp.push_back(ppp.back()+pp[i]);
    }
    while(k--) {
        int l,r;cin >> l >> r;r--;
        cout << (r-l+1)*(pp[r+1]+pp[l-1])-2*(ppp[r+1]-ppp[l])<< endl;
    }
}

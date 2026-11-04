#include<bits/stdc++.h>
using namespace std;
#define int long long
#define piii pair<int,pair<int,int>>

int a,b,c,d;
void func(int aa,int bb,int cc,map<piii,int> &mp) {
}
void solve() {
    cin >> a >> b >> c >> d;
    map<piii,int> mp;
    piii tmp = {0,{0,c}};
    mp[tmp] = 0;
    func(0LL,0LL,c,mp);
    int minwater = 1e18;
    int mindiff = 1e18;
    priority_queue<pair<int,piii>, vector<pair<int,piii>>, greater<pair<int,piii>>> pq;
    pq.push({0,tmp});
    while(!pq.empty()) {
        auto [w, cur] = pq.top(); pq.pop();
        auto [aa, rest] = cur;
        auto [bb, cc] = rest;
        piii tmp[6] = {
            {max(0LL,aa-(b-bb)), {bb+min(aa,b-bb), cc}},                 // A -> B
            {max(0LL,aa-(c-cc)), {bb, cc+min(aa,c-cc)}},                 // A -> C
            {aa+min(bb,a-aa),    {max(0LL,bb-(a-aa)), cc}},              // B -> A
            {aa,                 {max(0LL,bb-(c-cc)), cc+min(bb,c-cc)}}, // B -> C
            {aa+min(cc,a-aa),    {bb, max(0LL,cc-(a-aa))}},              // C -> A
            {aa,                 {bb+min(cc,b-bb), max(0LL,cc-(b-bb))}}  // C -> B
        };
        long long tmp2[6] = {
            min(aa, b-bb),  // A -> B
            min(aa, c-cc),  // A -> C
            min(bb, a-aa),  // B -> A
            min(bb, c-cc),  // B -> C
            min(cc, a-aa),  // C -> A
            min(cc, b-bb)   // C -> B
        };
        piii ha = {aa,{bb,cc}};
        int from = mp[ha];
        for(int i = 0;i < 6;i++) {
            if(!tmp2[i]) continue;
            if(mp.find(tmp[i])==mp.end() || mp[tmp[i]] > w+tmp2[i]) {
                mp[tmp[i]] = from+tmp2[i];
                pq.push({w+tmp2[i],tmp[i]});
            }
        }
    }

    cout << minwater << " " << mindiff << '\n';
}
signed main() {
    int t;cin >> t;
    while(t--) {
        solve();
    }
}

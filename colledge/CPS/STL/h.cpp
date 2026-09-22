#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    int num;
    int cnt;
    int l,r;
    bool operator<(const node& o) const {
        if (cnt != o.cnt) return cnt < o.cnt;
        return l > o.l;
    }
    bool operator>(const node& o) const {
        return o < *this;
    }
    void print() {
        cout << "num:" << num << " l:" << l << " r:" << r << " cnt:" << cnt << endl;
    }
};
signed main() {
    int n;
    cin >> n;
    vector<node > vp;
    int tmp;cin >> tmp;
    multiset<node> mts;
    node tmpp;
    tmpp.l = -1;tmpp.r = 1;tmpp.num = tmp;tmpp.cnt = 1;
    for(int i = 1;i < n;i++) {
        cin >> tmp;
        if(tmpp.num == tmp) tmpp.cnt++;
        else {
            vp.push_back(tmpp);
            mts.insert(tmpp);
            tmpp.l++;tmpp.r++;tmpp.num = tmp;tmpp.cnt = 1;
        }
    }
    vp.push_back(tmpp);
    mts.insert(tmpp);
    int ed = tmpp.r;
    int ans=0;
    while(!mts.empty()) {
        // for(node i:mts) {
        //     i.print();
        // }
        // cout << endl;
        node rm = *mts.rbegin();
        // rm.print();
        // cout << endl;
        mts.erase(prev(mts.end()));
        if(rm.l > -1 && rm.r < ed && vp[rm.r].num == vp[rm.l].num) {
            node r = vp[rm.r],l = vp[rm.l];
            mts.erase(mts.find(r));
            mts.erase(mts.find(l));
            l.cnt += r.cnt;
            vp[rm.l].cnt = l.cnt;
            rm.r = vp[rm.r].r;
            mts.insert(l);
        }
        if(rm.l > -1) {
            mts.erase(mts.find(vp[rm.l]));
            vp[rm.l].r = rm.r;
            mts.insert(vp[rm.l]);
        } 
        if(rm.r < ed) {
            mts.erase(mts.find(vp[rm.r]));
            vp[rm.r].l = rm.l;
            mts.insert(vp[rm.r]);
        }
        ans ++;
    }
    cout << ans << endl;
}
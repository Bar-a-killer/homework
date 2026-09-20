#include<bits/stdc++.h>
using namespace std;
#define int long long

struct node {
    int num;
    int cnt;
    int l,r;
};
signed main() {
    int n;
    cin >> n;
    vector<node > vp;
    int tmp;cin >> tmp;
    node tmpp;
    tmpp.l = -1;tmpp.r = 1;tmpp.num = tmp;tmpp.cnt = 1;
    vp.push_back(tmpp); 
    for(int i = 1;i < n;i++) {
        cin >> tmp;
        tmpp.l = i-1;tmpp.r = i+1;tmpp.num = tmp;tmpp.cnt = 1;
        if(vp.back().cnt == tmp) vp.back().cnt++;
        else vp.push_back(tmpp); 
    }
    
}
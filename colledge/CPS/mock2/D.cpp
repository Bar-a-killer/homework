#include<bits/stdc++.h>
using namespace std;
#define int long long

bool count(string op,bool a,bool b) {
    if(op == "AND") 
        return a&b;
    if(op == "OR")
        return a|b;
    if(op == "XOR")
        return a^b;
    return 0;
}
signed main() {
    int n,m;
    cin >> n >> m;
    vector<pair<string,int>> datas;
    for(int i = 0;i < n;i++) {
        string oop;int num;
        cin >> oop >> num;
        datas.push_back({oop,num});
    }
    int ans = 0;
    int tom = 0;
    for(int i = 30;i >= 0;i--) {
        bool v0 = 0,v1 = 1;
        for(int j = 0;j < n;j++) {
            auto v = datas[j];
            v.second = (v.second>>i)&1;
            v0 = count(v.first,v.second,v0);
            v1 = count(v.first,v.second,v1);
        }
        if(v0) {
            ans |= (1LL*v0) << i;
        } else if((tom | 1LL<<i) <= m && v1) {
            tom |= 1LL<<i;
            ans |= (1LL*v1) << i;
        }
    }
    cout << ans << endl;
}
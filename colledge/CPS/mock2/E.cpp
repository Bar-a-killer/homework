#include<bits/stdc++.h>
using namespace std;
#define int long long
#define cl(X) (X<<1)+1
#define cr(X) (X<<1)+2
#define INF 1e18
vector<int> arr(200005);
int l,r;

struct Binary_Indexed_Tree{
    int n;
    vector<long long> bit;
    int lowbit(int x){
        return x&-x;
    }
    void init(int _n){
        n = _n+1;
        bit = vector<long long>(n,0);
    }
    void update(int x,int v){
        for(; x<n; x+=lowbit(x)){
            bit[x] += v;
        }
    }
    long long query(int x){
        long long ret = 0;
        for(; x>0; x-=lowbit(x)){
            ret += bit[x];
        }
        return ret;
    }
}BIT;
int findl(vector<int>& tmp,int i) {
    return lower_bound(tmp.begin(), tmp.end(), i) - tmp.begin()+1;
}
int findu(vector<int>& tmp,int i) {
    return upper_bound(tmp.begin(), tmp.end(), i) - tmp.begin()+1;
}
signed main() {
    int n;
    cin >> n;
    cin >> l >> r;
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        if(i) arr[i] += arr[i-1];
    }

    vector<int> tmp(arr.begin(), arr.begin()+n);
    tmp.push_back(0);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    int ans = 0;
    BIT.init(tmp.size()+1);
    BIT.update(findl(tmp, 0), 1);

    for(int i = 0;i < n;i++) {
        int rbound = BIT.query(findu(tmp,arr[i] - l)-1);
        int lbound = BIT.query(findl(tmp,arr[i] - r)-1);
        ans += rbound - lbound;
        BIT.update(findl(tmp, arr[i]), 1);
    }
    cout << ans << endl;
}
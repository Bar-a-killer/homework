#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
vector<int> a;
int k;
bool check(int x) {
    set<int> s;
    int c=0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < x) {
            s.insert(a[i]);
        }
        if ((int)s.size() == x) {
            c++;
            s.clear();
        }
    }
    return c >= k;
}
int bs(int l,int r) {
    int mid = (l+r)>>1;
    if(l>=r) return mid;
    if(!check(mid)) {
        return bs(l,mid);
    } else {
        return bs(mid+1,r);
    }
}
signed main() {
    int n;
    cin >> n >> k;
    while(n--) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    cout << bs(0,2e5)-1 << endl;
}
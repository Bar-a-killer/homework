#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,m;cin >> n >> m;
    vector<int> narr,marr;
    for(int i = 0;i < n;i++) {
        int tmp;cin >> tmp;
        narr.push_back(tmp);
    }
    for(int i = 0;i < m;i++) {
        int tmp;cin >> tmp;
        marr.push_back(tmp);
    }
    int cmix = 0;
    int cmin = 100000000000000;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(cmin > (narr[i]&marr[j])) cmin = narr[i]&marr[j];
            else if((cmin&cmix) > (cmix&narr[i]&marr[j])) cmin = narr[i]&marr[j];
        }
        cmix = (cmix|cmin);
        cmin = 100000000000000;
    }
    cout << cmix << endl;
}

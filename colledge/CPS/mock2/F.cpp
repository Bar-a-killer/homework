#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int maxn = 1000006;
double pre[maxn] = {0};
signed main() {
    string ss;
    cin >> ss;
    double A = 0,W = 0,C = 0;
    int n = ss.length();
    for(int i = n-1;i >= 0;i--) {
        bool tmp = ss[i]=='W';
        pre[i] = (A + (tmp ? C : W))/(n-i);
        A += pre[i];
        if(tmp) W += (n - i);
        else C += (n - i);
    }
    cout << fixed << setprecision(9) << pre[0] << endl;
}
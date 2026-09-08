#include <bits/stdc++.h>
using namespace std;
#define int long long
double dp[2][101][101][101] = {0};

signed main() {
    int r,p,s;
    cin >> r >> s >> p;
    double rans = 0,pans = 0,sans = 0;
    dp[0][r][p][s] = 1;
    int maxn = 3*max({r,p,s});
    for(int i = 1;i <= maxn;i++) {
        for(int rr = 0;rr < r+1;rr++) {
        for(int pp = 0;pp < p+1;pp++) {
            if(!rr && !pp) continue;
            double src_rr = 2.0*((rr+1)*pp + pp*ss + ss*(rr+1));
            double src_pp = 2.0*(rr*(pp+1) + (pp+1)*ss + ss*rr);
            if(rr != r && src_rr > 0)
                dp[i%2][rr][pp][ss] += dp[(i-1)%2][rr+1][pp][ss]*(rr+1)*pp*2 / src_rr;
            if(pp != p && src_pp > 0)
                dp[i%2][rr][pp][ss] += dp[(i-1)%2][rr][pp+1][ss]*ss*(pp+1)*2 / src_pp;
        
        }
        }
        for(int rr = 1; rr <= r; rr++) rans += dp[i%2][rr][0][0];
        for(int pp = 1; pp <= p; pp++) pans += dp[i%2][0][pp][0];
        for(int ss = 1; ss <= s; ss++) sans += dp[i%2][0][0][ss];
        for(int rr = 0;rr < r+1;rr++) {
        for(int pp = 0;pp < p+1;pp++) {
        for(int ss = 0;ss < s+1;ss++) {
            dp[(i-1)%2][rr][pp][ss] = 0;
        }
        }
        }
        if(rans + pans + sans > 1 - 1e-10) break;
    }
    cout << fixed << setprecision(12) << rans << " " << sans << " " << pans << endl;
}
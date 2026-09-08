#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    double dp[2][8][8][8][8] = {0};
    for(int xs=0;xs < 8;xs++) {
        for(int ys=0;ys < 8;ys++) {
            for(int x=0;x < 8;x++) {
                for(int y=0;y < 8;y++) {
                    dp[0][xs][ys][x][y] = 0;
                    dp[1][xs][ys][x][y] = 0;
                }
            }
            dp[0][xs][ys][xs][ys] = 1;
            for(int i = 0;i < n;i++) {
                for(int xf=0;xf < 8;xf++) {
                    for(int yf=0;yf < 8;yf++) {
                        int devide;
                        if((xf<=0 || xf >= 7) && (yf<=0 || yf >= 7)) {
                            devide = 2;
                        } else if((xf<=0 || xf >= 7) || (yf<=0 || yf >= 7)) {
                            devide = 3;
                        } else {
                            devide = 4;
                        }
                        if(xf>0) dp[(i+1)%2][xs][ys][xf-1][yf] += dp[(i)%2][xs][ys][xf][yf]/devide;
                        if(xf<7) dp[(i+1)%2][xs][ys][xf+1][yf] += dp[(i)%2][xs][ys][xf][yf]/devide;
                        if(yf>0) dp[(i+1)%2][xs][ys][xf][yf-1] += dp[(i)%2][xs][ys][xf][yf]/devide;
                        if(yf<7) dp[(i+1)%2][xs][ys][xf][yf+1] += dp[(i)%2][xs][ys][xf][yf]/devide;
                        dp[(i)%2][xs][ys][xf][yf] = 0;
                    }
                }
            }
        }
    }
    double ans = 0;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            double prob_empty = 1.0;
            for (int sx = 0; sx < 8; sx++)
                for (int sy = 0; sy < 8; sy++)
                    prob_empty *= (1.0 - dp[n%2][sx][sy][x][y]);
            ans += prob_empty;
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}
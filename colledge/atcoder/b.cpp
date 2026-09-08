#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int x,y;
    cin >> x >> y;
    for(int i = 0;i < x;i++) {
        for(int j = 0;j < y;j++) {
            
            int t = 2;
            if(x == 1) t--;
            if(y == 1) t--;
            if(i > 0 && i < x-1) t++;
            if(j > 0 && j < y-1) t++;

            cout << t << " ";
        }
        cout << endl;
    }
}
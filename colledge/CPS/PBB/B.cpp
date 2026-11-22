#include<bits/stdc++.h>
#include <cmath>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> notprime(1e6+5);
    for(int i = 2; i <= 1e6+2; i++){
        if(!notprime[i]){
            for(long long j = i; i * j <= 1e6+2; j++){ 
                notprime[j * i] = 1;
            }
        }
    }
    while(n--) {
        int tmp;
        cin >> tmp;
        if(tmp != 1 && (int)sqrt(tmp)*(int)sqrt(tmp) == tmp && !notprime[(int)sqrt(tmp)]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxs = 1<<20;
struct tp {
    int q1,q2,q3;
};
int A[maxs] = {0};
tp F[maxs];
int x[200005];
signed main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> x[i];
        A[x[i]]++;
    }
    for(int i = 0; i<maxs; ++i)	F[i] = {A[i],A[i],A[i]};

    for(int i = 0;i < 20; ++i)
    for (int s = 0; s < maxs ; ++s)
        if (s & (1 << i))
            F[s].q1 += F[s ^ (1 << i)].q1;
    for(int i = 0;i < 20;i++) 
        for(int s = maxs-1;s >= 0;s--)
            if(!(s & (1<<i)))
                F[s].q2 += F[s|(1<<i)].q2;
    for(int i = 0; i < n; i++){
        int v = x[i];
        F[v].q3 = n - F[~v & (maxs-1)].q1;
    }
    for(int i = 0; i < n; i++){
        int v = x[i];
        cout << F[v].q1 << ' ' << F[v].q2 << ' ' << F[v].q3 << '\n';
    }
}
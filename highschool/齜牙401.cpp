#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define X first
#define Y second
typedef pair<long long,long long> Pt;

Pt operator+(const Pt &p1, const Pt &p2) {
    return Pt(p1.X + p2.X, p1.Y + p2.Y);
}

Pt operator-(const Pt &p1, const Pt &p2) {
    return Pt(p1.X - p2.X, p1.Y - p2.Y);
}

ll operator*(const Pt &p1, const Pt &p2) {
    return p1.X * p2.X + p1.Y * p2.Y;
}

ll operator^(const Pt &p1, const Pt &p2) {
    return p1.X * p2.Y - p1.Y * p2.X;
}
int sign(ll a) {
	if(a == 0) return 0;
	return a > 0 ? 1 : -1;
}
ll ori(const Pt &a, const Pt &b, const Pt &c) {
    ll cross = (b - a) ^ (c - a);
    //cout << cross << endl;
    return sign(cross);
}

bool btw(const Pt &a, const Pt &b, const Pt &c) {
    if (ori(a, b, c) != 0)
        return 0;
    return sign((c - a) * (c - b)) <= 0;
}

int main(void) {
    ios::sync_with_stdio(0), cin.tie(0);
    ll N;
    cin >> N;
    Pt a1, a3, a2, a4;
    for (int i = 0; i < N; i++) {
        cin >> a1.X >> a1.Y >> a2.X >> a2.Y >> a3.X >> a3.Y >> a4.X >> a4.Y;
        int a123 = ori(a1, a2, a3);
        int a124 = ori(a1, a2, a4);
        int a341 = ori(a3, a4, a1);
        int a342 = ori(a3, a4, a2);
        //cout << a123 << a124 << a341 << a342;
        if (a123 == 0 && a124 == 0) {
        	if(btw(a1, a2, a3) || btw(a1, a2, a4) || btw(a3, a4, a1) || btw(a3, a4, a2))
            	cout << "Yes" << endl;
            else
            	cout << "No" << endl;
            continue;
        }
        if (a123 * a124 <= 0 && a341 * a342 <= 0) {
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
    return 0;
}
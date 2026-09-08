#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define X first
#define Y second
typedef pair<long long,long long> Pt;

ll countPair(const Pt &a,const Pt &b) {
	return (a.X - b.X)*(a.X - b.X)+(a.Y - b.Y)*(a.Y - b.Y);
}
int main(void) {
	ll N;
	cin >> N;
	Pt tmp;
	vector<Pt> points;
	vector<ll> lengh;
	for(int i=0;i<N;i++) {
		cin >> tmp.X >> tmp.Y;
		points.push_back(tmp);
	}
	
	for(int i=0;i<N-1;i++) {
		for(int j=i+1;j<N;j++) {
			lengh.push_back(countPair(points[i],points[j]));
		}
	}
	sort(lengh.begin(),lengh.end());
	ll ans = 0;
	int times = 0;
	ll lleng = -1;
	for(int i=0;i<N*(N-1)/2;i++) {
		if(lengh[i] == lleng) {
			ans+=times;
			times++;
		}
		else
			times = 1;
		lleng = lengh[i];
	}
	cout << ans << endl;
}

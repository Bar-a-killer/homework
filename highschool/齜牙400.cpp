#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define X first
#define Y second
typedef pair<long long,long long> Pt;

ll countPair(const Pt &a,const Pt &b) {
	return (a.X - b.X)*(a.X - b.X)+(a.Y - b.Y)*(a.Y - b.Y);
}

long long cross(const Pt &a,const Pt &b) {
	return a.X * b.Y - a.Y * b.X;
}

int main(void) {
	ios::sync_with_stdio(0),cin.tie(0);
	ll N;
	cin >> N;
	Pt tmp;
	vector<Pt> points;
	vector<Pt> vecs;
	for(int i=0;i<N;i++) {
		cin >> tmp.X >> tmp.Y;
		points.push_back(tmp);
	}
	for(int i=0;i<N-1;i++) {
		vecs.push_back(make_pair(points[i+1].X-points[i].X,points[i+1].Y-points[i].Y));
	}
	int back = 0,left = 0,right = 0;
	for(int i=0;i<N-2;i++) {
		if(cross(vecs[i],vecs[i+1]) == 0 && (vecs[i].X*vecs[i+1].X < 0 || vecs[i].Y*vecs[i+1].Y < 0))
			back++;
		else if(cross(vecs[i],vecs[i+1]) > 0)
			left++;
		else if(cross(vecs[i],vecs[i+1]) < 0)
			right++;
	}
	cout << left << " " << right << " " << back << endl;
}

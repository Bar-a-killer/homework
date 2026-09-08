#include<bits/stdc++.h>
using namespace std;
void solve(int N,int X,int Y) {
	int x1=0,y1=0;
	while(x1+N < X) 
		x1+=N;
	while(y1+N < Y)
		y1+=N;
	if(N == 1)
		return;

	x1 += N/2;
	y1 += N/2;
	int x2=0,y2=0;
	int a[6];
	if(x1 < X)
		x2 = 1;
	if(y1 < Y)
		y2 = 1;
	int k = 0;
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			if(i != x2 || j != y2) {
				a[k] = i+x1;
				a[k+1] = j+y1;
				k+=2;
			}
		}
	}
	Report(a[0],a[1],a[2],a[3],a[4],a[5]);
	for(int i = 0 ; i < 6 ; i+=2)
		solve(N/2,a[i],a[i+1]);
	solve(N/2,X,Y);
}

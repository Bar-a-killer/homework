#include <bits/stdc++.h> 
using namespace std;

#define F first
#define S second
#define ll long long
vector<pair<int,int>> pots;
bool cmp(pair<int,int> a,pair<int,int> b) {
    return a.F>b.F;
}

ll count(pair<int,int> a,pair<int,int> b) {
    int x=a.F-b.F;
    int y=a.S-b.S;
    return x*x+y*y;
}
ll llabs(int a,int b) {
	if(a-b > 0)
		return a-b;
	else 
		return b-a;
}
ll solve(int l,int r) {
	if(l>=r-1) {
		//cout << "error" << r << l << endl;
		return 0;
	}
    if(l==r-2) {
    	//cout << pots[l].F << pots[l].S << pots[r-1].F << pots[r-1].S << ":" << count(pots[l],pots[r-1]) << endl;
        return count(pots[l],pots[r-1]);
    }
    if(l==r-3)
        return min(min(count(pots[l],pots[r-1]),count(pots[l],pots[r-2])),count(pots[r-2],pots[r-1]));
    ll ans=0;
    int helf=(3*l+r)/2;
    ans = min(solve(l,helf),solve(helf,r));
    
    int range=(int)sqrt(ans)+1;
    int mid=(pots[helf].F+pots[helf].F)/2;
    for(int i=helf-1;mid-pots[i].F<=range && i>=l;i--){
		for(int j=helf;pots[j].F-mid<=range && j<r;j++) {
			if(llabs(pots[i].S,pots[j].S)>range)
				continue;
			//cout << pots[i].F << pots[i].S << pots[j].F << pots[j].S << ":" << count(pots[i],pots[j]) << endl;
			ans = min(ans,count(pots[i],pots[j]));
		}
    }
    return ans;
}

int main(){
    int N;
    cin >> N;
    pair<int,int> tmp;
    for(int i=0;i<N;i++) {
        cin >> tmp.F >> tmp.S;
        pots.push_back(tmp);
    }
    sort(pots.begin(),pots.end(),cmp);

    cout << solve(0,N) << endl;
}
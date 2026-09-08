#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &datas,vector<pair<int,int>> &horse,int k,int n) {
	int l = 0,day = 0;
	while(l < n) {
		for(auto hor:horse) {
			for(int j=0;j<n;j++) {
	    		if(datas[j] > hor.first && j > 0) {
	    			datas[j-1] = -1;
	    			l++;
	    			break;
	    		}
	    		if(datas[j] > hor.first)
	    			break;
	    	}
		}
		day++;
		for(auto hor:horse) 
			hor.first += hor.second;
	}
	return day;
}
int main() {
    int T;
    int k,n,tmp;
    vector<int> datas(10000);
    vector<pair<int,int>> hores(10000);
    pair<int,int> ptmp;
    cin >> T;
    while(T--) {
        cin >> k >> n;
        int unuse = 0;
        for(int i = 0; i < k; i++) {
            cin >> ptmp.first;
            cin >> ptmp.second;
            hores.push_back(ptmp);
        }
        for(int i = 0; i < k; i++) {
            cin >> tmp;
            datas.push_back(tmp);
        }
        sort(datas.begin(),datas.end());
        while(int(datas.size()) != n)
        	datas.pop_back();
        for(int i = 0; i < k; i++) {
	    	if(ptmp.second == 0) {
	        	for(int j=0;j<n;j++) {
	        		if(datas[j] >= ptmp.first && j > 0) {
	        			datas[j-1] = -1;
	        			unuse--;
	        			hores.pop_back();
	        			break;
	        		}
	        		if(datas[j] >= ptmp.first && j == 0) {
	        			unuse++;
	        			break;
	        		}
	        	}
	        }
	    }
        if(k - unuse < n) 
        	cout << -1 << endl;
        else
        	cout << solve(datas,hores,k,n) << endl;
        hores.clear();
        datas.clear();
    }
}
#include<bits/stdc++.h>
using namespace std;
 int N,K;
// int ri(int x)
// {
	// if(x<0)
	// return -x;
	// else
	// return x;
// }
// 
// int re(int x,int y)
// {
	// return max(x ,y )-min(x ,y );
// }
int main()
{
	int tmps;
	cin >> N >> K;
	vector<int> lls;
	for(int i=0;i<N;i++){
		cin >> tmps;
		tmps = max(tmps,K-tmps);
		lls.push_back(tmps);
	}
	
	sort(lls.begin(),lls.begin()+N);
	printf("%d",lls.back()-lls.front());
	// if(N==2){
	// while((max(lls[N-1],K-lls[0])-lls[1] < lls[N-1]-lls[0] && K-lls[0] > lls[0])
	   // || (lls[N-2]-min(lls[1],K-lls[N-1]) < lls[N-1]-lls[0] && K-lls[N-1] < lls[N-1]))
	// {
		// if(max(lls[N-1],K-lls[0])-lls[1] < lls[N-1]-lls[0] && K-lls[0] > lls[0])
			// lls[N-1] = K-lls[N-1];
		// else
			// lls[0] = K-lls[0];
		// sort(lls,lls+N);
	// }}
	// else
	// {
	// vector<pair<int,int> > the;
	// vector<pair<int,int> > the1;
	// pair<int,int> tmp;
	// sort(lls.begin(),lls.begin()+N);
	// int miner=lls[0],maxer=lls[N-1],miden_1,miden_2;
	// for(int i=0;i<N;i++)
	// {
		// if(lls[i]<0)
			// miden_1=lls[i];	
	// }
	// for(int i=N;i>0;i--)
	// {
		// if(lls[i]>0)
			// miden_2=lls[i];	
		// if(lls[i]==0)
		// {
			// tmp.first=0;tmp.first=0;
			// the.push_back(tmp);
			// the1.push_back(tmp);
		// }
	// }
	// tmp.first = miner;tmp.second = miden_1;
	// the.push_back(tmp);
	// //tmp.first = -miner;tmp.second = -miden_1;
	// //the.push_back(tmp);
	// //tmp.first=miden_1+K;tmp.second=miner+K;
	// //the.push_back(tmp);
	// tmp.first=-miden_1+K;tmp.second=-miner+K;
	// the.push_back(tmp);
	// tmp.first=maxer;tmp.second=miden_2;
	// //the1.push_back(tmp);
	// //tmp.first=miden_2+K;tmp.second=maxer+K;
	// //the.push_back(tmp);
	// //tmp.first=-maxer;tmp.second=-miden_2;
	// the1.push_back(tmp);
	// tmp.first=-miden_2+K;tmp.second=-maxer+K;
	// the1.push_back(tmp);
	// int a,b;
	// while(!the.empty())
	// {
		// while(!the1.empty())
		// {
			// a = min(min(the.back().first,the1.back().first),min(the.back().second ,the1.back().second));
			// b = max(max(the.back().first,the1.back().first),max(the.back().second ,the1.back().second));
			// ans=min(ans,b-a);
			// the1.pop_back();
		// }
		// the.pop_back();
	// }
	// //}
	//printf("%d",ans);
}
#include<bits/stdc++.h>
using namespace std;

queue<int> order;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int x;
	scanf("%d",&x);
	int a=1,b=10,c=13;
	order.push(a);
	order.push(b);
	order.pop();
	order.push(c);
	order.pop();
	order.push(x);
	for(int i=0;i<=order.size();i++){
		printf("%d\n",order.front());
		order.pop();	
	}

	
	
	
	
	
	return 0;
}


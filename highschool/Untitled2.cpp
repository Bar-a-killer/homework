#include <bits/stdc++.h> 
using namespace std;
#define FOR(x,a,b) for(int x=a;x<=b;x++)

void loop(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}


int main(){
    ios::sync_with_stdio(0),cin.tie(0);
	int N;
    cin >> N;
    int b;
    int hu=0,ko=0,ka=0;
    bool type[9]={0};
    string str;
    FOR(i,0,N){
    	getline(cin,str);
    	switch(str)
    	{
    		case "1 0 0 0":
    			b++;
    			break;
		}
		
		
			
	}
    printf("%d",b);
	
}

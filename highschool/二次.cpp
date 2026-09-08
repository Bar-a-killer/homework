#include <bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(0),cin.tie(0);
int a,b,b1,c;
cin >> a >> b >> b1;
c=pow(b,2)-(4*a*b1);
if(c<0)
{
printf("No real root");
return 0;
}
if(c==0)
printf("Two same roots x=%d",(0-b)/(2*a));
else
printf("Two different roots x1=%.0f , x2=%.0f",(0-b+sqrt(c))/(2*a),(0-b-sqrt(c))/(2*a));
}


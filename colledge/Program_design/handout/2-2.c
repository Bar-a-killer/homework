#include<stdio.h>
int main() 
{ 
    int n,k,m; 

    scanf("%d",&k); 

    while (k > 0) { 
        scanf("%d%d",&n,&m);
        int ans = 1;
        while(n--) {
            ans = (ans * (n+1)) % m;
        }
        printf("%d\n",ans);
        k = k - 1; 
    } 
    return 0; 
}  
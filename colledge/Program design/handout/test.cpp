#include<stdio.h>
long long unsigned s = 0;
long long unsigned f(int n)
{
    s++;
    long long unsigned r = 0;
    int i;
    if (n<=1) {// base case
        return 1;
    }
    for(r = 0, i = 0; i <= n-1; ++i) {
        r += f(i)*f(n-1-i);
    }

    return r;
}
int main()
{
    long long unsigned r = f(21);
    printf("%llu\n",r);
    printf("%llu\n",s);
    return 0;
}

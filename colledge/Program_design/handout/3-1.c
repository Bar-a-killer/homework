#include <stdio.h>
#include <math.h>
int check(int n,int max) {
    if(n%105==53 && max - n >= 105) {
        return 3;
    } else if(n%15==8 && max - n >= 15) {
        return 2;
    } else if(n%3==2 && max - n >= 3) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    int n,tag_1,tag_2,tag_3,tag_4;
    scanf("%d",&n);
    scanf("%d %d %d %d",&tag_1,&tag_2,&tag_3,&tag_4);
    int white,blue,red,green;
    white = n/3*2 + n%3;
    red = n/3/5*4 + n/3%5;
    blue = n/3/5/7*6 + n/3/5%7;
    green = n/3/5/7;
    char out[4][10] = {"white","red","blue","green"};
    printf("%d,%d,%d,%d\n",white,red,blue,green);
    printf("%s,%s,%s,%s\n",out[check(tag_1,n)],out[check(tag_2,n)],out[check(tag_3,n)],out[check(tag_4,n)]);
    
    return 0;
}

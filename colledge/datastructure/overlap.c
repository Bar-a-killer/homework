#include <stdio.h>
int min(int a, int b) {
    return a < b ? a : b;
}   
int main() {
    int x_1, y_1, u_1 , v_1;
    int x_2, y_2, u_2 , v_2;
    scanf("%d%d%d%d",&u_1,&v_1,&x_1,&y_1);
    scanf("%d%d%d%d",&u_2,&v_2,&x_2,&y_2);
    int ovh = 0, ovw = 0;
    if(u_1 < u_2 && x_1 > u_2) { /* 1 2 1 2 || 1 2 2 1*/
        ovw = min(x_2 - u_2, x_1 - u_2);
    } else if(u_1 > u_2 && x_1 > u_1) { /* 2 1 2 1 || 2 1 1 2*/
        ovw = min(x_1 - u_1, x_2 - u_1);
    }
    if(v_1 > v_2 && y_1 < v_2) { /* 1 2 1 2 || 1 2 2 1*/
        ovh = min(v_2 - y_2, v_2 - y_1);
    } else if(v_2 > v_1 && v_2 > y_1) { /* 2 1 2 1 || 2 1 1 2*/
        ovh = min(v_1 - y_1, v_1 - y_2);
    }
    printf("%d",ovh*ovw);
    return 0;
}
#include <stdio.h>
float min(float a, float b) {
    return a < b ? a : b;
}   
int main() {
    float h_1, w_1, u_1 , v_1;
    float h_2, w_2, u_2 , v_2;
    scanf("%f%f%f%f",&u_1,&v_1,&w_1,&h_1);
    scanf("%f%f%f%f",&u_2,&v_2,&w_2,&h_2);
    float ovh = 0, ovw = 0;
    if(w_1 + u_1 > u_2 && u_1 < u_2) { /* 1 2 1 2 || 1 2 2 1*/
        ovw = min(w_2, w_1 + u_1 - u_2);
    } else if(w_2 + u_2 < u_1 && u_2 > u_1) { /* 2 1 2 1 || 2 1 1 2*/
        ovw = min(w_1, w_2 + u_2 - u_1);
    }
    if(h_1 + v_1 > v_2 && v_1 < v_2) { /* 1 2 1 2 || 1 2 2 1*/
        ovh = min(h_2, h_1 + v_1 - v_2);
    } else if(h_2 + v_2 < v_1 && v_2 > v_1) { /* 2 1 2 1 || 2 1 1 2*/
        ovh = min(h_1, h_2 + v_2 - v_1);
    }
    printf("%.2f",ovh*ovw/(h_1*w_1 + h_2*w_2 - ovh*ovw));
    return 0;
}
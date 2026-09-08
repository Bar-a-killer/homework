#include <stdio.h>
#define MAX 100
typedef struct {
    float a;
    int xn;
} poly;

void add(poly a[],poly b[],poly c[],int len_a,int len_b,int *len_c) {
    int i = 0,j = 0;
    while(i < len_a && j < len_b) {
        if(a[i].xn > b[j].xn) {
            c[*len_c] = a[i];
            (*len_c)++;
            i++;
        }
        else if(a[i].xn == b[j].xn) {
            c[*len_c] = a[i];
            c[*len_c].a += b[j].a;
            (*len_c)++;
            i++;j++;
        }
        else {
            c[*len_c] = b[j];
            (*len_c)++;
            j++;
        }
    }
    for(;i < len_a;i++) {
        c[*len_c] = a[i];
        (*len_c)++;
    }
    for(;j < len_b;j++) {
        c[*len_c] = b[j];
        (*len_c)++;
    }
}
/*len_c = len_exc_c + 1*/
void copy(poly ans[],poly term_j[],int ans_len,int *j_len) {
    poly tmp;
    for(int i = 0;i < ans_len;i++) {
        if(i < ans_len) {
            term_j[i] = ans[i];
        }
    }
    *j_len = ans_len;
}
int main() {
    poly term[MAX][MAX];
    int i = 0;
    int len[MAX];
    while(scanf("%d",&len[i]) != EOF) {
        for(int j = 0;j < len[i];j++) {
            scanf("%f",&term[i][j].a);
        }
        for(int j = 0;j < len[i];j++) {
            scanf("%d",&term[i][j].xn);
        }
        i++;
    }
    
    int j = 1;
    
    while(j < i) {
        poly answer[MAX];
        int len_c = 0;
        add(term[j],term[j-1],answer,len[j],len[j-1],&len_c);
        copy(answer,term[j],len_c,&len[j]);
        j++;
    }
    j--;
    printf("%d\n", len[j]);
    for(int k = 0;k < len[j];k++) {
        printf("%g ",term[j][k].a);    
    }
    printf("\n");
    for(int k = 0;k < len[j];k++) {
        printf("%d ",term[j][k].xn);    
    }
}
#include <stdio.h>
#include <math.h>   
#define MAX 100
#define EPS 1e-7      

typedef struct {
    float a;  
    int xn;   
} poly;

void add(poly a[], poly b[], poly c[], int len_a, int len_b, int *len_c) {
    int i = 0, j = 0;
    while (i < len_a && j < len_b) {
        if (a[i].xn > b[j].xn) {
            if (fabs(a[i].a) > EPS) c[(*len_c)++] = a[i];
            i++;
        } else if (a[i].xn == b[j].xn) {
            float sum = a[i].a + b[j].a;
            if (fabs(sum) > EPS) {
                c[*len_c] = a[i];
                c[*len_c].a = sum;
                (*len_c)++;
            }
            i++; j++;
        } else {
            if (fabs(b[j].a) > EPS) c[(*len_c)++] = b[j];
            j++;
        }
    }
    for (; i < len_a; i++) if (fabs(a[i].a) > EPS) c[(*len_c)++] = a[i];
    for (; j < len_b; j++) if (fabs(b[j].a) > EPS) c[(*len_c)++] = b[j];
}

void copy(poly ans[], poly term_j[], int ans_len, int *j_len) {
    for (int i = 0; i < ans_len; i++) term_j[i] = ans[i];
    *j_len = ans_len;
}

int main() {
    poly term[MAX][MAX];
    int i = 0;
    int len[MAX];

    while (scanf("%d", &len[i]) != EOF) {
        for (int j = 0; j < len[i]; j++) scanf("%f", &term[i][j].a);
        for (int j = 0; j < len[i]; j++) scanf("%d", &term[i][j].xn);
        i++;
    }

    int j = 1;
    while (j < i) {
        poly answer[MAX];
        int len_c = 0;
        add(term[j], term[j-1], answer, len[j], len[j-1], &len_c);
        copy(answer, term[j], len_c, &len[j]);
        j++;
    }
    j--;

    printf("%d\n", len[j]);

    for (int k = 0; k < len[j]; k++) {
        if (k) putchar(' ');
        printf("%g", term[j][k].a);
    }
    putchar('\n');

    for (int k = 0; k < len[j]; k++) {
        if (k) putchar(' ');
        printf("%d", term[j][k].xn);
    }
    putchar('\n');
}

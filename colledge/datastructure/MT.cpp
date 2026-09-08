#include <stdio.h>
#define MAX 100
typedef struct {
    int row,cal,val;
} term;

void input(term datas[]) {
    scanf("%d%d%d",&datas[0].row,&datas[0].cal,&datas[0].val);
    int n = datas[0].val;
    for(int i = 1;i <= n;i++) {
        scanf("%d%d%d",&datas[i].row,&datas[i].cal,&datas[i].val);
    }
}
void fast_transpose(term a[],term b[]) {
    int row_terms[MAX],starting_pos[MAX];
    int i,j,num_cols = a[0].cal,num_terms = a[0].val;
    b[0].row = num_cols;
    b[0].cal = a[0].row;
    b[0].val = num_terms;
    if(num_terms > 0) {
        for(i = 0;i < num_cols;i++) row_terms[i] = 0;
        for(i = 1;i <= num_terms;i++) row_terms[a[i].cal]++;
        starting_pos[0] = 1;
        for(i = 1;i < num_cols;i++) starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
        for(i = 1;i <= num_terms;i++) {
            j = starting_pos[a[i].cal]++;
            b[j].row = a[i].cal;
            b[j].cal = a[i].row;
            b[j].val = a[i].val;
        }
    }
}
void print(term datas[]) {
    int n = datas[0].val;
    printf("%d %d %d\n",datas[0].row,datas[0].cal,datas[0].val);
    for(int i = 1;i <= n;i++) {
        printf("%d %d %d\n",datas[i].row,datas[i].cal,datas[i].val);
    }
}

int main() {
    term datas[MAX],answers[MAX];
    input(datas);
    fast_transpose(datas,answers);
    printf("After fast transpose:\n");
    print(answers);
    return 0;

}
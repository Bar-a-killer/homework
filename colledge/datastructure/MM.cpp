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
void give_id(term a[], int n,int row,int cal,int val) {
    a[n].row = row;
    a[n].cal = cal;
    a[n].val = val;
}
void mat_multi(term a[],term b[],term c[]) {
    if(a[0].cal != b[0].row) {
        printf("incompatible matrices\n");
        return;
    }
    term newb[MAX];
    fast_transpose(b,newb);
    a[a[0].val+1].row = a[0].row;
    newb[b[0].val+1].row = b[0].cal;
    newb[b[0].val+1].cal = -1;
    give_id(c,0,a[0].row,b[0].cal,0);
    int i,j;
    int cal,row = a[1].row;
    int c_pos = 1,sum = 0,row_begin = 1;
    
    
    for(int i = 1;i <= a[0].val;) { 
        cal = newb[1].row;
        for(int j = 1;j <= b[0].val+1;) {
            if(a[i].row != row) {
                if(sum != 0) {
                    give_id(c,c_pos++,row,cal,sum);
                    sum = 0;
                }
                while(newb[j].row == cal) j++;
                i = row_begin;
                cal = newb[j].row;
            }
            else if (newb[j].row != cal) {
                if(sum != 0) {
                    give_id(c,c_pos++,row,cal,sum);
                    sum = 0;
                }
                cal = newb[j].row;
                i = row_begin;
            }
            else {
                if(a[i].cal == newb[j].cal) {
                    sum += a[i].val * newb[j].val;
                    i++;j++;
                } 
                else if(a[i].cal < newb[j].cal) {
                    i++;
                }
                else {
                    j++;
                }
            }
        }
        while(a[i].row == row) i++;
        row_begin = i;
        row = a[i].row;
    }
    c[0].val = c_pos - 1;
    c[0].row = a[0].row;
    c[0].cal = b[0].cal;
}

int main() {
    term datas_1[MAX],datas_2[MAX],answers[MAX];
    input(datas_1);
    input(datas_2);
    mat_multi(datas_1,datas_2,answers);
    print(answers);
    return 0;
}
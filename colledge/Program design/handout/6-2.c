#include <stdio.h>
#include <stdlib.h>
int main() {
    long long *title = malloc(sizeof(long long) * 500001);
    title[1] = 1;
    long long i;
    for(i = 2;title[i-1] <= 50000000000;i++) {
        
        if(i >= 500000) {
            printf("error\n");
            return 0;
        }
        title[i] = title[i-1]+i;
    }
    long long x,y;
    while(scanf("%lld", &x) != EOF) {
        if(x == 1) {
            printf("2,3\n");
            continue;
        }
        long long l = 0, r = i-1, mid;
        long long head;
        while(l < r) {
            mid = (l + r) / 2;
            if(title[mid] >= x && x > title[mid-1]) {
                head = title[mid];
                break;
            }
            if(title[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        long long top, left, right, bottom;
        if(mid % 2 == 1) {
            bottom = title[mid+1] - (x - head);
            top = head - 1 -(x - head);
            left = top + 1;
            right = bottom - 1;
        } else {
            top = title[mid-1] + (head - x);
            bottom = head + 1 + (head - x);
            right = bottom + 1;
            left = top - 1;
        }
        int len=0;
        long long ans[4]={0};
        int first = 1;
        if(left >= title[mid-1] - mid +2 && left <= title[mid-1]) {
            ans[len++] = left;
        }
        if(top >= title[mid-1] - mid + 2 && top <= title[mid-1]) {
            ans[len++] = top;
        }
        if(right > title[mid] && right <= title[mid+1]) {
            ans[len++] = right;
        }
        if(bottom > title[mid] && bottom <= title[mid+1]) {
            ans[len++] = bottom;
        }
        for(int j = 0; j < len; j++) {
            for(int k = j + 1; k < len; k++) {
                if(ans[j] > ans[k]) {
                    long long temp = ans[j];
                    ans[j] = ans[k];
                    ans[k] = temp;
                }
            }
        }
        for(int j = 0; j < len; j++) {
            if(first) {
                printf("%lld", ans[j]);
                first = 0;
            } else {
                printf(",%lld", ans[j]);
            }
        }
        printf("\n");
    }
}
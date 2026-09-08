#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    while (scanf("%lf %lf", &a, &b) == 2) {
        int left  = (int)ceil(200 * log(a));
        int right = (int)floor(200 * log(b));
        int count = 0;
        if (left <= right) {
            count = right - left + 1;
        }
        printf("%d\n", count);
    }
    return 0;
}

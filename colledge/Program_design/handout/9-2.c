#include <stdio.h>
#include <stdlib.h>
int main() {
    char tmp;
    int state = 0;
    int alpha = 0;
    while(scanf("%c",&tmp) != EOF) {
        if((state == 1 || state == 2) && tmp == 'y') {
            if(state == 1)
                state = 3;
            else
                state = 4;
            continue;
        }
        else if(!alpha && state == 0 && tmp == 'm') {
            state = 1;
            continue;
        }
        else if(!alpha && state == 0 && tmp == 'M') {
            state = 2;
            continue;
        }

        if((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z')) {
            alpha = 1;
            if(state == 3) {
                printf("my");
            }
            else if(state == 4) {
                printf("My");
            }
            if(state == 1) {
                printf("m");
            }
            else if(state == 2) {
                printf("M");
            }
            state = 0;
        }
        else {
            alpha = 0;
            if(state == 3) {
                printf("your");
            }
            else if(state == 4) {
                printf("Your");
            }
            if(state == 1) {
                printf("m");
            }
            else if(state == 2) {
                printf("M");
            }
            state = 0;
        }
        
        printf("%c",tmp);
    }
    if(state == 3) {
        printf("your");
    }
    else if(state == 4) {
        printf("Your");
    }
    else if(state == 1) {
        printf("m");
    }
    else if(state == 2) {
        printf("M");
    }
}
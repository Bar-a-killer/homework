#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Hello, World!\n");
    int i;
    scanf("%d",&i);
    printf("%d\n",i++ + ++i);
    system("pause");
    return 0;
}

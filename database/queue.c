#include <stdio.h>
#include <stdlib.h>

int n;
int next(int current) {
    return (current + 1) % n;
}
void enqueue(int *queue, int *rear, int front, int value) {
    if (next(*rear) == front) {
        printf("FULL\n");
        return;
    }
    queue[next(*rear)] = value;
    (*rear) = next(*rear);
}
int dequeue(int *queue, int *front, int rear) {
    if (*front == rear) {
        return -1;
    }
    int value = queue[next(*front)];
    (*front) = next(*front);
    return value;
}
int main() {
    scanf("%d", &n);
    //n++; //兩筆測資對n得定義不同 第一筆不須執行此行 第二筆須執行此行
    int *queue = (int *)malloc((n) * sizeof(int));
    int front = 0, rear = 0;
    int tmp;
    scanf("%d", &tmp);
    while (tmp != -1) {
        if(tmp == 0) {
            int value = dequeue(queue, &front, rear);
            if(value != -1) {
                printf("%d\n", value);
            }
            else {
                printf("EMPTY\n");
            }
        }
        else if(tmp == 1) {
            int value;
            scanf("%d", &value);
            enqueue(queue, &rear, front, value);
        }
        scanf("%d", &tmp);
    }
}

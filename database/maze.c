#include <stdio.h>
#include <stdlib.h>
void push(int stack[][2], int *top, int x, int y) {
    stack[++(*top)][0] = x;
    stack[*top][1] = y;
}
int pop(int stack[][2], int *top, int *x, int *y) {
    if (*top == -1) {
        return 0; 
    }
    *x = stack[*top][0];
    *y = stack[*top][1];
    (*top)--;
    return 1; 
}
int top_val(int stack[][2], int top, int *x, int *y) {
    if (top == -1) {
        return 0; 
    }
    *x = stack[top][0];
    *y = stack[top][1];
    return 1; 
}
void print_maze(int maze[][100], int n, int m,int lox, int loy) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == lox && j == loy) {
                printf("X ");
                continue;
            }
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    int maze[100][100];
    int visited[100][100] = {0};
    int n, m;
    int pos[8][2] = {
        {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}
    };
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    int start_x, start_y;
    scanf("%d %d", &start_x, &start_y);
    int end_x, end_y;
    scanf("%d %d", &end_x, &end_y);
    int stack[10000][2];
    int top = -1;
    push(stack, &top, start_x, start_y);
    visited[start_x][start_y] = 1;
    int find = 0;
    while(top != -1) {
        int x, y;
        top_val(stack,top,&x,&y);
        for (int i = 0; i < 8; i++) {
            int new_x = x + pos[i][0];
            int new_y = y + pos[i][1];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m &&
                maze[new_x][new_y] == 0 && visited[new_x][new_y] == 0) {
                push(stack, &top, new_x, new_y);
                visited[new_x][new_y] = 1;
                if (new_x == end_x && new_y == end_y) {
                    find = 1;
                    for(int j = 0; j <= top; j++) {
                        int px, py;
                        px = stack[j][0];
                        py = stack[j][1];
                        printf("(%d,%d)", px, py);
                        if(j != top) {
                            printf(" ");
                        }
                    }
                    return 0;
                }
                //print_maze(maze, n, m, new_x, new_y);
                break;
            }
            else if(i == 7) {
                pop(stack, &top, &x, &y);
            }
        }
    }
    if(!find) {
        printf("None\n");
    }
}
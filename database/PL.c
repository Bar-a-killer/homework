#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
} node;
int main() {
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;
    head->data = 0;
    node *now = head;
    int tmp;
    char ch;
    while(scanf("%d%c", &tmp,&ch) != EOF) {
        now->next = (node*)malloc(sizeof(node));
        now = now->next;
        now->data = tmp;
        now->next = NULL;
        if(ch == '\n') {
            break;
        }
    }
    int split = now->data;
    node *big_head = (node*)malloc(sizeof(node));
    big_head->next = NULL;
    big_head->data = 0;
    node *small_head = (node*)malloc(sizeof(node));
    small_head->next = NULL;
    small_head->data = 0;
    node *big_now = big_head;
    node *small_now = small_head;
    now = head;
    now = now->next;
    while(now != NULL && now->next != NULL) {
        node *nextNode = now->next;
        now->next = NULL;
        if(now->data >= split) {
            big_now->next = now;
            big_now = big_now->next;
        } else {
            small_now->next = now;
            small_now = small_now->next;
        }
        now = nextNode;
    }
    small_now->next = big_head->next;
    now = small_head;
    while(now->next != NULL) {
        now = now->next;
        printf("%d", now->data);
        if (now->next != NULL)
        {
            printf(" ");
        }
    }
}
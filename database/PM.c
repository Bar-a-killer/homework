#include<stdio.h>
#include<stdlib.h>
typedef struct p_node {
    float coef;
    int exp;
    struct p_node* next;
} p_node;

void input_poly(int len1, int len2, p_node *now1, p_node *now2) {
    scanf("%d", &len1);
    p_node *head1 = now1;
    p_node *head2 = now2;
    for(int i = 0;i < len1;i++) {
        now1->next = (p_node*)malloc(sizeof(p_node));
        now1 = now1->next;
        scanf("%f", &now1->coef);
        now1->next = NULL;
    }
    now1 = head1;
    for(int i = 0;i < len1;i++) {
        now1 = now1->next;
        scanf("%d", &now1->exp);
    }
    now1 = head1;
    scanf("%d", &len2);
    for(int i = 0;i < len2;i++) {
        now2->next = (p_node*)malloc(sizeof(p_node));
        now2 = now2->next;
        scanf("%f", &now2->coef);
        now2->next = NULL;
    }
    now2 = head2;
    for(int i = 0;i < len2;i++) {
        now2 = now2->next;
        scanf("%d", &now2->exp);
    }
    now2 = head2;
}

void insert_poly(p_node *poly, int coef, float exp) {
    p_node *now = poly;
    while(now->next != NULL && now->next->exp > exp) {
        now = now->next;
    }
    if(now->exp == exp) {
        now->coef += coef;
    } else {
        p_node *newNode = (p_node*)malloc(sizeof(p_node));
        newNode->coef = coef;
        newNode->exp = exp;
        newNode->next = now->next;
        now->next = newNode;
    }
}

void output_poly(p_node *poly) {
    p_node *now = poly->next;
    int cnt = 0;
    while(now != NULL) {
        if(now->coef != 0) {
            cnt++;
        }
        now = now->next;
    }
    printf("%d\n", cnt);
    now = poly->next;
    while(now != NULL) {
        if(now->coef != 0) {
            printf("%g", now->coef);
            if(now->next != NULL) {
                printf(" ");
            }
        }
        now = now->next;
    }
    printf("\n");
    now = poly->next;
    while(now != NULL) {
        if(now->coef != 0) {
            printf("%d", now->exp);
            if(now->next != NULL) {
                printf(" ");
            }
        }
        now = now->next;
    }
    printf("\n");
}
int main() {
    p_node *m1 = (p_node*)malloc(sizeof(p_node));
    p_node *m2 = (p_node*)malloc(sizeof(p_node));
    m1->next = NULL;
    m2->next = NULL;

    int len1 = 0, len2 = 0;
    input_poly(len1, len2, m1, m2);
    //output_poly(m1);
    //output_poly(m2);
    p_node *ans = (p_node*)malloc(sizeof(p_node));
    ans->next = NULL;

    for(p_node *p = m2->next;p != NULL;p = p->next) {
        for(p_node *q = m1->next;q != NULL;q = q->next) {
            insert_poly(ans, p->coef * q->coef, p->exp + q->exp);
        }
    }

    output_poly(ans);
    return 0;
}
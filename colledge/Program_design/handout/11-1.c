#include <stdio.h>
struct record {
    char msg[8];
    unsigned next;
} ;
int main() {
    char name[100];
    scanf("%s", name);
    FILE *fp = fopen(name, "rb");
    if (fp == NULL) {
        printf("%s not found\n", name);
        return 1;
    }
    int first;
    struct record rec;
    fread(&first, sizeof(first), 4, fp);
    int cur = first;

    while (cur != 0) {
        fseek(fp, sizeof(int) + (cur - 1) * sizeof(struct record), SEEK_SET);
        fread(&rec, sizeof(struct record), 1, fp);

        printf("%s\n", rec.msg);
        cur = rec.next;
    }
}
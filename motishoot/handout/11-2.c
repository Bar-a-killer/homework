// set the value for the ith bit 

void setbit(unsigned char bitstream[], int size, int i, int value);

// get the value of the ith bit 

int getbit(const unsigned char bitstream[], int size, int i);

 

//程式藍色部分不要改。
// does not modify any blue character.

#include<stdio.h>

#define SIZE 10
unsigned char bitstreams[SIZE];

// set the value for the ith bit

void setbit(unsigned char bitstream[], int size, int i, int value)
{
    bitstream[i/8] &= ~(1 << (i % 8));
    bitstream[i/8] |= (value << (i % 8));
}

// get the value of the ith bit
int getbit(const unsigned char bitstream[], int size, int i)
{
    return (bitstream[i/8] >> (i % 8)) & 1;
}

int main(void)
{

    int i,v;  

    scanf("%d%d",&i,&v);

    while(i != -1) {
         setbit(bitstreams,SIZE,i,v);
         scanf("%d%d",&i,&v);
    }

    for(i = 0; i < SIZE; ++i) printf("%02x",bitstreams[i]);

    printf("\n");

    scanf("%d",&i);

    while(i != -1) {
         printf("%d\n",getbit(bitstreams,SIZE,i));
         scanf("%d",&i);
    }

    return 0;
}
#include<stdio.h>

int main()
{
	int n1=2,n2=3;
	float landa;
	while(1){
		landa=91.2*n1*n1*n2*n2/(n2*n2-n1*n1);
		if(landa<700&&landa>400)
		{
			printf("%d : %f\n",n2,landa);
			n2++;
		}
		else{
			printf("ans : %f",landa);
			break;
		}
	}
	
	
} 

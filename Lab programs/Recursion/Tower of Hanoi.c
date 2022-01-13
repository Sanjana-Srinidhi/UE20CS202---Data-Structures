#include <stdio.h>
void tower(int n,char a,char b,char c);

int i=0;

int main() 
{
	int n;
	printf("Enter the number of discs: ");
	scanf("%d",&n);
	tower(n,'A','B','C');
	printf("Number of moves taken: %d\n",i);
    return 0;
}

void tower(int n,char a,char b,char c)
 {
	if (n == 1) 
	{
		i++;
		printf("Move the disc from %c to %c\n",a, c);
    }
	else 
	{
		tower(n - 1,a,c,b);	
		tower(1,a,b,c);
		tower(n - 1,b,a,c);
   }    
}
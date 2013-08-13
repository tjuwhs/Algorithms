/*
	3484 source code
	acm.tju.edu.cn
*/


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *array;
	int test;
	scanf("%d\n",&test);
	while(test>0)
	{
		int n;
		scanf("%d\n",&n);
		array=(int *)malloc(sizeof(int)*n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
		}
		int largest=array[0];
		int result=0;
		for(i=1;i<n;i++)
		{
			if(array[i]>largest)
			{
				result+=largest;
				largest=array[i];
			}
			else
				result+=array[i];
		}
		printf("%d\n",result);
		free(array);
		test--;
	}
}

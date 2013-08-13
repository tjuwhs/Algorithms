/*
	3515 source code 
	acm.tju.edu.cn
*/

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>


void Insert(int *array,int key,int size)
{
	int i;
	for(i=size-1;i>=0 && array[i]>key;i--)
	{
		array[i+1]=array[i];
	}
	array[i+1]=key;
}

int main()
{
	int test;
	int *array;
	scanf("%d\n",&test);
	array=(int *)malloc(sizeof(int)*(110000));
	while(test>0)
	{
		int n;
		scanf("%d\n",&n);
		int i;
		int size=n;
		for(i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
		}
		std::sort(array,array+n);
		int m;
		scanf("%d\n",&m);
		while(m>0)
		{
			char c[4];
			scanf("%s",c);
			if(strcmp(c,"add")==0)
			{
				int key;
				scanf("%d\n",&key);
				Insert(array,key,size);
				size++;
				m--;
			}
			if(strcmp(c,"mid")==0)
			{
				int mid=size/2;
				if(size%2==0)
				{
					printf("%d\n",(array[mid-1]<array[mid]?array[mid-1]:array[mid]));
				}
				else
				{
					printf("%d\n",array[mid]);
				}
				m--;
			}
		}
		test--;
	}
	free(array);
}

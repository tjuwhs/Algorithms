/*
	归并排序代码
*/
#include <stdio.h>
#include <stdlib.h>

void Merge(int *array,int p,int q,int r)
{
	int *tmp;
	int i,j,k;
	tmp=(int *)malloc(sizeof(int)*(r-p));
	for(k=0,i=p,j=q+1;;k++)
	{	
		if(i<=q&&j<=r)
		{
			if(array[i]<=array[j]){
				tmp[k]=array[i];
				i++;
			}
			else{	
				tmp[k]=array[j];
				j++;
			}
		}
		else if(i>q&&j<=r)
		{
			tmp[k]=array[j];
			j++;
		}
		else if(i<=q&&j>r)
		{
			tmp[k]=array[i];
			i++;
		}
		else
		{break;}
	}

	for(i=p,j=0;i<=r;i++,j++)
	{
		array[i]=tmp[j];
	}
	free(tmp);
}
void MergeSort(int *array,int left, int right)
{
	if(left<right){
		MergeSort(array,left,(left+right)/2);
		MergeSort(array,(left+right)/2+1,right);
		Merge(array,left,(left+right)/2,right);
	}
}


int main()
{
	int array[10];
	int i,j;
	printf("请输入10个数字:");
	for(i=0;i<10;i++)
	{
		scanf("%d",&array[i]);
	}
	MergeSort(array,0,9);
	printf("正确排序：");
	for(i=0;i<10;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}	

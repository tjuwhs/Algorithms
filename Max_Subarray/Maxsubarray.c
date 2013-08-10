/*
	Find the Maximum Subarray
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Triple{
	int left;
	int right;
	int sum;
};

struct Triple Find_Max_Cross_Subarray(int *array,int low,int mid,int high)
{
	int left_sum=INT_MIN;
	int right_sum=INT_MIN;
	int sum=0;
	int i,j;
	int max_left,max_right;
	for(i=mid;i>=low;i--)
	{
		sum=sum+array[i];
		if(sum>left_sum)
		{
			left_sum=sum;
			max_left=i;
		}		
	}
	
	sum=0;
	for(i=mid+1;i<=high;i++)
	{
		sum=sum+array[i];
		if(sum>right_sum)
		{
			right_sum=sum;
			max_right=i;
		}
	}

	struct Triple tmp;
	tmp.left=max_left;
	tmp.right=max_right;
	tmp.sum=right_sum+left_sum;
	return tmp;
}

struct Triple Find_Max_Subarray(int *array,int low,int high)
{
	if(low==high)
	{
		struct Triple tmp;
		tmp.left=low;tmp.right=high;tmp.sum=array[low];
		return tmp;
	}

	else
	{
		struct Triple tmp_left,tmp_right,tmp_cross;
		int mid=(low+high)/2;
		tmp_left=Find_Max_Subarray(array,low,mid);
		tmp_right=Find_Max_Subarray(array,mid+1,high);
		tmp_cross=Find_Max_Cross_Subarray(array,low,mid,high);
		if(tmp_left.sum>=tmp_right.sum && tmp_left.sum>=tmp_cross.sum)
			return tmp_left;
		else if(tmp_right.sum>=tmp_left.sum && tmp_right.sum>=tmp_cross.sum)
			return tmp_right;
		else 	
			return tmp_cross;
	}
}


int main(int argc,char *argv[])
{
	int num,i;
	printf("数组的大小：");
	scanf("%d",&num);

	int *array;
	array=(int *)malloc(sizeof(int)*num);
	printf("输入数组：");
	for(i=0;i<num;i++)
	{
		scanf("%d",&array[i]);
	}

	struct Triple tmp;
	tmp=Find_Max_Subarray(array,0,num-1);
	printf("最大子数组的下界 %d 上界 %d 和 %d\n",tmp.left,tmp.right,tmp.sum);
}

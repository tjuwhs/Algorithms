/*
	HeapSort source code
*/

#include <stdio.h>
#include <stdlib.h>


#define Parent(i) (i-1)/2
#define Left(i)  2*i+1
#define Right(i) 2*i+2


void Heapify(int *array,int i,int size)
{
	int left,right,largest;
	left=Left(i);
	right=Right(i);
	if(left<size && array[left]>array[i])
		largest = left;
	else
		largest = i;

	if(right < size && array[right]>array[largest])
		largest = right;

	if(largest != i)
	{
		int tmp=array[i];
		array[i]=array[largest];
		array[largest]=tmp;
		Heapify(array,largest,size);
	}
}

void BuildHeap(int *array,int size)
{
	int i;
	for(i=(size-1)/2;i>=0;i--)
		Heapify(array,i,size);
}

void HeapSort(int *array,int size)
{
	int heapsize,length,i;
	BuildHeap(array,size);
	heapsize=length=size;

	for(i=length-1;i>0;i--)
	{
		int tmp=array[0];
		array[0]=array[i];
		array[i]=tmp;
		heapsize=heapsize-1;
		Heapify(array,0,heapsize);
	}
}


int main(int argc,char* argv[])
{
	int array[10];
	int i,j;
	for(i=0;i<10;i++)
	{
		scanf("%d",&array[i]);
	}
	HeapSort(array,10);

	for(i=0;i<10;i++)
		printf("%d ",array[i]);
	printf("\n");
}

	

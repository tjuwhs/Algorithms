/*
	3488:Stone II
	
	Huffman tree
*/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>


struct Heap{
	int size;
	int *array;
};

void Heapify(struct Heap *a,int i)
{
	int largest;
	int left,right;
	left=2*i+1;
	right=2*i+2;
	largest=i;
	if(a->array[left]<a->array[largest]&&left<a->size)
		largest=left;
	if(a->array[right]<a->array[largest]&&right<a->size)
		largest=right;

	if(largest!=i){
		int tmp=a->array[i];
		a->array[i]=a->array[largest];
		a->array[largest]=tmp;
		Heapify(a,largest);
	}

}
int Heap_Extract_Min(struct Heap *a)
{
	int min;
	min=a->array[0];
	a->array[0]=a->array[a->size-1];
	a->size--;
	Heapify(a,0);
	return min;
}


void Insert(struct Heap *a,int k)
{
	a->size++;
	a->array[a->size-1]=k;
	int i;
	for(i=a->size-1;i>=0&&a->array[(i-1)/2]>a->array[i];)
	{
		int tmp=a->array[i];
		a->array[i]=a->array[(i-1)/2];
		a->array[(i-1)/2]=tmp;
		i=(i-1)/2;
	}	
}


int main()
{
	int t;
	scanf("%d\n",&t);
	while(t>0)
	{
		int n;
		scanf("%d\n",&n);
		int i,j;
		struct Heap a;
		a.array=(int *)malloc(sizeof(int)*n);
		a.size=0;
		int result,left,right;
		result=0;
		for(i=0;i<n;i++)
		{
			int size;
			scanf("%d",&size);
			Insert(&a,size);
		}
		for(i=0;i<n-1;i++)
		{
			left=Heap_Extract_Min(&a);
			right=Heap_Extract_Min(&a);
			int freq;
			freq=left+right;
			result+=freq;
			Insert(&a,freq);
		}
		printf("%d\n",result);
		free(a.array);
		t--;
	}
}

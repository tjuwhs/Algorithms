/*
	web site:
		http://acm.tju.edu.cn
	question id:
		2196

	use the min heap to slove the problem
*/

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
	int n;
	while(scanf("%d",&n))
	{
		char tmp;scanf("%c",&tmp);
		if(n==0)	break;

		else
		{
			char s;int key;
			struct Heap a;
			a.array=(int *)malloc(sizeof(int)*n);
			a.size=0;
			while(n>0)
			{
				scanf("%c",&s);
				if(s=='B')
				{
					scanf("%d\n",&key);
					Insert(&a,key);
					n--;	
				}
				if(s=='G')
				{
					scanf("%c",&tmp);
					int give=Heap_Extract_Min(&a);
					printf("%d\n",give);
					n--;
				}
			}
			free(a.array);
		}
	}
}

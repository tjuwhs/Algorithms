/*
	ID: 3581
	web:acm.tju.edu.cn
*/

#include <stdio.h>
#include <stdlib.h>

struct Toy{
	int joy;
	int price;
	float hfm;
};
int main()
{
	int n;
	scanf("%d\n",&n);
	struct Toy *b;
	b=(struct Toy*)malloc(sizeof(struct Toy)*n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&b[i].joy,&b[i].price);
		b[i].hfm=(float)b[i].joy/(float)b[i].price;
	}

	int large,mid,small;
	if(b[0].hfm>b[1].hfm && b[0].hfm>b[2].hfm)
	{
		large=0;
		if(b[1].hfm>b[2].hfm){mid =1;small=2;}
		else {mid=2;small=1;}
	}
	else if(b[1].hfm>b[0].hfm && b[1].hfm>b[2].hfm)
	{
		large=1;
		if(b[0].hfm>b[2].hfm) {mid=0;small=2;}
		else {mid =2; small=0;}
	}
	else
	{
		large=2;
		if(b[0].hfm>b[1].hfm){mid =0; small=1;}
		else {mid=1;small=0;}
	}

	for(i=3;i<n;i++)
	{
		if(b[i].hfm>=b[large].hfm)
		{
			small=mid;mid=large;large=i;
		}
		else if(b[i].hfm >= b[mid].hfm && b[i].hfm<b[large].hfm)
		{
			small = mid;mid = i;
		}

		else if(b[i].hfm >= b[small].hfm && b[i].hfm<b[mid].hfm)
		{
			small = i;
		}
	}

	printf("%d\n",b[large].price+b[mid].price+b[small].price);
	printf("%d\n",large+1);
	printf("%d\n%d\n",mid+1,small+1);
}

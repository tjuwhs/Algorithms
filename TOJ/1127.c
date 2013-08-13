/*
	ID:1127
	Web:acm.tju.edu.cn
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
struct DNA{
	int measure;
	char s[51];
	bool out;
};

int main()
{
	int n,m;
	scanf("%d%d\n",&n,&m);
	int i,j,k;
	struct DNA *d;
	int *array;
	d=(struct DNA *) malloc(sizeof(struct DNA)*m);
	array=(int *)malloc(sizeof(int)*m);
	for(i=0;i<m;i++)
	{
		scanf("%s",d[i].s);
		d[i].measure=0;
		d[i].out=false;
		for(j=0;j<n;j++)
			for(k=j+1;k<n;k++)
				if(d[i].s[k]<d[i].s[j]) d[i].measure++;
		array[i]=d[i].measure;
	}

	std::sort(array,array+m);
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			if(array[i]==d[j].measure && !d[j].out)
			{
				printf("%s\n",d[j].s);
				d[j].out=true;
			}
		}
	}	
}

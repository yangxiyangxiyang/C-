#include<stdio.h>
#include<string.h>
#define NUM 2
struct census {
			char	a[20];
			int		b;
			float	c;
	} ;
void city_name (census *s)
{
	int i=0,k;
	char city_name[10];
	while(i<NUM-1)
	{
		k=0;
		while(k<NUM-1-i)
		{
			if(strcmp((*(s+k)).a,(*(s+k+1)).a)>0)
			{
				strcpy(city_name,(*(s+k)).a);
				strcpy((*(s+k)).a,(*(s+k+1)).a);
				strcpy((*(s+k+1)).a,city_name);
			}
			k++;
		}
		i++;
	}
}
void city_people (census *d)
{
	int i=0,k,t;
	while(i<NUM-1)
	{
		k=0;
		while(k<NUM-1-i)
		{
			if((*(d+k)).b>(*(d+k+1)).b)
			{
				t=(*(d+k)).b;
				(*(d+k)).b=(*(d+k+1)).b;
				(*(d+k+1)).b=t;
			}
			k++;
		}
		i++;
	}
}
void city_civilization (census *f)
{
	int i=0,k;
	float t;
	while(i<NUM-1)
	{
		k=0;
		while(k<NUM-1-i)
		{
			if((*(f+k)).c>(*(f+k+1)).c)
			{
				t=(*(f+k)).c;
				(*(f+k)).c=(*(f+k+1)).c;
				(*(f+k+1)).c=t;
			}
			k++;
		}
		i++;
	}
}
void main(void)
{/*typedef struct {
			char	a[20];
			int		b;
			float	c;
	} census;
	census x[NUM],*y;*/
	census x[NUM],y[NUM];
	char city[10];
	int i=0,k=0;
	while(i<NUM)
	{
		printf("请输入城市名：");
		scanf("%s",&x[i].a);strcpy(y[i].a,x[i].a);
		printf("请输入城市人口数：");
		scanf("%d",&x[i].b);y[i].b=x[i].b;
		printf("请输入城市文明度（小数）：");
		scanf("%f",&x[i].c);y[i].c=x[i].c;
		i++;
	}
	printf("按城市名排名分布\n");
	city_name(x);
	for(i=0;i<NUM;i++)
	{
		for(k=0;k<NUM;k++)
		{
			if(strcmp(x[k].a,y[i].a)==0){printf("%s\t%d\t%f\n",y[k].a,y[k].b,y[k].c);}
		}
	}
	printf("按城市人口排名\n");
	city_people(x);
	for(i=0;i<NUM;i++)
	{
		for(k=0;k<NUM;k++)
		{
			if(x[k].b==y[i].b){printf("%s\t%d\t%f\n",y[k].a,y[k].b,y[k].c);}
		}
	}
	printf("按城市文明度分布\n");
	city_civilization(x);
	for(i=0;i<NUM;i++)
	{
		for(k=0;k<NUM;k++)
		{
			if(x[k].c==y[i].c){printf("%s\t%d\t%f\n",y[k].a,y[k].b,y[k].c);}
		}
	}
}

		




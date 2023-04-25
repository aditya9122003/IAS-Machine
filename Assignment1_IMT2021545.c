#include<stdio.h>
int fibo(int n)
{
	int a=0,b=1,c;
	if(n==0)
	{
		return a;
	}
        for(int i=2;i<n+1;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}
int main()
{
	int n,x;
	scanf("%d",&n);
	x=fibo(n);
	printf("%d\n",x);
	return 0;
}

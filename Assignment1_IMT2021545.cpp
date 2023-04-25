#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef long long int li;
li IR=0;
li IBR=0;
li MBR=0;
li MAR=0;
li AC=0;
li MQ=0;

int func(li memory[1000],li PC,int n)
{
	memory[0]=0;
	memory[1]=1;
	memory[PC]=0x0501E15019;
	if(n-2==0)
		memory[30]=memory[n-1];
	else
		memory[30]=memory[n-2];
	while(PC<1000)
	{
		int left=1;
		MAR=PC;
		MBR=*(memory+MAR);
		IBR=MBR%((li) 1<<20);
		IR=MBR>>32;
		MAR=(MBR>>20)%(1<<12);
		goto cases;

	cases:
	switch(IR)
	{
		case 21:// for the command stor m(x)
			*(memory+MAR)=AC;
			break;
		case 5:// for the command add m(x)
			AC=AC+*(memory+MAR);
			break;
		case 7:// for the command add |m(x)|
			if(*(memory+MAR)>0)
			{
				AC=AC+*(memory+MAR);
			}
			else
			{
				AC=AC-*(memory+MAR);
			}
		case 6:// for the command sub m(x)
			AC=AC-*(memory+MAR);
			break;
		case 8:// for the command sub |m(x)|
			if(*(memory+MAR)>0)
			{
				AC=AC-*(memory+MAR);
			}
			else
			{
				AC=AC+*(memory+MAR);
			}
			break;
		case 1:// for the command load m(x)
			AC=*(memory+MAR);
			break;
		case 2:// for the command load -m(x)
			AC=-(*(memory+MAR));
			break;
		case 3:// for the command load |m(x)|
			if(*(memory+MAR)>0)
			{
				AC=*(memory+MAR);
			}
			else
			{
				AC=-(*(memory+MAR));
			}
			break;
		case 4:// for the command load -|m(x)|
			if(*(memory+MAR)>0)
			{
				AC=-(*(memory+MAR));
			}
			else
			{
				AC=(*(memory+MAR));
			}
			break;
		case 10:// for the command load mq
			AC=MQ;
			break;
		case 9:// for the command load mq,m(x)
			MQ=*(memory+MAR);
			break;
	}
	if(left)
	{
		left=0;
		MAR=IBR%(1<<12);
		IR=IBR>>12;
		goto cases;
	}
	memory[n]=memory[25];
	PC++;
	return memory[n];
}
}

int main()
{
	li PC=50;
	int x,y;
	li memory[1000];
	for(int i=0;i<1000;i++)
	{
		memory[i]=0;
	}
	cout<<"Hello this code finds the nth number of a fibonacci sequence. The fibonacci code starts as 1,1,2... and so on"<<endl;
	cout<<"Please enter the nth index: ";
	cin>>x;//to input values
	for(int i=2;i<=x;i++)
	{
		y=func(memory,PC,i);
	}
	cout<<"The "<<x<<"th term of the fibonacci sequence is: "<<y<<endl;
	return 0;
}

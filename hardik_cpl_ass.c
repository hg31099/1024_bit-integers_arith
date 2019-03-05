//----------------------------------------
#include<stdio.h>
#include<string.h>
typedef struct tag{
	char num[309];
}int_1024bit;
typedef enum {F,T} valid;
//helper functions--------------------------
int charToint(char a)
{
	int i;
	i=a-'0';
	return i;
}
//-----------------------------------------
valid checkValidity(char str[])
{
	valid v=T;
	int i=0;	
	while((str[i]!='\0')&&(v==T))
	{
		if((str[i]<'0')||(str[i]>'9'))
			v=F;
		i++;
	}
	return v;
}
//----------------------------------------
int_1024bit reverseStr(int_1024bit str)
{
    	int i,j;
	char temp;
	i = 0;
   	j = strlen(str.num) - 1;
    	while (i < j) {
      		temp = str.num[i];
      		str.num[i] = str.num[j];
      		str.num[j] = temp;
      		i++;
		j--;
   	}
	str.num[strlen(str.num)]='\0';
	return str;
}
//function to add bigints--------------------------------------
int_1024bit Add(int_1024bit num1,int_1024bit num2)
{
	int l1=strlen(num1.num),l2=strlen(num2.num),carry=0,sumi,i;
	int_1024bit sum;
	for(i=0;((i<l1)&&(i<l2));i++)
	{
		sumi=charToint(num1.num[l1-i-1])+charToint(num2.num[l2-i-1])+carry;
		carry=sumi/10;
		sumi=sumi%10;
		sum.num[i]='0'+sumi;
	}
	if(l1==l2 && carry!=0)
	{
		sum.num[i]='0'+carry;
		i++;
	}
	
	int ck=0;
	while(i<l1)
	{
		if(carry==0)		
			sum.num[i]=num1.num[l1-i-1];
		else
		{
			sumi=charToint(num1.num[l1-i-1])+carry;
			carry=sumi/10;
			sumi=sumi%10;
			sum.num[i]='0'+sumi;
			ck=1;
		}
		i++;
	}
	if(ck==1 && carry!=0)
	{
		sum.num[i]='0'+carry;
		i++;
	}
	ck=0;
	while(i<l2)
	{	
		if(carry==0)		
			sum.num[i]=num2.num[l2-i-1];
		else
		{
			sumi=charToint(num2.num[l2-i-1])+carry;
			carry=sumi/10;
			sumi=sumi%10;
			sum.num[i]='0'+sumi;
			ck=1;
		}
		i++;
	}
	if(ck==1 && carry!=0)
	{
		sum.num[i]='0'+carry;
		i++;
	}
	sum.num[i]='\0';
	sum=reverseStr(sum);
	return sum;
}

//function to subtract bigints-----------------------------------	
int_1024bit Sub(int_1024bit n1,int_1024bit n2)
{
	int l1=strlen(n1.num),l2=strlen(n2.num),borrow=0,diffi,i,l,l3,r;
	int_1024bit diff,num1,num2;
	num1=n1;
	num2=n2;
	r=0;
	if(l1==l2)
	r=strcmp(num1.num,num2.num);
	if((l1<l2)||(r<0))
	{
		num1=n2;
		num2=n1;
	}
	l=strlen(num1.num);
	l3=strlen(num2.num);
	for(i=0;(i<l3);i++)
	{
		diffi=charToint(num1.num[l-i-1])-charToint(num2.num[l3-i-1])+borrow;
		if(diffi<0)
		{
			diffi=10+diffi;
			borrow=-1;
		}
		else
			borrow=0;
		diff.num[i]='0'+diffi;
	}
	while(i<l)
	{
		if(borrow==-1)
		{
			diffi=charToint(num1.num[l-i-1])+borrow;
			borrow=0;		
		}
		else
			diffi=charToint(num1.num[l-i-1])+borrow;
		diff.num[i]='0'+diffi;	
		i++;
	}
	if((l1<l2)||(r<0))
	{
		diff.num[i]='-';
		i++;
	}
	diff.num[i]='\0';
	diff=reverseStr(diff);
	return diff;
}
//function to multiply bigints---------------------------------
int_1024bit Mul(int_1024bit num1,int_1024bit num2)
{
	int i,j,l1,l2,pro,t,carry;
	l1=strlen(num1.num);
	l2=strlen(num2.num);
	int_1024bit temp,result;
	result.num[0]='\0';
	for(i=0;i<l2;i++)
	{	
		carry=0;
		for(t=0;t<i;t++)
		{
			temp.num[t]='0';
		}
		for(j=0;j<l1;j++)
		{
			pro=charToint(num2.num[l2-i-1])*charToint(num1.num[l1-j-1])+carry;
			temp.num[j+t]='0'+pro%10;
			carry=pro/10;
		}
		if(carry!=0)
		{
			temp.num[j+t]='0'+carry;
			j++;
		}
		temp.num[j+t]='\0';
		temp=reverseStr(temp);
		//printf("%s\n",temp.num);
		result=Add(result,temp);
		//printf("*%s\n",result.num);
	}
	return result;
}

//main driver function-----------------------------------
void main()
{
	int choice;	
	int_1024bit num1,num2,sum,product,difference;
	printf("Enter first number\n");
	scanf("%s",num1.num);
	printf("Enter second number\n");
	scanf("%s",num2.num);
	valid v1,v2;
	v1=checkValidity(num1.num);
	v2=checkValidity(num2.num);
	do
	{
	printf("1.Addition\n2.Substraction\n3.Multiplication\n4.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		sum=Add(num1,num2);
		printf("Sum is %s\n",sum.num);
		break;
	
		case 2:
		difference=Sub(num1,num2);
		printf("Difference is %s\n",difference.num);
		break;
		
		case 3:
		product=Mul(num1,num2);
		printf("Product is %s\n",product.num);
		break;
		
		case 4:
		choice=0;
		break;
	}
	}while(choice!=0);
}

//------------------------------------------
	
	

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define max 20
int top=-1;
char s[max];

void push(int x)
{
	if(top==max-1)
	{
		printf("stack overflow \n");
		main();
		exit(0);
	}
	else
	{
		s[++top] = x;
	}
}


char pop()
{
	if(top==-1)
	{
		printf("stack underflow \n");
		main();
		exit(1);
	}
	else
	{
		return s[top--];
	}
}
int operation(int op1 , int op2 , char *operator)
{
	switch(*operator)
	{
		case'+': return(op1+op2);

		case'-': return(op1-op2);

		case'*': return(op1*op2);

		case'/': return(op1/op2);

		case'%': return(fmod(op1,op2));

		case'^': return(pow(op1,op2));

	}
}
void evaluation(char postfix[])
{
	int i,op1,op2,res;
	char *operator;
	for(i=0;postfix[i]!='\0';i++)
	{
		if(isdigit(postfix[i]))
        {
            push(postfix[i]-'0');
        }
		else
		{
		    operator=postfix[i];
			op2=pop();
			op1=pop();
			res=operation(op1,op2,operator);
			push(res);
		}
	}
res=pop();
printf("evaluated value is %d \n",res);
}

int main()
{
	 char postfix[20];
     printf("Enter the expression :: ");
     scanf("%s",postfix);
     evaluation(postfix);
     return 0;
}

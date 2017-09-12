#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max 50
 int top=-1;
char s[max];
void push(char ele)
{
if(top==max-1);
printf("stack overflow");
else
{
top= top+1;
s[top]=ele;
}
}
char pop()
{
char del;
if(top==-1)
printf("stack underflow");
else 
{
del= s[top];
top=top-1;
}
return del;
}
int priority(char c)
{
if(c=='#')
return 0;
else if(c=='(')
return 1;
else if(c=='+'||c=='-')
return 2;
else if(c=='*'||c=='/'||c=='%')
return 3;
else
return 4;

int main()
{
int i,j=0;
char postfix[max],infix[max];
printf("enter the infix");
scanf("%s",infix);
push('#');
for(i=0;infix[i]!=0;i++)
{
if (infix[i]=='(')
{
push (infix[i]);();
}
else if(isalum(infix[i]))
{
postfix[j++]=infix[i];
}
else if(infix[i]==')')
{
while(s[top]!='(')
{
postfix[j++]=pop();
}
pop();
}
else
{
while(priority(s[top])>priority(infix[i]))
{
postfix[j++]=pop();
}
push(infix[i]);
}
}
while(s[top]!='#')
postfix[j++]=pop();
postfix[j]='\0';
printf("the postfix expression is %s \n",postfix);
return 0;
}

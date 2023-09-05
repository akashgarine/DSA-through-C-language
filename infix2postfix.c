#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
char stack[81];
int tos=-1;
char pop ()
{
	return stack[tos--];
}
char peep()
{
	return stack[tos];	
}
void push(char c)
{
	stack[++tos]=c;
}
int priority (char op)
{
	switch(op)
	{
	 case '(':return 0;
	 case '/':
	 case '*':return 2;
	 case '+':
	 case '-':return 1;
	}
}
bool isOperator (char op)
{
	switch(op)
	{
	 case '+':
	 case '-':
	 case '*':
	 case '/':
	 case '%':return true;
	 default :return false;
	 }
}
void infix2postfix(char infix[81],char postfix[81])
{
	int i,j;
	char token,op,x;
	i=0,j=0;
	for(i=0;infix[i]!='\0';i++)
	{
	 token=infix[i];
	 if(token=='(')
	   push(token);
	 else if(token==')')
	      { 
	        while('('!=(x=pop()))
	         postfix[j++]=x;
	      }
	     else if(true==isOperator(token))
	          {
	            while(true)
	            {
	              op=peep();
	              if(priority(op)>=priority(token)&&tos>-1)
	                  postfix[j++]=pop();
	              else 
	                  break;
	            }
	            push(token);
	         }
	        else
	         postfix[j++]=token;
	        }
	        while(-1!=tos)
	         { 
	           postfix[j++]=pop();
	       	 }
	      	 postfix[j++]='\0';    
}
int main ()
{
	char infix[81],postfix[81];
	printf("Enter infix:");
	scanf(" %[^\n]",infix);
	infix2postfix(infix,postfix);
	printf("postfix:%s\n",postfix);
	return 0;
}

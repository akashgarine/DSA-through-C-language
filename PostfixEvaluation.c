#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
char stack[81];
int tos=-1;
void push(char c)
{
	stack[++tos]=c;
}
char pop ()
{
	return stack[tos--];
}
char peep()
{
	return stack[tos];	
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
int compute(int x,char op, int y)
{
	switch(op)
	{
	  case '+':return x+y;
	  case '-':return x-y;
	  case '*':return x*y;
	  case '/':if(y!=0)
	  	    return x/y;
	  case '%':if(y!=0)
	  	    return x%y;
	}
}
int posteval(char postfix[81])
{
	char token;
 	int i,res,val,y,x;
 	i=0;
 	for(i=0;postfix[i]!='\0';i++)
 	{
 	   token=postfix[i];
 	   if(false==isOperator(token))
 	     push(token-'0');
 	   else 
 	   { 
 	     y=pop();
 	     x=pop();
 	     res=compute(x,token,y);
 	     push(res);
 	   }
 	 }
 	 if(tos==0)
 	 {
 	 val=pop();
 	 }
 	 else
 	   printf("postfix evalution may be empty\n");
 	 return val;
}
int main ()
{
	char postfix[81];
	int ans;
	printf("Enter postfix:");
	scanf("%[^\n]",postfix);
	ans=posteval(postfix);
	printf("postfix eval:%d\n",ans);
	return 0;
}

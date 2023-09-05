#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct stackArraylist{
	int *list;
	int tos;
	int capacity;
};
typedef struct stackArraylist stack;
stack * newstack(int capacity)
{
	stack *self=NULL;
	self=(stack*)malloc(sizeof(stack));
	self->capacity=capacity;
	self->list=(int*)malloc(sizeof(int)*self->capacity);
	self->tos=-1;
	return self;
}
bool push (stack *self,int elem)
{
	if(self->tos+1==self->capacity)
	  return false;
	self->tos++;
	self->list[self->tos]=elem;
	return true;
}
void display(stack *self)
{
	int i;
	if(self->tos==-1)
	  printf("stack is empty\n");
	else
	for(i=self->tos;i>=0;i--)
	  printf("|%d|\n",self->list[i]);
}
bool pop(stack *self, int *pelem)
{
	if(self->tos==-1)
	  return false;
	*pelem=self->list[self->tos];
	self->tos--;
	return true;
}
bool peep (stack *self, int *pelem)
{	
	if(self->tos==-1)
	{
	 return false;
	}
	*pelem=self->list[self->tos];
	return true;
}
int main ()
{
	stack *s=NULL;
	int elem,c;
	s=newstack(5);
	printf("1.push\n2.pop\n3.peep\n4.display\n5.exit\n");
	do{
		printf("Enter choice:");
		scanf("%d",&c);
	switch(c)
	{
	 case 1:printf("Enter elem:");
	 	scanf("%d",&elem);
                push(s,elem);
                break;
         case 2:pop(s,&elem);
         	printf("poped elem is:%d\n",elem);
         	break;
         case 3:if(true==peep(s,&elem))
         	printf("peep elem is %d\n",elem);
         	else
         	printf("No elements in stack\n");
          	break;
         case 4:display(s);
         	break;
         case 5:exit(0);
         default:printf("Invalid\n");
          }
         }while(1);
}

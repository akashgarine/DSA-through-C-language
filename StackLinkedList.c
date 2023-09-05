#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct NodeType{
	int data;
	struct NodeType *link;
};
typedef struct NodeType Node;
struct stack{
	Node *tos;
};
typedef struct stack stack;
Node* newNode(int data)
{
	Node *pNew;
	pNew=(Node*)malloc(sizeof(Node));
	pNew->data=data;
	pNew->link;
	return pNew;
}
stack* newstack()
{
	stack *self;
	self=(stack*) malloc(sizeof(stack));
	self->tos=NULL;
	return self;
}
bool push (stack *self, int elem)
{
	Node *pNew=NULL;
	pNew=newNode(elem);
	pNew->link=self->tos;
	self->tos=pNew;
	return true;
}
bool pop (stack *self , int *pelem)
{
	if(self->tos==NULL)
	  return false;
	Node *pDel=NULL;
	pDel=self->tos;
	*pelem=pDel->data;
	self->tos=self->tos->link;
	free(pDel);
	return true;
}
bool peep(stack *self , int *pelem)
{
	if(self->tos==NULL)
	  return false;
	*pelem=self->tos->data;
	  return true;
}
void display(stack *self)
{
	 Node *jump=NULL;
	 jump=self->tos;
	 if(jump!=NULL)
	 {
	   printf("Stack as follows\n");
	    while(jump!=NULL)
	   {
	      printf("|%d|\n",jump->data);
	      jump=jump->link;
	    }
	  }
	 else
	  printf("Stack is empty\n");
}
int main ()
{
	stack *s;
	s=newstack();
	int c,elem;
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
          case 2:if(true==pop(s,&elem))
         	printf("poped elem is:%d\n",elem);
         	else
         	printf("No elements in stack\n");
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

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct NodeType{
	int data;
	struct NodeType *link;
};
typedef struct NodeType Node;
struct QueueADT{
	Node *front;
	Node *rear;
};
typedef struct QueueADT Queue;
Node* newNode(int data)
{
	Node *pNew=NULL;
	pNew=(Node*)malloc(sizeof(Node));
	pNew->data=data;
	pNew->link=NULL;
	return pNew;
}
Queue* newQueue()
{
	Queue *self;
	self=(Queue*)malloc(sizeof(Queue));
	self->front=NULL;
	self->rear=NULL;
	return self;
}
bool enQueue(Queue *self, int elem)
{
	Node *pNew=NULL;
	pNew=newNode(elem);
	if(self->front==NULL)
	 {
	   self->front=pNew;
	   self->rear=pNew;
	   return true;
	 }
	 self->rear->link=pNew;
	 self->rear=pNew;
	 return true;
	 
}
bool deQueue (Queue *self, int *pelem)
{
	Node *pDel=NULL;
	if(self->front==NULL)
	   return false;
	pDel=self->front;
	*pelem=pDel->data;
	self->front=self->front->link;
	if(self->front==NULL)
	   self->rear=NULL;
	free(pDel);
	return true;
	
}
void display(Queue *self)
{
	Node *jump;
	jump=self->front;
	if(self->front==NULL)
	  printf("Queue is empty\n");
	else
	  printf("Queue as follows\n");
	  while(jump!=NULL)
	  {
	  	printf("|%d|",jump->data);
	  	jump=jump->link;
	  }
	  putchar('\n');
}
int main ()
{
	Queue *ql;
	ql=newQueue();
	int c, elem;
	printf("1.enQueue\n2.deQueue\n3.display\n4.exit\n");
	do
         {
           printf("Enter choice:");
           scanf("%d",&c);
         switch(c)
         {
           case 1:printf("Enter elem:");
      	    	   scanf("%d",&elem);
      	    	   enQueue(ql,elem);
      	    	   break;
      	    case 2:deQueue(ql,&elem);
      	    	printf("DeQueue elem is:%d\n",elem);
      	    	break;
      	    case 3:display(ql);
      	     	 break;
      	    case 4:exit(1);
      	    default:printf("Invalid\n");
      	 }
      	 }while(true);
}

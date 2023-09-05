#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct QueueArraylist{
	int front;
	int rear;
	int  *list;
	int capacity;
};
typedef struct QueueArraylist Queue;
Queue* newQueue (int capacity)
{
	Queue *self;
	self=(Queue*)malloc(sizeof(Queue));
	self->capacity=capacity;
	self->list=(int*)malloc(sizeof(int));
	self->front=0;
	self->rear=-1;
	return self;
}
bool enQueue(Queue *self,int elem)
{
	if(self->rear+1==self->capacity)
	  return false;
	 self->rear++;
	 self->list[self->rear]=elem;
	 return true;
}
bool deQueue(Queue *self, int *pelem)
{
	if(self->front >self->rear)
	  return false;
	*pelem=self->list[self->front];
	self->front++;
	return false;
}
void display(Queue *self)
{
	int i;
	if(self->front>self->rear)
	   printf("Queue is empty\n");
	else
	{
	  printf("Queue as follows\n");
	  for(i=self->front;i<=self->rear;i++)
	  printf("|%d|",self->list[i]);
	}
	putchar('\n');
}
int main()
{
	int elem;
	Queue *q;
	q=newQueue(5);
	int c;
	printf("1.enQueue\n2.deQueue\n3.display\n4.exit\n");
	do
	 {
	  	printf("Enter choice:");
	  	scanf("%d",&c);
	switch(c)
	{
	  case 1:printf("Enter elem:");
	  	scanf("%d",&elem);
	  	enQueue(q,elem);
	  	break;
	  case 2:deQueue(q,&elem);
	  	 printf("Deleted elem is %d\n",elem);
	  	 break;
	  case 3:display(q);
	  	 break;
	  case 4: exit(1);
	  default:printf("Invalid\n");
	}
	}while(1);
}

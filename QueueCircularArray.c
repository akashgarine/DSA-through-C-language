#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
struct QueueCir{
	int *list;
	int capacity;
	int front;
	int rear;
};
typedef struct QueueCir Queue;
Queue* newQueue (int capacity)
{
	Queue *self;
	self=(Queue*)malloc(sizeof(Queue));
	self->capacity=capacity;
	self->list=(int*)malloc(sizeof(int)*self->capacity);
	self->front=0;
	self->rear=0;
	return self;
}
bool enQueue(Queue *self, int elem)
{
	if(self->front==(self->rear+1)%self->capacity)
		return false;
	self->list[self->rear]=elem;
	self->rear=(self->rear+1)%self->capacity;
	return true;
}
bool deQueue(Queue *self, int *pelem)
{
	if(self->rear==self->front)
	  return false;
	*pelem=self->list[self->front];
	self->front=(self->front+1)%self->capacity;
	return true;
}
void display(Queue *self)
{
	int i;
	if(self->rear==self->front)
	{
	   printf("Queue is empty\n");
	   return;
	}
	for(i=self->front;i!=self->rear;i=(i+1)%self->capacity)
	   printf("%d |",self->list[i]);
	putchar('\n');
}
int main()
{
	Queue *ql;
	ql=newQueue(5);
	int elem;
	int c;
	printf("1.enQueue\n2.deQueue\n3.display\n4.exit\n");
	do{
	     printf("Enter choice:");
	     scanf("%d",&c);
	switch(c)
	{
	  case 1:printf("Enter Elem:");
	  	 scanf("%d",&elem); 
	         enQueue(ql,elem);
	  	 break;
	  case 2:deQueue(ql,&elem);
	         printf("Dequeue elem:%d\n",elem);
	         break;
	  case 3:display(ql);
	  	break;
	  case 4:exit(1);
	  default :printf("Invalid\n");
	 }
	 }while(1);
	
}

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct arrayADT{
	int *list;
	int size;
	int capacity;
};
typedef struct arrayADT Arraylist;
Arraylist* newarray(int capacity)
{
	Arraylist *pNew;
	pNew=(Arraylist*)malloc(sizeof(Arraylist));
	pNew->capacity=capacity;
	pNew->list=(int*)malloc(sizeof(int)*pNew->capacity)    	 	;
	pNew->size=0;
	return pNew;
}
bool insertBeg(Arraylist *self, int elem)
{
	int i;
	if(self->size==self->capacity)
	 return false;
	for(i=self->size-1;i>=0;i--)
	self->list[i+1]=self->list[i];
	self->list[0]=elem;
	self->size++;
	return true;
}
bool insertEnd (Arraylist *self , int elem)
{
	if(self->size==self->capacity)
	 return false;
	self->list[self->size]=elem;
	self->size++;
	return true;		 		
}
bool insertAt (Arraylist *self,int pos, int elem)
{
	int i;
	if(self->size==self->capacity)
	 return false;
	if (pos<0||pos > self->size)
	return false;
	for (i=self->size-1;i>=pos;i--)
	self->list[i+1]=self->list[i];
	self->list[pos]=elem;
	self->size++;
	return true;
}
void display(Arraylist *self)
{
	int i;
	if(0==self->size)
	{
	  printf("List is empty\n");
	  return;
	  putchar('\n');
	}
	else
	{
	for(i=0;i<self->size;i++)
	 printf("%d |",self->list[i]);
	}
	putchar('\n');
}
bool deleteBeg (Arraylist *self,int *pelem)
{
	int i;
	if(0==self->size)
	 return false;
	*pelem=self->list[0];
	for(i=1;i<self->size;i++)
	self->list[i-1]=self->list[i]; 
	self->size--;
	return true;
}
bool deleteEnd(Arraylist *self,int *pelem)
{
	if(0==self->size)
	 return false;
	*pelem=self->list[self->size-1];
	self->size--;
	return true;
}
bool deleteAt (Arraylist *self, int pos, int *pelem)
{
	int i ;
	if (self->size==0)
	return false;
	*pelem=self->list[pos];
	for(i=pos+1;i<self->size;i++)
	self->list[i-1]=self->list[i];
	self->size--;
	return true;
}
int search(Arraylist *self,int elem)
{
	int pos,i;
	for(i=0;i<self->size;i++)
	{
	 if(elem==self->list[i])
	    return i;
	}
}
int main ()
{
	Arraylist *al=NULL;
	al=newarray(10);
	int c,elem,pos,res;
	printf("1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
	do{
	printf("Enter choice:");
	scanf("%d",&c);
	
	switch(c)
	{
	case 1: printf("Enter elem:");
	 	scanf("%d",&elem);
	 	printf("Enter pos:");
	 	scanf("%d",&pos);
	 	if(pos==0)
	 	insertBeg(al,elem);
	 	else if (al->size==pos)
	 	insertEnd(al,elem);
	 	else 
	 	insertAt(al,pos,elem);
	 	break;
	case 2:printf("Enter pos:");
	 	scanf("%d",&pos);
		if(pos==0)
	 	deleteBeg(al,&elem);
	 	else if (al->size==pos)
	 	deleteEnd(al,&elem);
	 	else 
	 	deleteAt(al,pos,&elem);
	 	printf("Deleted elem is:%d\n",elem);
	 	break;
	case 3:display(al);
		break;
	case 4:printf("Enter elem:");
		scanf("%d",&elem);
		res=search(al,elem);
		printf("Elem %d at pos [%d]\n",elem,res);
		break;
	case 5: exit(0);
	default :printf("INVALID\n");
	 }
	}while(true);
	putchar('\n');
	return 0;
		
}

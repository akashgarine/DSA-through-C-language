#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct LinkedNode{
	struct LinkedNode *prev;
	int data;
	struct LinkedNode *next;
};
typedef struct LinkedNode Node;
struct doublyLinkedList{
	Node *head;
};
typedef struct doublyLinkedList DLL;
Node* newNode (int data)
{
	Node *pNew=NULL;
	pNew=(Node*)malloc(sizeof(Node));
	pNew->data=data;
	pNew->prev=NULL;
	pNew->next=NULL;
	return pNew;
}
DLL *doublyLList()
{
	DLL *self;
	self=(DLL*)malloc(sizeof(DLL));
	self->head=NULL;
	return self;
}
bool insertBeg(DLL *self, int elem)
{
	Node *pNew=NULL;
	pNew=newNode(elem);
	if(self->head==NULL)
	{
	 self->head=pNew;
	 return true;
	}
	pNew->next=self->head;
	self->head->prev=pNew;
	self->head=pNew;
	return true;
}
bool insertEnd(DLL *self, int elem)
{
	Node *pNew=NULL;
	Node *jump=NULL;
	pNew=newNode(elem);
	if(self->head==NULL)
	{
	 self->head=pNew;
	 return true;
	}
	jump=self->head;
	while(jump->next!=NULL)
	{
	 jump=jump->next;
	}
	jump->next=pNew;
	pNew->prev=jump;
	return true;	
}
int count (DLL *self)
{
	Node *jump=NULL;
	int i;
	i=1;
	jump=self->head;
	while(jump->next!=NULL)
	{
	 jump=jump->next;
	 i++;
	}
	return i;
}
bool insertAt(DLL *self, int elem,int pos)
{
 	Node *pNew=NULL;
 	pNew=newNode(elem);
 	Node *jump=NULL;
 	if(pos<0||pos>count(self))
 	 return false;
 	if(pos==0)
 	 return insertBeg(self,elem);
 	if(pos==count(self))
 	 return insertEnd(self,elem);
 	jump=self->head;
 	int i=1;
 	while(i<pos)
 	{
 	  jump=jump->next;
 	  i++;
 	}
 	pNew->next=jump->next;
 	jump->next->prev=pNew;
 	jump->next=pNew;
 	pNew->prev=jump;
 	return true;
 	
}
void display (DLL *self)
{
	Node *jump=NULL;
	jump=self->head;
	if(self->head==NULL)
	{
	 printf("Linked list is empty\n");
	 return ;
	}
	else
	while(jump!=NULL)
	{
	   printf("%d |",jump->data);
	   jump=jump->next;
	}
	putchar('\n');
}
bool deleteBeg(DLL *self, int *pelem)
{
	Node *pDel=NULL;
	if(self->head==NULL)
	 return false;
	pDel=self->head;
	*pelem=pDel->data;
	self->head=self->head->next;
	free(pDel);
	return true;
}
bool deleteEnd (DLL *self, int *pelem)
{
	 Node *pDel=NULL;
	 Node *lbo=NULL;
	 pDel=self->head;
	 if(NULL==self->head)
	  return false;
	 while(pDel->next!=NULL)
	 {
	   lbo=pDel;
	   pDel=pDel->next;
	 }
	  *pelem=pDel->data;
	  lbo->next=NULL;
	  free(pDel);
	  return true;
}
bool deleteAt(DLL *self,int pos, int *pelem)
{
	int i;
	Node *pDel=NULL;
	Node *lbo=NULL;
	pDel=self->head;
	if(self->head==NULL)
	 return false;
	if(pos==0)
	   return deleteBeg(self,pelem);
	if(pos==count(self)-1)
	   return deleteEnd(self,pelem);
	for(i=0;i<pos;i++)
	{
	 lbo=pDel;
	 pDel=pDel->next;
	}
	*pelem=pDel->data;
	lbo->next=pDel->next;
	pDel->next->prev=lbo;
	free(pDel);
	return true;	 
}
int search(DLL *self, int key)
{
	Node *jump;
	int i=0;
	jump=self->head;
	while(jump!=NULL)
	{
	  if(jump->data==key)
	      return i;
	   else
	   {
	    jump=jump->next;
	    i++;
	   }
	}
	 return -1;
}
int main ()
{
	DLL *ll=NULL;
	ll=doublyLList();
	int c,elem,pos,res;
	printf("1.insert\n2.delete\n3.display\n4.search\n5.exit\n");
	do{
		printf("Enter choice:");
		scanf("%d",&c);
	 switch(c)
	 {
	   case 1:printf("Enter elem:");
	   	  scanf("%d",&elem);
	   	  printf("Enter pos:");
	   	  scanf("%d",&pos);
	   	  if(pos==0)
	   	   insertBeg(ll,elem);
	   	  else if (pos==count(ll))
	   	    insertEnd(ll,elem);
	   	      else 
	   	       insertAt(ll,elem,pos);
	   	  break;
	   case 2:printf("Enter pos:");
	   	  scanf("%d",&pos);
	   	  if(pos==0)
	   	   deleteBeg(ll,&elem);
	   	  else if (pos==count(ll)-1)
	   	   deleteEnd(ll,&elem);
	   	  else
	   	   deleteAt(ll,pos,&elem);
	   	   printf("Deleted elem is:%d\n",elem);
	   	  break ;
	   case 3:display(ll);
	   	break ;
	   case 4 :printf("Enter elem to search:");
	   	   scanf("%d",&elem);
	   	   res=search(ll,elem);
	   	   if(res==-1)
	   	   printf("Key not found\n");
	   	   else
	   	   printf("Key found at :%d\n",res);
	   	   break;
	   case 5:exit(0);
	   default :printf("Invalid\n");
	 }
	}while(1);
	
}
	

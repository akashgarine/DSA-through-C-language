#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Nodetype{
	int data;
	struct Nodetype *link;
};
typedef struct Nodetype Node;
struct Linkedlist {
	Node *head;
};
typedef struct Linkedlist Linkedlist;
Linkedlist* newlist ()
{
	Linkedlist *self;
	self=(Linkedlist*)malloc(sizeof(Linkedlist));
	self->head=NULL;
	return self;
	
}
Node * newnode(int data)
{
	Node *pNew;
	pNew=(Node*)malloc(sizeof(Node));
	pNew->data=data;
	pNew->link=NULL;
	return pNew;
}
int count(Linkedlist *self)
{	
	Node *jump;
	int count=1;
	jump=self->head;
	   if (self == NULL || self->head == NULL) 
              return 0;
	while(jump->link!=NULL)
	{
	 count++;
	 jump=jump->link;
	}
	return count;
}
bool insertBeg(Linkedlist *self,int data)
{
	Node *pNew;
	pNew=newnode(data);
	if(self->head==NULL)
	{
	 self->head=pNew;
	 return true;
	}
	pNew->link=self->head;
	self->head=pNew;
	return true;
}
bool insertEnd (Linkedlist *self,int data)
{
	Node *pNew;
	Node *jump;
	pNew=newnode(data);
	if(NULL==self->head)
	{
	   self->head=pNew;
	   return true;
	 }
	jump=self->head;
	while(jump->link!=NULL)
	     jump=jump->link;
	jump->link=pNew;
	return true;	
}
bool insertAt (Linkedlist *self,int data,int pos)
{
	Node *pNew=NULL;
	Node *jump;
	int i;
	pNew=newnode(data);
	if(pos<0||pos>count(self))
	  return false;
	jump=self->head;
	for(i=1;i<pos;i++)
	{
	 jump=jump->link;
	}
	if(jump!=NULL)
	{
	 pNew->link=jump->link;
	 jump->link=pNew;
	}
	return true;
}
void display (Linkedlist *self)
{
	Node *jump=NULL;
	jump=self->head;
	while(jump!=NULL)
	{
	  printf("%d |",jump->data);
	  jump=jump->link;
	}
	putchar('\n');
}
bool deleteBeg(Linkedlist *self,int *pelem)
{	
	Node *pDel;
	pDel=self->head;
	*pelem=pDel->data;
	self->head=self->head->link;
	free(pDel);
	return true;
}
bool deleteEnd(Linkedlist *self, int *pelem)
{
	Node *pDel=NULL;
	Node *lbo=NULL;
	if(NULL==self->head)
	  return false;
	if(self->head->link==NULL)
	 {
	   *pelem=self->head->data;
	   free(self->head);
	   self->head=NULL;
	   return true;
	  }
	 pDel=self->head;
	 while(pDel->link!=NULL)
	  {
	    lbo=pDel;
	    
	    pDel=pDel->link;
	  }
	*pelem=pDel->data;
	lbo->link=NULL;
	free(pDel);
	return true;
}
bool deleteAt(Linkedlist* self,int pos,int *pelem)
{
 	Node *pDel=NULL;;
 	Node *pRev=NULL;
 	if(NULL==self->head)
 	 return false;
 	if(pos<0||pos>count(self))
 	  return false;
 	if (pos==0)
 	return deleteBeg(self,pelem);
 	if (pos==count(self)-1)
 	return deleteEnd(self,pelem);
 	int i;
 	pRev=NULL;
 	pDel=self->head;
 	for(i=0;i<pos;i++)
 	{
 	  pRev=pDel;
 	  pDel=pDel->link;
 	}
        *pelem=pDel->data;
 	pRev->link=pDel->link;
 	free(pDel);
 	return true;
}
int search(Linkedlist *self,int key )
{
	Node *jump=NULL;
	jump=self->head;
	int i=0;
	while(jump!=NULL)
	{
	 if(jump->data==key)
	   return i;
	 else
	 {
	  i++;
	  jump=jump->link;
	 }
	}
	return -1;
}
int main ()
{
	Linkedlist *ll=NULL;
	ll=newlist();
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
	   	   printf("Deleted elem is:%d\nc",elem);
	   	  break ;
	   case 3:display(ll);
	   	break ;
	   case 4 :printf("Enter elem to search:");
	   	   scanf("%d",&elem);
	   	   res=search(ll,elem);
	   	   if(res==-1)
	   	   printf("Key %d not  found\n",elem);
	   	   else
	   	   printf("Key %d found at :%d\n",elem,res);
	   	   break;
	   case 5:exit(1);
	   default :printf("Invalid\n");
	 }
	}while(1);
	return 0;	
}
	
	
	

#include<stdio.h>
#include<stdlib.h>
struct st{
	int data;
	struct st *prev;
	struct st *link;
};
void add(struct st **,int);
void display(struct st **);
int main()
{
	struct st *head=NULL;
	add(&head,10);
	add(&head,20);
	add(&head,30);
	add(&head,40);
	add(&head,50);
	display(&head);
}
void add(struct st **ptr,int n)
{
	struct st *newnode,*temp;
	newnode=*ptr;
	if(newnode==NULL)
	{
		newnode=(struct st*)malloc(sizeof(struct st));
		newnode->prev=NULL;
		newnode->data=n;
		newnode->link=NULL;
		*ptr=newnode;
	}
	else
	{
		while(newnode->link!=NULL)
			newnode=newnode->link;
		temp=(struct st *)malloc(sizeof(struct st));
		temp->prev=newnode;
		temp->data=n;
		temp->link=NULL;
		newnode->link=temp;
	}
	return ;
}
void display(struct st **ptr)
{
	struct st *temp,*q;
	temp=*ptr;
	q=*ptr;
	while(temp!=NULL)
	{
		printf("\n%p\t %p\t%d\t%p\n",temp,temp->prev,temp->data,temp->link);
		temp=temp->link;
	}
}



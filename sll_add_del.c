#include<stdio.h>
#include<stdlib.h>
struct Student
{
	int roll;
	char name[20];
	struct Student *link;
};
struct Student * Add_first(struct Student *ptr)
{
	struct Student *newnode=NULL;
	newnode=malloc(sizeof(struct Student));
	if(newnode==NULL)
	{
		printf("node not created\n");

	}
	else
	{
		printf("enter the roll\n");
		scanf("%d",&newnode->roll);
		printf("enter the name\n");
		scanf("%s",newnode->name);
		newnode->link=NULL;
		newnode->link=ptr;
		ptr=newnode; 
	}
	return ptr;
}
void Display(struct Student *ptr)
{
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		while(ptr)
		{
			printf("%d %s\n",ptr->roll,ptr->name);
			ptr=ptr->link;
		}
	}
}
struct Student * Add_last(struct Student *ptr)
{
	struct Student *newnode=NULL,*temp=NULL;
	newnode=malloc(sizeof(struct Student));
	if(newnode==NULL)
	{
		printf("Node not created\n");
	}
	else
	{
		printf("enter the roll\n");
		scanf("%d",&newnode->roll);
		printf("enter the name\n");
		scanf("%s",newnode->name);
		newnode->link=NULL ;// if we use malloc fun for memory allocation
		if(ptr==NULL) 
		{
			ptr=newnode;
		}
		else
		{
			temp=ptr;
			while(temp->link!=NULL)
			{
				temp=temp->link;
			}
			temp->link=newnode;
		}
	}
	return ptr;
}
struct Student * Del_first(struct Student *ptr)
{
	struct Student *temp=NULL;
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp=ptr; // assigning first to temp;
		ptr=ptr->link; // making next node as first node  or moving ptr to next node;
		free(temp);
		temp=NULL;
	}
	return ptr;
}
struct Student * Reverse(struct Student *ptr)
{
	struct Student *prev=NULL,*cur=NULL,*next=NULL;
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else if(ptr->link==NULL)
	{
		printf("List is having only one node in the list\n");
	}
	else
	{
		next=ptr;// pointing to first node
		while(next)
		{
			prev=cur;
			cur=next;
			next=next->link;
			cur->link=prev; // linking with previous node;
		}
		ptr=cur;
	}
	return ptr;
}
struct Student * Del_last(struct Student *ptr)
{
	struct Student *temp=NULL,*prev=NULL;
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		temp=ptr;
		while(temp->link!=NULL)
		{
			prev=temp;
			temp=temp->link;
		}
		free(temp);
		temp=NULL;
		if(prev) 
			prev->link=NULL;
		else
			ptr=NULL;
	}
	return ptr;
}
struct Student * Del_data(struct Student *ptr)
{
	struct Student *prev=NULL,*temp=NULL;
	int data;
	printf("enter the data\n");
	scanf("%d",&data);
	if(ptr==NULL)
	{
		printf("List is empty\n");
	}
	else if(data==ptr->roll)// data matching with first node
	{
		temp=ptr;
		ptr=ptr->link;
		free(temp);
		temp=NULL;
	}
	else
	{
		prev=ptr;  // first node
		temp=ptr->link; // second node
		while(temp && data !=temp->roll)
		{
			prev=temp;
			temp=temp->link;
		}
		if(temp==NULL)
		{
			printf("%d is not found\n",data);
		}
		else
		{
			prev->link=temp->link;
			free(temp);
			temp=NULL;
		}
	}
	return ptr;
}
void countnode(struct Student *ptr)
{
	int cnt=0;
	struct Student *temp=NULL;
	if(ptr==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		temp=ptr;
		while(temp!=NULL)
		{
			cnt++;
			temp=temp->link;
		}
	}
	printf("count the no.of nodes in sll %d\n",cnt);
}
//struct Student *head=NULL;
int main()
{
	struct Student *head=NULL;
	int choice;
	while(1)
	{
		printf("1. Add_first 2.Display 3. add_last 4.del_first  5.del_last 6.del_data 7.reverse 8.countnode 9.exit\n");
		printf("enter the choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: head=Add_first(head);
				break;
			case 2: Display(head);
				break;
			case 3:head=Add_last(head);
				break;
			case 4:head=Del_first(head);
			       break;
			case 5:head=Del_last(head);
			       break;
			case 6:head=Del_data(head);
			       break;
			case 7:head=Reverse(head);
			       break;
			case 8:countnode(head);
			       break;
			case 9: exit(0);
		}
	}
}

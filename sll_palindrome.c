#include <stdio.h>
#include <stdlib.h>
struct student
{
      	int data;
	struct student *link;
};
struct student *head=NULL;
void add_first(int num)
{
    struct student* newnode=(struct student*)malloc(sizeof(struct student));
    newnode->data=num;
    newnode->link=head;
    head = newnode;
}
struct student* reverselist(struct student *head) 
{
    struct student *newnode1=NULL, *ptr;
    if(head==NULL) 
    { 
       printf("Invalid\n");       
       return 0;  
    }
    while(head!=NULL) 
    {
        ptr=(struct student*)malloc(sizeof(struct student));
        ptr->data=head->data;
        ptr->link=newnode1;
        newnode1=ptr;
        head=head->link;
    }
    return newnode1;
}
int compare_list(struct student* list, struct student* rev)
{ 
    while(list!=NULL&&rev!=NULL) 
    {
        if(list->data!=rev->data)
            return 0;
	list=list->link;
        rev=rev->link;
    }
     return(list==NULL && rev==NULL);
}
void display(struct student *ptr) 
{
       	while(ptr!= NULL) 
	{
	       	printf("%d\t", ptr->data);
	       	ptr=ptr->link;
	}
}	
int main()
{
    struct student *reverse;
    int i,node, temp;
    printf("Enter number of Nodes in Linked List\n");
    scanf("%d", &node);
    printf("enter the details:"); 
    for(i=0;i<node;i++)
    {
        scanf("%d", &temp);
        add_first(temp);
    } 
    printf("Linked List\n");
    display(head);
    reverse = reverselist(head);
    if(compare_list(head, reverse))
    {
	    printf("\nlist is Palindrome\n");
    }
    else
    {
        printf("\nlist is not a Palindrome\n");
    }
}

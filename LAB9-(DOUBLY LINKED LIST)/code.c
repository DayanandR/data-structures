#include<stdio.h>

#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
void insert_left()
{
	 struct node *new_node;
	 new_node=(struct node*)malloc(sizeof(struct node));
	 printf("Enter the item\n");
	 scanf("%d",&new_node->data);
	 new_node->next=NULL;
	 new_node->prev=NULL;

	 if(head==NULL)
	 {
			head=new_node;
	 }
	 else
	 {
			new_node->next=head;
			head->prev=new_node;
			head=new_node;
	 }

}

void insert_right()
{
	struct node *new_node,*temp;
	new_node=(struct node*)malloc(sizeof(struct node));
	printf("Enter the item\n");
	scanf("%d",&new_node->data);
	new_node->next=NULL;
	new_node->prev=NULL;
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		 temp=head;
		 while(temp->next!=NULL)
		 temp=temp->next;
		 temp->next=new_node;
		 new_node->prev=temp;

	}

}

void del()
{
	struct node *temp;
	int ele;
    if(head==NULL)
    {
        printf("Empty List \n");
        return;
    }
	printf("Enter the element to be deleted\n");
	scanf("%d",&ele);
	temp=head;
	while(temp->data!=ele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
		 printf("Element is not in the list\n");
		 break;
		}
	 }
	 if(temp==head)
	 {
		 head=head->next;
	 }
	 else if(temp->next==NULL)
	 {
			temp=temp->prev;
			temp->next=NULL;
	 }

	 else
	 {
		 temp->prev->next=temp->next;
		 temp->next->prev=temp->prev;
	 }
}
void display()
{
	 struct node *ptr;
	 ptr=head;
	 while(ptr!=NULL)
	 {
		 printf("%d\t",ptr->data);
		 ptr=ptr->next;
	 }
	 printf("\n");
}


int main()
{
	int choice;
	
	 while(1)
	 {
			printf(" 1. Insert at the left \n");
			printf(" 2. Insert at the right \n");
			printf(" 3. Delete \n");
			printf(" 4. Display\n");
			printf(" 5. Exit\n");
			printf("Enter your choice\n");
			scanf("%d",&choice);
			switch(choice)
			{
				 case 1: insert_left(); break;
				 case 2: insert_right();break;
				 case 3: del(); break;
				 case 4: display(); break;
				 case 5: exit(0);
			}
	 }
}

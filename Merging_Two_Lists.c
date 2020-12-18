#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;	
}*head1=NULL,*head2=NULL,*head3=NULL;

void menu()
{
	printf(" Menu (Linked List):\n---------------------");
	printf("\n\n0) Exit.");
	printf("\n1) Create linked list 1.");
	printf("\n2) Create linked list 2.");
	printf("\n3) Display linked list 1.");
	printf("\n4) Display linked list 2.");
	printf("\n5) Merge the two linked list.");
	printf("\n6) Display the merged linked list.");
	printf("\n7) Re-display the menu.");
}

void free_all(struct Node* head)
{
	struct Node* ptr=head;
	while(ptr)
	{
		head=head->next;
		free(ptr);
		ptr=head;
	}
	
	head=NULL;
}

struct Node* display(struct Node* head)
{
	if(!head)
	{
		printf("ERROR: No list found.");
		return NULL;
	}
	
	struct Node* ptr=head;
	
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
	return head;
}

struct Node* create(struct Node* head,int n)
{
	if(head)
	{
		printf("\n\nERROR: A linked list is already present.");
		printf("\n\nMESSAGE: Displaying the list:\n\n");
		display(head);
		int ch;
		printf("\n\nMESSAGE: Do you want to delete the previous linked list and make a new one. If yes, enter '1', otherwise '0'.\nEnter your choice: ");
		scanf("%d",&ch);
		if(ch==0)
		return head;
		else
		free_all(head);
	}
	
	if(!n)
	{
		printf("\n\nMESSAGE: No node created for the list.");
		return NULL;
	}
	
	struct Node* ptr;
	
	printf("\n\nMESSAGE: Enter the '%d' sized data sequentially from left to right:\n\n",n);	
	
	int data,i;
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		
		struct Node* qtr=(struct Node*)malloc(sizeof(struct Node));
		
		if(!qtr)
		{
			printf("\n\nERROR: Dynamic allocation failed.");
			return NULL;
		}
		
		if(i==0)
		head=ptr=qtr;
		
		else
		ptr->next=qtr;
		
		qtr->data=data;
		qtr->next=NULL;
		
		ptr=qtr;
	}
	
	return head;
}

struct Node* merge(struct Node* head1,struct Node* head2,struct Node* head3)
{
	if(!head1 || !head2)
	{
		printf("\n\nERROR: One of the two lists not found.");
		return head3;
	}

	if(head3)
	{
		printf("\n\nERROR: A merged linked list is already present.");
		printf("\n\nMESSAGE: Displaying the list:\n\n");
		display(head3);
		int ch;
		printf("\n\nMESSAGE: Do you want to delete the previous linked list and make a new one. If yes, enter '1', otherwise '0'.\nEnter your choice: ");
		scanf("%d",&ch);
		if(ch==0)
		return head3;
		else
		free_all(head3);
	}
	
	struct Node* ptr=head1,*qtr,*rtr;
	int i=0;
	
	while(ptr)
	{	
		qtr=(struct Node*)malloc(sizeof(struct Node));
		
		if(!qtr)
		{
			printf("\n\nERROR: Dynamic allocation failed.");
			return NULL;
		}
		
		if(i==0)
		head3=qtr;
		else
		rtr->next=qtr;
		
		qtr->data=ptr->data;
		qtr->next=NULL;
		
		rtr=qtr;
		
		ptr=ptr->next;
		
		i++;
	}
	
	ptr=head2;
	
	i=0;
	
	while(ptr)
	{
		qtr=(struct Node*)malloc(sizeof(struct Node));
		
		if(!qtr)
		{
			printf("\n\nERROR: Dynamic allocation failed.");
			return NULL;
		}
		
		rtr->next=qtr;
		
		qtr->data=ptr->data;
		qtr->next=NULL;
		
		rtr=qtr;
		
		ptr=ptr->next;
		
		i++;
	}
	
	return head3;	
}

int main()
{
	int ch,n;
	menu();
	
	printf("\n\n");
	int i;
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	while(ch)
	{
		
		switch(ch)
		{			
			case 1:		printf("\n\nEnter the details for linked list '1':");
						printf("\nEnter the no of nodes, you want to create: ");
						scanf("%d",&n);
						head1=create(head1,n);
						break;
			
			case 2:		printf("\n\nEnter the details for linked list '2':");
						printf("\nEnter the no of nodes, you want to create: ");
						scanf("%d",&n);
						head2=create(head2,n);
						break;
						
			case 3:		printf("\n\nMESSAGE: Displaying the whole linked list '1'.\n\n");
						if(display(head1))
						printf("\n\nMESSAGE: Successfully displayed the whole linked list '1'.");
						break;
			
			case 4:		printf("\n\nMESSAGE: Displaying the whole linked list '2'.\n\n");
						if(display(head2))
						printf("\n\nMESSAGE: Successfully displayed the whole linked list '2'.");
						break;
									
			case 5:		printf("\n\nMESSAGE: Merging the two linked lists '1' & '2'.");
						struct Node* head;
						head=merge(head1,head2,head3);
						if(head)
						{
							head3=head;
							printf("\n\nMESSAGE: Successfully merged the two linked lists '1' & '2'.");
						}
						break;
						
			case 6:		printf("\n\nMESSAGE: Displaying the whole merged linked list.\n\n");
						if(display(head3))
						printf("\n\nMESSAGE: Successfully displayed the whole merged linked list.");
						break;
						
			case 7:		printf("\n\nMESSAGE: Re-displaying the menu.\n\n\n");
						menu();
						break;
			
			default:	printf("\n\nERROR: Wrong choice.");
						break;
						
		};
		
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
		
	}
	
	printf("\n\nMESSAGE: Program Exited.");
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	printf("\n\n");
	
	free_all(head1);
	free_all(head2);
	free_all(head3);
}

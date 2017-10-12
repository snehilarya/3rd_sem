#include<stdio.h>
#include<stdlib.h>
struct student 
{
	char usn[100];
	char name[100];
	char branch[100];
	int sem;
	int phno;
	struct student *link; /* basically this portion contains data and link and since link contains address of next node we take it as 
	a pointer and  make its data type as struct student becoz the data type of the node is also the same */
	
};
typedef struct student *STUDENT ;
 STUDENT start=NULL;
STUDENT createnode()
{
	STUDENT getnode;
	getnode=(STUDENT)malloc(sizeof(struct student));
	printf("enter the student details\n");
	printf("enter usn\n");
	scanf("%s",getnode->usn);
	printf("enter name\n");
	scanf("%s",getnode->name);
	printf("enter branch\n");
	scanf("%s",getnode->branch);
	printf("enter sem\n");
	scanf("%d",&getnode->sem);
	printf("enter phone number\n");
	scanf("%d",&getnode->phno);

		getnode->link=NULL;
		return(getnode);
	
}
void createlist()
{
	int n,i;
	STUDENT node;

	printf("enter n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		node=createnode();
		if(start==NULL)
			start=node;
		else
		{
			node->link=start;
			start=node;
			return;

		}


	}	
		
	
}
void display()
{
	STUDENT temp;
	int count=0;
	temp=start;
	while(temp!=NULL)
	{
		count++;
		printf("%s\n%s\n%s\n%d\n%d\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
		temp=temp->link;

	}
	printf("the number of nodes are %d",count);
}
void insertfront()
{
	STUDENT node;
	node=createnode();
	if(start==NULL)
	{
		start=node;
		return;
	}
	else
	{
		node->link=start;
		start=node;

	}	
}
void insertend()
{
	STUDENT node;
		node=createnode();
	STUDENT temp;
		temp=start;
	if(start==NULL)
	{
		start=node;
		return;
	}
	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=node;

	}
}
void deletefront()
{
		STUDENT temp;
		temp=start;
	if(start==NULL)
	{
		printf("empty list\n");
		return;
	}

	else if(start->link==NULL)
	{
		printf("the deleted element is %s\n",temp->usn);
		free(temp);
	}
	else
	{
		start=temp->link;
		printf("the deleted element is %s\n",temp->usn);
		free(temp);

	}
}
void deleteend()
{
	STUDENT temp,cur;
	temp=start;
	if(temp==NULL)
	{
		printf("list is empty\n");
		return;
	}
	else if(temp->link==NULL)
	{
		printf("the deleted element is %s\n",temp->usn);
		free(temp);
		start=NULL;
	}
	else
	{
		while(temp->link!=NULL)
		{
			cur=temp;
			temp=temp->link;

		}
		printf("the deleted element is %s\n",temp->usn);
		free(temp);
		cur->link=NULL;
	}

}
void main()
{
	int n;
	while(1)
	{
		printf("enter your choice: 1. create\n 2.display\n3.insertfront\n4.insertend\n5.deletefront\n6.deleteend\n7.exit");
		scanf("%d",&n);
		switch(n)
		{
			case 1: createlist();
					break;
			case 2: display();
					break;
			case 3: insertfront();
					break;
			case 4: insertend();
					break;
			case 5: deletefront();
					break;
			case 6: deleteend();
					break;
			case 7: exit(0);
					break;
			default: printf("invalid choice\n");
																						
		}
	}
}
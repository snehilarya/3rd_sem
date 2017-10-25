#include<stdio.h>
#include<stdlib.h>
struct emp{
	char ssn[20],name[20],designation[10],dept[10];
	struct emp *llink,*rlink;
};
typedef struct emp *employee;
employee start =NULL;
employee create_employee()
{
	employee new;
	new = (employee)malloc(sizeof(struct emp));
	printf("\nenter employee ssn: ");
	scanf("%s",new->ssn);
	printf("\nenter employee name: ");
	scanf("%s",new->name);
	printf("\nenter designation: ");
	scanf("%s",new->designation);
	printf("\nenter department: ");
	scanf("%s",new->dept);
	new->llink = NULL;
	new->rlink = NULL;
	return new;
}

void create_list()
{
	int i,n;
	printf("enter number of employees: ");
	scanf("%d", &n);
	employee node,temp;
	for(i=0;i<n;i++)
	{
		node = create_employee();
		if(start == NULL)
		{
			start = node;
		}
		else{
			temp = start;
			while(temp->rlink!=NULL)
			temp = temp->rlink;
			temp->rlink = new;
			new->llink = temp;
		}
	}
}

void status()
{
	employee temp;
	if(start == NULL)
	{
		printf("\nno employees list avilable");
		return;
	}
	temp=start;
	while(temp!=NULL)
	{
		printf("\n%s\n%s\n%s\n%s\n\n",temp->ssn,temp->name,temp->designation,temp->dept);
		temp = temp->rlink;
	}	
}
void insert_end()
{
	employee new,temp;
	new = create_employee();
	temp = start;
	while(temp->rlink!=NULL)
	{
		temp = temp->rlink;
	}
	temp->rlink = new;
	new->llink = temp;
}

void del_end()
{
	employee temp;
	temp=start;
	while(temp->rlink!=NULL)
	{
		temp = temp->rlink;
	}
	temp->llink->rlink = NULL;
	free(temp);
}
void insert_front()
{
	employee new;
	new = create_employee();
	new->rlink = start;
	start->llink = new;
	start = new;
}
void del_front()
{
	if(start == NULL)
	{
		printf("\nempty list");
		return;
	}
	employee temp;
	temp = start;
	start = start->rlink;
	start->llink = NULL;
	free(temp);
}
void queue()
{
	int i;
	printf("\ndouble ended queue operations:");
	printf("\n1.insert front \n2.delete front\n3.insert end\n4.delete end\n5.exit queue\n6.display\n");
	while(1)
	{
		printf("\nenter your choice: ");
		scanf("%d",&i);
		switch(i)
		{
			case 1: insert_front();
			break;
			case 2: del_front();
			break;
			case 3: insert_end();
			break;
			case 4: del_end();
			break;
			case 6: status();
			break;
			case 5: return;
			default:printf("\ninvalid choice!!!");
		}
	}
	
}
void main()
{
	int i;
	while(1)
	{
	printf("\ndoubly linked list operations:");
	printf("\n1.create list\n2.display\n 3.insert end\n 4.insert front \n5.delete end\n6.delete front\n7.queue operations\n8.exit");
	
		printf("\nenter your choice:");
		scanf("%d",&i);
		switch(i)
		{
			case 1: create_list();
			break;
			case 2: status();
			break;
			case 3: insert_end();
			break;
			case 4: insert_front();
			break;
			case 5: del_end();
			break;
			case 6: del_front();
			break;
			case 7: queue();
			break;
			case 8: return;
			default: printf("\ninvalid chioce!!!");
		}
	}
}

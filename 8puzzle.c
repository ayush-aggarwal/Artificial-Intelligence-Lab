#include<stdio.h>
#include<malloc.h>
int i,j;
struct node
{
	int puzzle[3][3];
	struct node *link[40];
}*t1;
struct node1
{
	struct node *ptr;
	struct node1 *next;
}*n1,*start,*rear;
struct node *create_new_node()
{
	t1=(struct node *)malloc(sizeof(struct node *)*48);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&t1->puzzle[i][j]);
	for(i=0;i<40;i++)
		t1->link[i]=NULL;
	return t1;
}
struct node1 *create_new_node1(struct node *temp)
{
	n1=(struct node1 *)malloc(sizeof(struct node1 *));
	n1->ptr=temp;
	n1->next=NULL;
	return n1;
}
void insert(struct node1 *temp)
{
	if(start==NULL)
		start=rear=temp;
	else
	{
		rear->next=temp;
		rear=temp;
	}
}
void display()
{
	struct node1 *t=start;
	while(t!=NULL)
	{
		for(i=0;i<3;i++)
		{	
			for(j=0;j<3;j++)
				printf("%d\t",t->ptr->puzzle[i][j]);
			printf("\n");
		}
		t=t->next;
	}
}
void main()
{
	start=rear=NULL;
	struct node *initial, *goal;
	struct node1 *s;
	printf("\nEnter Initial State:- \n");
	initial=create_new_node();
	s=create_new_node1(initial);
	insert(s);
	printf("\nEnter Goal State:- \n");
	goal=create_new_node();
	display();
}

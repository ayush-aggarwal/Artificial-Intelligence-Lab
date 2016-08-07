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
struct node *create_new_node(int arr[][3])
{
	t1=(struct node *)malloc(sizeof(struct node *)*48);
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			t1->puzzle[i][j]=arr[i][j];
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
		printf("----------->\n");
		t=t->next;
	}
}
void findpos(struct node *temp)
{
	int a,b,k,l,pos1,pos2,arr1[3][3],flag=0,ptrcount=0;
	struct node *te1;
	struct node1 *te2;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(temp->puzzle[i][j]==0)
			{
				flag=1;
				a=i;
				b=j;
				pos1=i;
				pos2=i;
				break;
			}
		}
		if(flag==1)
			break;
	}
	//printf("%d--%d",i,j);
	a=pos1-1;
	if(a>=0)
	{
		for(k=0;k<3;k++)
			for(l=0;l<3;l++)
				arr1[k][l]=temp->puzzle[k][l];
		arr1[pos1][pos2]=arr1[a][b];
		arr1[a][b]=0;
		te1=create_new_node(arr1);
		temp->link[ptrcount]=te1;
		ptrcount=ptrcount+1;
		te2=create_new_node1(te1);
		insert(te2);
	}
	a=pos1+1;
	if(a<=2)
	{
		for(k=0;k<3;k++)
			for(l=0;l<3;l++)
				arr1[k][l]=temp->puzzle[k][l];
		arr1[pos1][pos2]=arr1[a][b];
		arr1[a][b]=0;
		te1=create_new_node(arr1);
		temp->link[ptrcount]=te1;
		ptrcount=ptrcount+1;
		te2=create_new_node1(te1);
		insert(te2);
	}
	a=pos1;
	b=pos2+1;
	if(b<=2)
	{
		for(k=0;k<3;k++)
			for(l=0;l<3;l++)
				arr1[k][l]=temp->puzzle[k][l];
		arr1[pos1][pos2]=arr1[a][b];
		arr1[a][b]=0;
		te1=create_new_node(arr1);
		temp->link[ptrcount]=te1;
		ptrcount=ptrcount+1;
		te2=create_new_node1(te1);
		insert(te2);
	}
	b=pos2-1;
	if(b>=0)
	{
		for(k=0;k<3;k++)
			for(l=0;l<3;l++)
				arr1[k][l]=temp->puzzle[k][l];
		arr1[pos1][pos2]=arr1[a][b];
		arr1[a][b]=0;
		te1=create_new_node(arr1);
		temp->link[ptrcount]=te1;
		ptrcount=ptrcount+1;
		te2=create_new_node1(te1);
		insert(te2);
	}
	display();
}
void pop()
{
	struct node1 *p=start;
	//start=start->next;
	findpos(p->ptr);
}

void main()
{
	int arr[3][3];
	start=rear=NULL;
	struct node *initial, *goal;
	struct node1 *s;
	printf("\nEnter Initial State:- \n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&arr[i][j]);
	initial=create_new_node(arr);
	s=create_new_node1(initial);
	insert(s);
	display();
	printf("\n\nhere\n\n");
	/*printf("\nEnter Goal State:- \n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%d",&arr[i][j]);
	goal=create_new_node(arr);*/
	pop();
}

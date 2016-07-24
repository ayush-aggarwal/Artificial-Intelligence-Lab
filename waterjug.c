#include<stdio.h>
#include<malloc.h>
const int ju1=4,j2=3,req=0;
struct jugdata
{
	int jug1;
	int jug2;
}*p;
struct node
{
	struct jugdata *data;
	struct node *next[20];
}*n;
struct queuenode
{
	struct node *n1;
	struct queuenode *link;
}*start,*rear,*l;
struct jugdata* create_new_jugdata(int x, int y)
{
	p=(struct jugdata *)malloc(sizeof(struct jugdata*));
	p->jug1=x;
	p->jug2=y;
	return p;
}	
struct node* create_new_node(int x,int y)
{
	int i;
	n=(struct node*)malloc(sizeof(struct node*)*20);
	n->data=create_new_jugdata(x,y);
	for(i=0;i<20;i++)
	{
		n->next[i]=NULL;
	}
	//printf("%d - %d\n",n->data->jug1,n->data->jug2);
	return n;
}
struct queuenode* create_new_queuenode(struct node *ptr)
{
	l=(struct queuenode*) malloc(sizeof(struct queuenode*));
	l->n1=ptr;
	l->link=NULL;
	return l;
}
void insert_in_queue(struct queuenode *q)
{
	if(start==NULL)
		start=rear=q;
	else
	{
		rear->link=q;
		rear=q;
		printf("here");
	}
}
void display(struct queuenode *s)
{
	while(s!=NULL)
	{
		printf("%d - %d ->",s->n1->data->jug1,s->n1->data->jug2);
		s=s->link;
	}
}
void displaytree(struct node *ss)
{
	int a=0;
	while(ss->next[a]!=NULL)
	{
		printf("-----%d - %d ------",ss->next[a]->data->jug1,ss->next[a]->data->jug2);
		a=a+1;
	}
}
struct node* Fill_Jug1()
{
	int i;
	n=(struct node*)malloc(sizeof(struct node*)*20);
	n->data=create_new_jugdata(ju1,0);
	for(i=0;i<20;i++)
	{
		n->next[i]=NULL;
	}
	return n;
}
struct node* Fill_Jug2()
{
	int i;
	n=(struct node*)malloc(sizeof(struct node*)*20);
	n->data=create_new_jugdata(0,j2);
	for(i=0;i<20;i++)
	{
		n->next[i]=NULL;
	}
	return n;
}
int main()
{
	int c,i;
	start=NULL;
	rear=NULL;
	struct node *ptr,*init;
	struct jugdata *ju;
	struct queuenode *q,*q1;
	/*for(c=0;c<5;c++)                 TEST SUCCESS
	{
	ptr=create_new_node(c,c);
	q=create_new_queuenode(ptr);
	insert_in_queue(q);
	}
	display(start);*/ 
	init=create_new_node(0,0);
	ptr=Fill_Jug1();
	init->next[0]=ptr;
	q=create_new_queuenode(init->next[0]);
	insert_in_queue(q);
	ptr=Fill_Jug2();
	init->next[1]=ptr;
	displaytree(init);
	q=create_new_queuenode(init->next[1]);
	insert_in_queue(q);
	display(start);
	return 0;
}

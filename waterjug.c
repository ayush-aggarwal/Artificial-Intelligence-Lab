#include<stdio.h>
#include<malloc.h>
struct jugdata
{
	int jug1;
	int jug2;
}*p;
struct node
{
	struct jugdata *data;
	struct node *next[3];
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
	n=(struct node*)malloc(sizeof(struct node*));
	n->data=create_new_jugdata(x,y);
	for(i=0;i<3;i++)
	{
		n->next[i]=NULL;
	}
	printf("%d - %d\n",n->data->jug1,n->data->jug2);
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
int main()
{
	int a=2,b=3,c;
	start=NULL;
	rear=NULL;
	struct node *ptr;
	struct queuenode *q;
	for(c=0;c<15;c++)
	{
	ptr=create_new_node(c,c);
	q=create_new_queuenode(ptr);
	insert_in_queue(q);
	}
	display(start);
	return 0;
}

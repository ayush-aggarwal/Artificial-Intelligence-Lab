#include<stdio.h>
#include<malloc.h>
int ju1=4,j2=3,req=0,pj1=0,pj2=0;
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
struct node* Fill_Jug1(struct node *p)
{
	int i;
	n=(struct node*)malloc(sizeof(struct node*)*20);
	n->data=create_new_jugdata(ju1,p->data->jug2);
	pj1=ju1;
	pj2=p->data->jug2;
	for(i=0;i<20;i++)
	{
		n->next[i]=NULL;
	}
	return n;
}
struct node* Fill_Jug2(struct node *p)
{
	int i;
	n=(struct node*)malloc(sizeof(struct node*)*20);
	n->data=create_new_jugdata(p->data->jug1,j2);
	pj1=p->data->jug1;
	pj2=j2;
	for(i=0;i<20;i++)
	{
		n->next[i]=NULL;
	}
	return n;
}
struct node *TransferFromJug1ToJug2(struct node *p)
{
	int temp=j2-pj2;
	if(pj1>=temp)
	{
		pj2=pj2+temp;
		pj1=pj1-temp;
		p->data->jug1=pj1;
		p->data->jug2=pj2;
	}
	else
	{
		pj2=pj2+pj1;
		pj1=0;
		p->data->jug1=pj1;
		p->data->jug2=pj2;
	}
	return p;
}
struct node *EmptyJug2(struct node *p)
{
	pj2=0;
	p->data->jug2=0;
	return p;
}
struct node *TransferFromJug2ToJug1()
{
	int i,temp=ju1-pj1;
	if(pj2>=temp)
	{
		pj1=pj1+temp;
		pj2=pj2-temp;
	}
	else
	{
		pj1=pj1+pj2;
		pj2=0;
	}
	n=(struct node*)malloc(sizeof(struct node*)*20);
	n->data=create_new_jugdata(pj1,pj2);
	for(i=0;i<20;i++)
	{
		n->next[i]=NULL;
	}
	return n;
}
struct node *EmptyJug1(struct node *p)
{
	int i;
	pj1=0;
	pj2=p->data->jug2;
	n=(struct node*)malloc(sizeof(struct node*)*20);
	n->data=create_new_jugdata(pj1,pj2);
	for(i=0;i<20;i++)
	{
		n->next[i]=NULL;
	}
	return n;
}
void displaynode(struct node *p)
{
	printf("\n\n%d .....%d",p->data->jug1,p->data->jug2);
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
	printf("Jug1:- ");
	scanf("%d",&ju1);
	printf("Jug2:- ");
	scanf("%d",&j2);
	printf("Required:- ");
	scanf("%d",&req);
	init=create_new_node(0,0);
	q=create_new_queuenode(init);
	insert_in_queue(q);
	ptr=Fill_Jug1(init);
	init->next[0]=ptr;
	q=create_new_queuenode(init->next[0]);
	insert_in_queue(q);
	ptr=Fill_Jug2(init);
	init->next[1]=ptr;
	//displaytree(init);
	q=create_new_queuenode(init->next[1]);
	insert_in_queue(q);
	//display(start);
	init=init->next[1];
	ptr=TransferFromJug2ToJug1();
	//displaynode(ptr);
	init->next[0]=ptr;
	q=create_new_queuenode(init->next[0]);
	insert_in_queue(q);
	//free(ptr);
	//ptr=create_new_node(0,0);
	//displaynode(ptr);
	ptr=Fill_Jug1(init);
	init->next[1]=ptr;
	q=create_new_queuenode(init->next[1]);
	insert_in_queue(q);
	init=init->next[0];
	ptr=EmptyJug1(init);
	init->next[0]=ptr;
	q=create_new_queuenode(init->next[0]);
	insert_in_queue(q);
	ptr=TransferFromJug2ToJug1();
	init->next[0]=ptr;
	q=create_new_queuenode(init->next[0]);
	insert_in_queue(q);
	//displaytree(init);
	display(start);
	return 0;
}

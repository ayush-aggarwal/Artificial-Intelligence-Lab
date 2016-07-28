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
}*start,*rear,*l,*start1,*rear1;
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
		n->next[i]=NULL;
	return n;
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
void create_new_queuenode(struct node *ptr)
{
	l=(struct queuenode*) malloc(sizeof(struct queuenode*));
	l->n1=ptr;
	l->link=NULL;
	insert_in_queue(l);
}
void display(struct queuenode *s)
{
	while(s!=NULL)
	{
		printf("%d - %d ->",s->n1->data->jug1,s->n1->data->jug2);
		s=s->link;
	}
}

struct node* Fill_Jug1(struct node *p)
{
	n=create_new_node(ju1,p->data->jug2);
	pj1=ju1;
	pj2=p->data->jug2;
	return n;
}
struct node* Fill_Jug2(struct node *p)
{
	n=create_new_node(p->data->jug1,j2);
	pj1=p->data->jug1;
	pj2=j2;
	return n;
}
struct node *TransferFromJug1ToJug2(struct node *p)
{
	int temp=j2-p->data->jug2;
	if(p->data->jug1>=temp)
	{
		pj2=p->data->jug2+temp;
		pj1=p->data->jug1-temp;
	}
	else
	{
		pj2=p->data->jug2+p->data->jug1;
		pj1=0;
	}
	n=create_new_node(pj1,pj2);
	return n;
}
struct node *EmptyJug2(struct node *p)
{
	pj1=p->data->jug1;
	pj2=0;
	n=create_new_node(pj1,pj2);
	return n;
}
struct node *TransferFromJug2ToJug1(struct node *p)
{
	int temp=ju1-p->data->jug1;
	if(p->data->jug2>=temp)
	{
		pj1=p->data->jug1+temp;
		pj2=p->data->jug2-temp;
	}
	else
	{
		pj1=p->data->jug1+p->data->jug2;
		pj2=0;
	}
	n=create_new_node(pj1,pj2);
	return n;
}
struct node *EmptyJug1(struct node *p)
{
	pj1=0;
	pj2=p->data->jug2;
	n=create_new_node(pj1,pj2);
	return n;
}
void bfs()
{
	printf("%d %d",start->n1->data->jug1,start->n1->data->jug2);
}
int main()
{
	int c,i;
	start=NULL;
	rear=NULL;
	struct node *ptr,*init,*root;
	printf("Jug1:- ");
	scanf("%d",&ju1);
	printf("Jug2:- ");
	scanf("%d",&j2);
	printf("Required:- ");
	scanf("%d",&req);
	init=create_new_node(0,0);
	root=create_new_node(0,0);
	create_new_queuenode(init);
	ptr=Fill_Jug1(init);
	init->next[0]=ptr;
	create_new_queuenode(init->next[0]);
	ptr=Fill_Jug2(init);
	init->next[1]=ptr;
	create_new_queuenode(init->next[1]);
	root=init;
	init=root->next[0];
	ptr=TransferFromJug1ToJug2(init);
	init->next[0]=ptr;
	create_new_queuenode(init->next[0]);
	ptr=Fill_Jug2(init);
	init->next[1]=ptr;
	create_new_queuenode(init->next[1]);
	init=init->next[0];
	while(1)
	{
		if(init->data->jug2==j2)
			ptr=EmptyJug2(init);
		else if(init->data->jug1==0)
			ptr=Fill_Jug1(init);
		else
			ptr=TransferFromJug1ToJug2(init);
		if(ptr->data->jug1==root->data->jug1 && ptr->data->jug2==root->data->jug2)
			break;
		else
		{
			init->next[0]=ptr;
			create_new_queuenode(init->next[0]);
			init=init->next[0];
		}
	}
	init=root->next[1];  //......................
	ptr=TransferFromJug2ToJug1(init);
	init->next[0]=ptr;
	create_new_queuenode(init->next[0]);
	ptr=Fill_Jug1(init);
	init->next[1]=ptr;
	create_new_queuenode(init->next[1]);
	init=init->next[0];	
	while(1)
	{
		if(init->data->jug1==ju1)
			ptr=EmptyJug1(init);
		else if(init->data->jug2==0)
			ptr=Fill_Jug2(init);
		else
			ptr=TransferFromJug2ToJug1(init);
		if(ptr->data->jug1==root->data->jug1 && ptr->data->jug2==root->data->jug2)
			break;
		else
		{
		init->next[0]=ptr;
		create_new_queuenode(init->next[0]);
		init=init->next[0];
		}
	}
	display(start);
	bfs();
	return 0;
}

#include<stdio.h>
#include<malloc.h>
int ju1=4,j2=3,req=0,pj1=0,pj2=0,reqjug=1;
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
struct stacknode
{
	struct node *n1;
	struct stacknode *link;
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
		n->next[i]=NULL;
	return n;
}
void insert_in_stack(struct stacknode *q)
{
	if(start==NULL)
		start=q;
	else
	{
		q->link=start;
		start=q;
	}
}
void create_new_stacknode(struct node *ptr)
{
	l=(struct stacknode*) malloc(sizeof(struct stacknode*));
	l->n1=ptr;
	l->link=NULL;
	insert_in_stack(l);
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
struct node *pop()
{
	struct stacknode *p=start;
	if(start->link)
		start=start->link;
	else
		start=NULL;
	return p->n1;
}
void dfs(struct node *rt,int req,int reqjug)
{
	struct node *tempnode=rt;
	int a=1;
	struct stacknode *q2;
	while(1)
	{
		while(tempnode!=NULL)
		{
			printf("%d--%d->",tempnode->data->jug1,tempnode->data->jug2);
			switch(reqjug)
			{
				case 1:	
						if(tempnode->data->jug1==req && tempnode->data->jug2==0)
							printf("\nSolution Found in %d steps\n",a);
						break;
				case 2:
						if(tempnode->data->jug1==0 && tempnode->data->jug2==req)
							printf("\nSolution Found in %d steps\n",a);
						break;
			}
			if(tempnode->next[1])
				create_new_stacknode(tempnode);
			tempnode=tempnode->next[0];
			a=a+1;
		}
		if(start==NULL)
			break;
		tempnode=pop();
		tempnode=tempnode->next[1];
	}
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
	printf("Requirement Jug:- ");
	scanf("%d",&reqjug);
	init=create_new_node(0,0);
	root=create_new_node(0,0);
	ptr=Fill_Jug1(init);
	init->next[0]=ptr;
	ptr=Fill_Jug2(init);
	init->next[1]=ptr;
	root=init;
	init=root->next[0];
	ptr=TransferFromJug1ToJug2(init);
	init->next[0]=ptr;
	ptr=Fill_Jug2(init);
	init->next[1]=ptr;
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
			init=init->next[0];
		}
	}
	init=root->next[1]; 
	ptr=TransferFromJug2ToJug1(init);
	init->next[0]=ptr;
	ptr=Fill_Jug1(init);
	init->next[1]=ptr;
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
		init=init->next[0];
		}
	}
	dfs(root,req,reqjug);
	return 0;
}

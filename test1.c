
#include<stdio.h>
#include<stdlib.h>



typedef struct student{
	char name[20];
	int score;
	struct student *node;//creat the node name;
}Stu;

//function declaration

Stu *creat1();//creat 1 node
Stu *creatList(int n);
void addtAfter(Stu *list, int n);
void deleteNode(Stu *list,int n);
void viewNode(Stu *list,int n);
void changeNode(Stu *list,int n);
void putList(Stu *head);
void linksOper();

void main()
{
	linksOper();//整个链表操作
}


//prepare for link-list;
Stu *creat1()//make up 1 nodes;
{
	Stu *p;
	p = (Stu *)calloc(1,sizeof(Stu) );
	scanf("%s%d",p->name,&(p->score) );
	p->node= NULL;
	return p;
}
Stu *creatList(int n)//make up lists;
{
	puts("Input name and score:");
	Stu *head,*end,*p;
	int i;
	if ( n>=1 )
	{
		p = creat1();
		head = p;
		end = p;
	}
	for ( i = 2; i <= n; i++ )
	{
		end = creat1();
		p -> node = end;
		p = end;
	}
	if ( n >= 1)
		return head;
	else 
		return NULL;
}
//linklinks oper；
void addAfter(Stu *list, int n)
{
	Stu *p = list, *in;
	int i = 1;
	while ( i <= n && p != NULL)
	{
		p = p->node;
		i++;
	}
	if ( p != NULL )
	{
		in = (Stu *)malloc(sizeof(Stu) );
		puts("input name and score");
		scanf("%s%d",in->name,&(in->score) );
		in->node = p->node;
		p->node = in;
	}
	else
		puts("node not exits");

}
//删除节点
void deleteNode(Stu *list,int n)
{
	Stu *de,*p;
	de = list;
	int i = 0;
	while ( i < n && de != NULL )
	{
		p = de;
		de = de->node;
		i++;
	}
	if ( de != NULL)
	{
		p->node = de ->node;
		free(de);
	}
	else
		puts("delete's node was not exit");

}
//查询节点
void viewNode(Stu *list,int n)
{
	Stu *vi = list;
	int i = 0;
	while ( i < n && vi != NULL )
	{
		vi = vi->node;
		i++;
	}
	if ( vi != NULL )
		printf("%s %d\n",vi->name,vi->score);
	else
		puts("not exit the node");

}
//改变结点
void changeNode(Stu *list,int n)
{
	Stu *ch;
	ch = list;
	int i = 0;
	while ( i < n && ch != NULL )
	{
		ch = ch->node;
		i++;

	}
	if ( ch != NULL )
	{
		puts("input new name and score");
		scanf("%s%d",ch->name,&(ch->score) );
	}
	else
		puts("put nodes not exit");
}


//输出链表
void putList(Stu *head)
{
	Stu *p;
	if (head != NULL)
	{
		p = head;
		while(p!=NULL)
		{
			printf("%s %d\n",p->name,p->score);
			p = p->node;
		}
	}
}
//all oper of linklist
void linksOper()
{

	int num,i,de,n=1,m=1;
	Stu *head = NULL;
	puts("puts the num of lisks");
	scanf("%d",&num);
	head = creatList(num);
	while(m)
	{
		puts("choose your oper:");
		puts("1:add. 2:delete. 3:find: 4:change. 5:ends and puts all.");
		while(n)
		{
			scanf("%d",&de);
			if ( de <= 5 && de >= 1)
				n = 0;
			else
				puts("puts error");
		}
		
		switch(de)
		{
		case 1:
			{
				  puts("add size start from 0:");
				  scanf("%d",&i);
				  addAfter(head,i);
				  n = 1;
			}
			break;
		case 2:
			{
				  puts("delete size start from 0:");
				  scanf("%d",&i);
				  deleteNode(head,i);
				  n = 1;
			}
			break;
		case 3:
			{
				  puts("put view size start from 0:");
				  scanf("%d",&i);
				  viewNode(head,i);
				  n = 1;
			}
			break;
		case 4:
			{
				  puts("put change size start from 0:");
				  scanf("%d",&i);
				  changeNode(head,i);
				  n = 1;
			}
			break;
		case 5:
			m = 0;
			break;
		default :  
			{
				puts("big error !");
				break;
			}
		}
	}

	printf("start puts all\n");
	putList(head);

}

11111
	1111111111

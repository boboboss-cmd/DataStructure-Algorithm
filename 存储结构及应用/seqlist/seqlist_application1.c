#include<stdio.h> //scanf,printf
#include<stdlib.h> //exit
#include<malloc.h> //malloc

/*
1.头插法尾插法建立链表
2.逆置
3.取最值
4.归并
5.划分
*/

//定义ADT
typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*Linklist;

/*1.创建链表*/

//头插法（顺序输入,倒序输出）
Linklist creatLinklistH(LNode *head)
{
	LNode *s = NULL;
	int n;
	printf("请输入整数n：");
	scanf("%d",&n);
	//为头结点分配空间
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	if(head == NULL)
	{
		printf("分配空间失败\n");
		exit(-1);
	}
	//循环分配空间
	for(int i=0;i<n;++i)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->next = NULL;
		printf("请输入元素值：");
		scanf("%d ",&(s->data));
		s->next = head->next;
		head->next = s;
	}
	return head;
}

//尾插法（顺序输入,顺序输出）
Linklist creatLinklistR(LNode *head)
{
	head = (LNode *)malloc(sizeof(LNode));
	head->next = NULL;
	if(head == NULL)
	{
		printf("空间分配失败\n");
		exit(0);
	}

	LNode *p = NULL;//用来申请新的结点
	LNode *r =head;//用来获取当前的尾结点
	int n;//输入结点的总数
	printf("请输入整数n：");
	scanf("%d",&n);

	for(int i=0;i<n;++i)
	{
		p = (LNode *)malloc(sizeof(LNode));
		p->next = NULL;
		printf("请输入元素值：");
		scanf("%d",&(p->data));
		//p->next = r->next;
		r->next = p;
		r = p;
	}
	return head;
}

/*2.逆置*/
Linklist seqlistReverse(LNode *head)
{
	//先找出最后一个结点
	LNode *r = head;
	LNode *p = r;
	LNode *h = NULL;
	while(p != NULL)
	{
		r = p;
		p = p->next;
	}
	//将头结点后的第一个元素插入到最后一个元素的后面
	while(head->next != r)
	{
		h = head->next;
		head->next = h->next;
		h->next = r->next;
		r->next = h;
	}
	return head;
}

/*3.取最值*/
//最大值
int maxElem(LNode *head)
{
	LNode *p = head->next;
	LNode *q = p->next;
	int max = p->data;
	while(q != NULL)
	{
		if(q->data >= max)
		{
			max = q->data;
			p = q;
		}
		q = q->next;
	}
	return max;
}
//最小值
int minElem(LNode *head)
{
	LNode *p = head->next;
	LNode *q = p->next;
	int min = p->data;
	while(q != NULL)
	{
		if(q->data <= min)
		{
			min = q->data;
			p = q;
		}
		q = q->next;
	}
	return min;
}

/*4.归并*/
//尾插法合并有序表
Linklist mergerElemR(LNode *A,LNode *B,LNode *&C)
{
	LNode *r = NULL;
	LNode *p = A->next;
	LNode *q = B->next;

	C = A;
	C->next = NULL;

	free(B);

	r = C;
	
	while(p != NULL && q != NULL)
	{
		if(p->data <= q->data)
		{
			r->next = p;
			p = p->next;
			r = r->next;
		}
		else
		{
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	
	if(p != NULL)
	{
		r->next = p;
	}
	
	if(q != NULL)
	{
		r->next = q;
	}

	return C;
}

//头插法合并有序表
Linklist mergerElemH(LNode *A,LNode *B,LNode *&C)
{
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *s = NULL;

	C = A;
	C->next = NULL;

	free(B);

	while(p != NULL && q != NULL)
	{
		if(p->data <= q->data)
		{
			s = p;
			p = p->next;
			s->next = C->next;
			C->next = s;
		}
		else
		{
			s = q;
			q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}

	while(p != NULL)
	{
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}

	while(q != NULL)
	{
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}

	return C;
}

/*5.划分*/

//打印线性表元素
void printElem(LNode *head)
{
	LNode *p = head->next;
	printf("线性表内元素依次为：\n");
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LNode data1,data2,*head=NULL,*l = NULL;
	LNode *A = NULL, *B = NULL;
	int max,min;
	//head = creatLinklistR(&data);
	//head = creatLinklistH(&data);
	//printElem(head);
	//max = maxElem(head);
	//min = minElem(head);
	//printf("最大值为：%d\n",max);
	//printf("最小值为：%d\n",min);
	//l = seqlistReverse(head);
	//printElem(l);
	A = creatLinklistR(&data1);
	printElem(A);
	B = creatLinklistR(&data2);
	printElem(B);
	//l = mergerElemR(A,B,head);
	l = mergerElemH(A,B,head);
	printf("合并的结果\n");
	printElem(l);
	return 0;
}

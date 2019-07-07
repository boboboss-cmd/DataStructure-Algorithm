#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/*循环队列链式存储的基本操作
1.初始化
2.销毁队列
3.清空队列
4.判断队空
5.判断队满
6.元素入队
7.元素出队
8.计算队列元素个数
9.遍历队列元素
*/

//定义队列结点
typedef struct QNode
{
	int data;
	struct QNode *next;
}QNode;

//定义队列
typedef struct
{
	QNode *front;//定义队头指针
	QNode *rear;//定义队尾指针
}LinkQueue;

//1.初始化队列
void InitLinkQueue(LinkQueue *Q)
{
	Q->front = (QNode *)malloc(sizeof(QNode));
	Q->rear = Q->front;
	if(Q->front == NULL)
	{
		exit(-1);//分配失败
	}
	Q->front->next = NULL;
}

//2.销毁队列
void DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{	
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}

//3.清空队列(保留头指针)
void clearQueue(LinkQueue *Q)
{
	QNode *p = NULL,*q = NULL;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

//4.判断队空
void isLinkQueueNULL(LinkQueue *Q)
{
	if(Q->front == Q->rear)
		printf("队空");
}

//5.判断队满
//无需进行判断

//6.元素入队
void EnLinkQueue(LinkQueue *Q,int x)
{
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if(p == NULL) exit(-1);
	p->data = x;
	p->next = NULL;	
	Q->rear->next = p;
	Q->rear = p;
}

//7.元素出队
void DeLinkQueue(LinkQueue *Q,int *y)
{
	//先判断是否队空
	if(Q->front == Q->rear) exit(-1);
	QNode *q = Q->front->next;
	*y = q->data;
	Q->front->next = q->next;
	//考虑删除的结点为最后一个结点即尾结点
	if(Q->rear == q) Q->rear = Q->front;
	free(q);
}

//8.计算队列元素个数
int calQNode(LinkQueue *Q)
{
	int i = 0;
	QNode *f = Q->front->next;
	while(f != NULL)
	{
		f = f->next;
		++i;
	}
	return i;
}
//9.遍历队列元素
void LinkQueueTrave(LinkQueue *Q)
{
	QNode *q = Q->front->next;
	int e;
	while(q != NULL)
	{
		e = q->data;
		printf("%d ",e);
		q = q->next;	
	}
	printf("\n");
}

int main()
{
	LinkQueue Q;
	int i = 1;
	int y;
	int n;
	int c;
	
	InitLinkQueue(&Q);//初始化
	
	printf("---------------------------\n");
	printf("元素入队操作\n");
	printf("---------------------------\n");

	printf("请输入要输入的元素个数：");
	scanf("%d",&n);

	while(i <= n)
	{
		int elem;
		printf("输入的第%d元素是：",i);
		scanf("%d",&elem);
		EnLinkQueue(&Q,elem);//元素入队
		++i;
	}

	c = calQNode(&Q);//统计元素个数
	printf("链表中元素的个数为:%d\n",c);
	
	printf("链表元素是: ");
	LinkQueueTrave(&Q);

	printf("---------------------------\n");
	printf("元素出队操作\n");
	printf("---------------------------\n");

	DeLinkQueue(&Q,&y);
	printf("出队元素为：%d\n",y);
	c = calQNode(&Q);//统计元素个数
	printf("链表中元素的个数为:%d\n",c);
	
	printf("链表元素是: ");
	LinkQueueTrave(&Q);

	return 0;
}

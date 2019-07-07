#include<stdio.h>

#define maxsize 11

/*循环队列顺序存储的基本操作
1.初始化
2.清空队列
3.判断队空
4.判断队满
5.元素入队
6.元素出队
7.计算队列元素个数
8.遍历队列元素
*/

//定义队列数据结构
typedef struct 
{
	int data[maxsize];
	int front;//头指针
	int rear;//尾指针
}SqQueue;

//1.初始化
void Init_SqQueue(SqQueue *SQ)
{
	SQ->front = 0;
	SQ->rear = 0;
}

//2.清空队列
void clear_SqQueue(SqQueue SQ)
{
	SQ.front = SQ.rear = 0;
}

//3.判断队空
int isSqueueNull(SqQueue SQ)
{
	if(SQ.front == SQ.rear)
	{
		printf("队空");
		return 1;
	}
	return 0;
}

//4.判断队满
int isSqueueFull(SqQueue SQ)
{
	if(SQ.front == (SQ.rear+1)%maxsize)
	{
		printf("队满");
		return 1;
	}
	return 0;
}

//5.元素入队
int EnSqueue(SqQueue *SQ, int x)
{
	//先判断是否队满
	if(SQ->front == (SQ->rear+1)%maxsize) return 0;
	//入队
	SQ->rear = (SQ->rear+1)%maxsize;
	SQ->data[SQ->rear] = x;
	return 1;
}

//6.元素出队
int DeSqueue(SqQueue *SQ, int *y)
{
	//先判断是否队空
	if(SQ->front == SQ->rear) return 0;
	//出队
	SQ->front = (SQ->front+1)%maxsize;
	*y = SQ->data[SQ->front];
	return 0;
}

//7.计算元素个数
int calElem(SqQueue SQ)
{
	int i;
	i = (SQ.rear-SQ.front+maxsize)%maxsize;
	return i;
}

//8.遍历队列元素
void ElemTrave(SqQueue SQ)
{	
	printf("队列元素：");
	while(SQ.front != SQ.rear)
	{
		SQ.front = (SQ.front+1)%maxsize;
		printf("%d ",SQ.data[SQ.front]);
	}
	printf("\n");
}

int main()
{
	SqQueue SQ;//定义队列
	int x;//定义入队元素
	int s;//接收元素个数
	int n;//输入元素的个数
	int i = 1;
	int y;//接收出队元素

	Init_SqQueue(&SQ);//初始化

	printf("请输入要输入的元素个数：");
	scanf("%d",&n);

	printf("请输入元素:\n");
	while(i <= n)
	{	
		int elem;
		printf("第%d个元素:",i);
		scanf("%d",&elem);
		EnSqueue(&SQ,elem);	
		++i;
	}
	
	s = calElem(SQ);//统计元素个数
	printf("队列中元素的个数为：%d\n",s);
	ElemTrave(SQ);//遍历队列内元素

	DeSqueue(&SQ,&y);//元素出队
	printf("出队元素为：%d\n",y);

	s = calElem(SQ);//统计元素个数
	printf("队列中元素的个数为：%d\n",s);
	ElemTrave(SQ);//遍历队列内元素

	return 0;
}
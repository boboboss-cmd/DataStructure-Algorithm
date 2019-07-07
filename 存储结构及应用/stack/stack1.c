#include<stdio.h>	//scanf,printf
#include<malloc.h> //malloc
#include<stdlib.h> //exit

/*链栈的基本操作*/
#define true 1
#define false 0

//1.定义栈的ADT
//定义结点
typedef struct Node
{
	int data;
	struct Node *next;
}Node, *pNode; //*pNode指向指针的指针
//由结点组成栈
typedef struct Stack
{
	pNode Top; //栈顶指针
	pNode Bottom; //栈底指针
}Stack, *pStack;

//2.栈的初始化
//定义一个头结点，让栈顶栈底指针都指向该头结点
void stack_init(pStack s)
{
	// 分配空间，判断是否分配成功
	s->Top = (pNode)malloc(sizeof(Node));
	if(s->Top == NULL)
	{
		printf("分配空间失败\n");
		exit(-1);
	}
	else
	{// 让栈底指针指向头节点，头节点域置为空
		s->Bottom = s->Top;
		s->Top->next = NULL;
	}
	return ;
}

//3.入栈操作
void stack_push(pStack s, int x)
{	
	pNode l = (pNode)malloc(sizeof(Node));
	l->data = x;
	l->next = s->Top;
	s->Top = l;
	return ;
}

//4.出栈
//先判断栈是否空
void stack_pop(pStack s)
{
	if(s->Top == s->Bottom)
	{
		printf("栈空\n");
		exit(-1);
	}
	pNode q = s->Top;
	s->Top = s->Top->next;
	free(q);
	return ;
}


//5.栈的遍历
void stack_scan(pStack s)
{
	pNode p = s->Top;

	printf("栈内元素为：");
	while(p != s->Bottom)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
	return ;
}

//6.判断栈是否为空
int is_empty(pStack s)
{
	if(s->Top == s->Bottom)
		return true;
	else
		return false;
}

//7.清空栈
void clear_stack(pStack s)
{
	if(is_empty(s))
	{
		return ;
	}
	else
	{
		while(s->Top != s->Bottom)
		{
			pNode p = s->Top;
			s->Top = s->Top->next;
			free(p);
		}		
	}
}

//主函数 
int main()
{
	Stack s;
	int x;

	stack_init(&s);
	
	stack_push(&s,1);
	stack_push(&s,2);
	stack_push(&s,3);
	stack_push(&s,4);
	
	stack_scan(&s);

	stack_pop(&s);

	stack_scan(&s);

	clear_stack(&s);

	stack_scan(&s);

	return 0;

}
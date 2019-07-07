#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define maxsize 100
/*
1.建树
2.二叉树的遍历-递归算法
3.二叉树的遍历-非递归算法
4.二叉树的遍历-层次遍历
5.二叉树的深度
6.二叉树的结点个数
*/

typedef struct BiTNode
{
	char data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode;

//1.建树
// 用先序遍历建立二叉树
BiTNode *CreatBiTree()
{
	BiTNode *root=NULL;

	char ch;

	scanf("\n%c",&ch);

	if(ch == '#')
	{
		root = NULL;	
	}
	else
	{
		root = (BiTNode *)malloc(sizeof(BiTNode));
		root->data = ch;
		printf("请输入%c左孩子的内容：",ch);
		root->lchild = CreatBiTree();
		printf("请输入%c右孩子的内容：",ch);
		root->rchild = CreatBiTree();
	}

	return root;

}

//2.二叉树的遍历-递归算法
//先序遍历
void Preorder(BiTNode *root)
{
	if(root == NULL)
		return ;
	printf("%c ",root->data);
	Preorder(root->lchild);
	Preorder(root->rchild);
}

//中序遍历
void Inorder(BiTNode *root)
{
	if(root == NULL)
		return ;
	Inorder(root->lchild);
	printf("%c ",root->data);
	Inorder(root->rchild);
}

//后序遍历
void Postorder(BiTNode *root)
{
	if(root == NULL)
		return ;
	Postorder(root->lchild);
	Postorder(root->rchild);
	printf("%c ",root->data);
}

// 3.二叉树遍历-非递归算法
//先序遍历非递归
void UNPreorder(BiTNode *root)
{
	BiTNode *stack[maxsize];
	int top = -1;

	BiTNode *p = NULL;
	stack[++top] = root;
	while(top != -1)
	{
		p = stack[top--];
		printf("%c ",p->data);
		
		if(p->rchild != NULL)
			stack[++top] = p->rchild;
		
		if(p->lchild != NULL)
			stack[++top] = p->lchild;
	}
}

//中序遍历非递归
void UNInorder(BiTNode *root)
{
	BiTNode *stack[maxsize];
	int top  = -1;

	BiTNode *p = NULL;

	p = root;

	while(top != -1 || p != NULL)
	{
		while(p != NULL)
		{
			stack[++top] = p;	
			p = p->lchild;
		}
		
		if(top != -1)
		{
			p = stack[top--];
			printf("%c",p->data);
			p = p->rchild;
		}
	}
}

// 后序遍历非递归
void UNPostorder(BiTNode *root)
{
	BiTNode *stack1[maxsize];
	int top1  = -1;

	BiTNode *stack2[maxsize];
	int top2  = -1;
	
	BiTNode *p = NULL;

	stack1[++top1] = root;
	
	while(top1 != -1)
	{
		p = stack1[top1--];
		stack2[++top2] = p;

		if(p->lchild != NULL)
			stack1[++top1] = p->lchild;
		
		if(p->rchild != NULL)
			stack1[++top1] = p->rchild;
	}
	while(top2 != -1)
	{
		p = stack2[top2--];
		printf("%c ",p->data );
	}
}

// 4.层次遍历
void Leave(BiTNode *root)
{
	BiTNode *p = NULL;

	BiTNode *queue[maxsize];
	int front,rear;
	front = rear =0;

	rear = (rear+1)%maxsize;
	queue[rear] = root;

	while(front != rear)
	{
		front = (front+1)%maxsize;
		p = queue[front];
		printf("%c ",p->data);

		if(p->lchild != NULL)
		{
			rear = (rear+1)%maxsize;
			queue[rear] = p->lchild;
		}

		if(p->rchild != NULL)
		{
			rear = (rear+1)%maxsize;
			queue[rear] = p->rchild;
		}
	}
}
// 5.二叉树深度

// 6.二叉树结点数


int main()
{
	BiTNode *root = NULL;

	int flag = 1,k;
	
	while(flag)
	{
		//构造界面
		printf("==================================================\n");
		printf("|               二叉树的基本操作：               |\n");
		printf("|                0.创建二叉树                    |\n");
		printf("|                1.二叉树的递归先序遍历          |\n");
		printf("|                2.二叉树的递归中序遍历          |\n");
		printf("|                3.二叉树的递归后序遍历          |\n");
		printf("|                4.二叉树的非递归先序遍历        |\n");
		printf("|                5.二叉树的非递归中序遍历        |\n");
		printf("|                6.二叉树的非递归后序遍历        |\n");
		printf("|                7.二叉树的层次遍历              |\n");
		printf("|                8.二叉树的深度                  |\n");
		printf("|                9.二叉树的结点个数              |\n");
		printf("|                10.退出系统                     |\n");
		printf("==================================================\n");
		printf("请选择要执行的操作:");
		scanf("%d",&k);
		switch(k)
		{
			case 0:
				printf("请输入根结点的内容：");
				root = CreatBiTree();
				break;
			
			case 1:
				printf("-----------------------------------\n");
				printf("递归先序遍历的结果为：");
				Preorder(root);
				printf("\n---------------------------------\n");
				break;
			
			case 2:
				printf("-----------------------------------\n");
				printf("递归中序遍历的结果为：");
				Inorder(root);
				printf("\n---------------------------------\n");
				break;
			
			case 3:
				printf("-----------------------------------\n");
				printf("递归后序遍历的结果为：");
				Postorder(root);
				printf("\n---------------------------------\n");
				break;
			case 4:
				printf("-----------------------------------\n");
				printf("非递归先序遍历的结果为：");
				UNPreorder(root);
				printf("\n---------------------------------\n");
				break;
			case 5:
				printf("-----------------------------------\n");
				printf("非递归中序遍历的结果为：");
				UNInorder(root);
				printf("\n---------------------------------\n");
				break;
			case 6:
				printf("-----------------------------------\n");
				printf("非递归后序遍历的结果为：");
				UNPostorder(root);
				printf("\n---------------------------------\n");
				break;
			case 7:
				printf("-----------------------------------\n");
				printf("层次遍历的结果为：");
				Leave(root);
				printf("\n---------------------------------\n");
				break;
			default:
				flag = 0;
				printf("程序运行结束，请按任意键退出！\n");
		}
	}
	return 0;
}
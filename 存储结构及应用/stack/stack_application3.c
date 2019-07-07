#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define maxsize 100

/*
顺序栈的应用
1.表达式求值
2.表达式转换
3.括号匹配
4.分段函数计算
*/

/*3.括号匹配*/
//比较栈中和当前扫描的括号是否匹配
int isMatched(char left, char right)
{
	if(left == '(' && right == ')') return 1;
	if(left == '[' && right == ']') return 1;
	if(left == '{' && right == '}') return 1;
	return 0;
}

int isParethesesBalanced(char exp[])
{
	char stack[maxsize];
	int top = -1;

	int i = 0;

	while(exp[i] != '\0')
	{
		if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
		{
			stack[++top] = exp[i++];
		}
		else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if(top == -1) return 0;
			char left = stack[top--];
			if(isMatched(left,exp[i]) == 0) return 0;
			++i;
		}
		else
		{
			++i;
		}
	}
	if(top >-1) return 0;
	return 1;
}

int main()
{
	char exp[maxsize];
	int flag;

	printf("请输入表达式：");
	scanf("%s",exp);
	printf("您输入的表达式为：%s\n",&exp[0]);

	flag = isParethesesBalanced(exp);
	
	if(flag == 1) 
	{
		printf("匹配成功\n");
	}
	else
	{
		printf("匹配失败\n");
	}

	return 0;
}
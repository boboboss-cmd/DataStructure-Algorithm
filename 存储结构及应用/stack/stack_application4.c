#include<stdio.h>

#define maxsize 100

/*
顺序栈的应用
1.表达式求值
2.表达式转换
3.括号匹配
4.分段函数计算
*/

/*4.分段函数计算*/
int calF(int m)
{
	int stack[maxsize];
	int top = -1;

	int sum = 1;

	while(m != 0)
	{
		stack[++top] = m;
		m/=3;
	}
	while(top != -1)
	{
		sum = sum * stack[top--];
	}
	return sum;
}

int main()
{
	int m,result;
	
	printf("请输入要计算的值：");
	scanf("%d",&m);
	
	result = calF(m);
	printf("%d\n", result);
	return 0;
}
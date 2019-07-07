#include<stdio.h>
#include<string.h>

#define maxsize 100

/*
顺序栈的应用
1.表达式求值
2.表达式转换
3.括号匹配
4.分段函数计算
*/

/*2.表达式转换*/
//比较优先级
int getPriority(char op)
{
	if(op == '+' || op == '-')
	{
		return 0;
	}
	else
	{
		return 1;
	}

}

//中缀转后缀
void InfixToPostfix(char exp[],char conexp[], int &j)
{
	char stack[maxsize];//定义运算符栈
	int top = -1;

	int i = 0;

	while(exp[i] != '\0')
	{
		if(exp[i] >= '0' && exp[i] <= '9')
		{
			conexp[j++] = exp[i++];
		}
		else if(exp[i] == '(')
		{
			stack[++top] = '(';
			++i;
		}
		else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if(getPriority(exp[i]) > getPriority(stack[top]) || top == -1 || stack[top] == '(')
			{
				stack[++top] = exp[i];
				++i;
			}
			else //if(getPriority(exp[i]) <= getPriority(stack[top]))
			{
				conexp[j++] = stack[top--];
			}
		}
		else if(exp[i] == ')')
		{
			while(stack[top] != '(')
			{
				conexp[j++] = stack[top--];
			}
			--top;
			++i;
		}
	}
	while(top != -1)
	{
		conexp[j++] = stack[top--];
	}
}

//中缀转前缀
void InfixToPrefix(char exp[], int len, char conexp[], int &j)
{
	char stack[maxsize];
	int top = -1;

	int i = len-1;

	while(i >= 0)
	{
		if(exp[i] >= '0' && exp[i] <= '9')
		{
			conexp[j++] = exp[i--];
		}
		else if(exp[i] == ')')
		{
			stack[++top] = ')';
			--i;
		}
		else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if(getPriority(exp[i]) >= getPriority(stack[top]) || top == -1 || stack[top] == ')')
			{
				stack[++top] = exp[i];
				--i;
			}
			else //if(getPriority(exp[i]) <= getPriority(stack[top]))
			{
				conexp[j++] = stack[top--];
			}
		}
		else if(exp[i] == '(')
		{
			while(stack[top] != ')')
			{
				conexp[j++] = stack[top--];
			}
			--top;
			--i;
		}
	}
	while(top != -1)
	{
		conexp[j++] = stack[top--];
	}
}

int main()
{
	char exp[maxsize];
	int length;
	char conexp[maxsize];
	int j = 0;
	
	printf("请输入需要转换的表达式：");
	scanf("%s",exp);
	printf("您输入的表达式为：%s\n",&exp[0]);
	length = strlen(exp);

	//InfixToPostfix(exp,conexp,j);
	InfixToPrefix(exp, length, conexp, j);

	//printf("转换后的表达式为：%s\n",&conexp[0]);
	printf("转换后的表达式为：");
	while(j != -1)
	{
		printf("%c",conexp[j--]);
	}
	printf("\n");

	return 0;
}

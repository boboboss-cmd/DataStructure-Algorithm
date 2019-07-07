#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define maxsize 100
#define min 0.00001
/*
顺序栈的应用
1.表达式求值
2.表达式转换
3.括号匹配
4.分段函数计算
*/

/*1.表达式求值*/
//判断优先级函数
int getPriority(char op)
{
	if(op == '+' || op == '-')
		return 0;
	else
		return 1;
}
//计算
int calculate(float opand1,float opand2,char op,float &result)
{
	if(op == '+') result=opand1+opand2;
	if(op == '-') result=opand1-opand2; 
	if(op == '*') result=opand1*opand2;
	if(op == '/')
	{
		if(fabs(opand2) < min)
		{
			printf("除数为0");
			return 0;
		}
		result = opand1/opand2;
	}
	return 1;
}
//取出两个数和一个运算符进行计算
/*int calexp(float stack1[],char stack2[],int top1,int top2)
{
	float opand1,opand2;
	char op;
	int flag;
	float result;

	opand2 = stack1[top1--];
	opand1 = stack1[top1--];
	op = stack2[top2--];
	flag = calculate(opand1,opand2,op,result);
	if(flag == 0)
	{
		printf("ERROR");
		return 0;
	}
	stack1[++top1] = result;

}*/


//用栈求中缀表达式的值
float calInfix(char exp[])
{
	float stack1[maxsize];//定义数据栈
	int top1 = -1;
	char stack2[maxsize];//定义操作符栈
	int top2 = -1;

	//int flag;

	int i=0;

	while(exp[i] != '\0')
	{
		if(exp[i]>='0' && exp[i]<='9')
		{
			stack1[++top1] = exp[i]-'0';
			++i;
		}
		else if(exp[i] == '(')
		{
			stack2[++top2] = '(';
			++i;
		}
		else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
		{
			if(top2 == -1 || stack2[top2] == '(' || getPriority(exp[i]) > getPriority(stack2[top2]))
			{
				stack2[++top2] = exp[i];
				++i;
			}
			else
			{
				// flag = calexp(stack1,stack2,top1,top2);
				// if(flag == 0) return 0;
				float opand1,opand2;
				char op;
				int flag;
				float result;

				opand2 = stack1[top1--];
				opand1 = stack1[top1--];
				op = stack2[top2--];
				flag = calculate(opand1,opand2,op,result);
				if(flag == 0)
				{
					printf("ERROR");
					return 0;
				}
				stack1[++top1] = result;
			}	
		}
		else if(exp[i] == ')')
		{
			while(stack2[top2] != '(')
			{
				// flag = calexp(stack1,stack2,top1,top2);
				// if(flag == 0) return 0;
				float opand1,opand2;
				char op;
				int flag;
				float result;

				opand2 = stack1[top1--];
				opand1 = stack1[top1--];
				op = stack2[top2--];
				flag = calculate(opand1,opand2,op,result);
				if(flag == 0)
				{
					printf("ERROR");
					return 0;
				}
				stack1[++top1] = result;
			}
			--top2;
			++i;
		}
	}
	while(top2 != -1)
	{
		// flag = calexp(stack1,stack2,top1,top2);
		// if(flag == 0) return 0;
		float opand1,opand2;
		char op;
		int flag;
		float result;

		opand2 = stack1[top1--];
		opand1 = stack1[top1--];
		op = stack2[top2--];
		flag = calculate(opand1,opand2,op,result);
		if(flag == 0)
		{
			printf("ERROR");
			return 0;
		}
		stack1[++top1] = result;
	}
	return stack1[top1];
}

//求后缀表达式的值
float calPostfix(char exp[])
{
	float stack[maxsize];
	int top = -1;
	int i = 0;
	for(i=0;exp[i] != '\0';++i)
	{
		if('0'<= exp[i] && exp[i] <= '9')
		{
			stack[++top] = exp[i]-'0';
		}
		else
		{
			float opand1,opand2;
			char op;
			int flag;
			float result;

			opand2 = stack[top--];
			opand1 = stack[top--];
			op = exp[i];
			flag = calculate(opand1,opand2,op,result);
			if(flag == 0)
			{
				printf("ERROR");
				break;
			}
			stack[++top] = result;
		}
	}
	return stack[top];
}

//求前缀表达式的值
float calPrefix(char exp[],int len)
{
	float stack[maxsize];//定义操作数栈
	int top = -1;

	for(int i=len-1;i >= 0;--i)
	{
		if(exp[i] >= '0' && exp[i] <= '9')
		{
			stack[++top]=exp[i]-'0';
		}
		else
		{
			float opand1,opand2,result;
			char op;
			int flag;

			opand1 = stack[top--];
			opand2 = stack[top--];
			op = exp[i];

			flag = calculate(opand1,opand2,op,result);
			if(flag == 0)
			{
				puts("ERROR");
				break;
			}
			stack[++top] = result;
		}

	}

	return stack[top];
}

int main()
{
	char exp[maxsize];
	int length;
	float result;
	printf("请输入需要计算的表达式：");
	scanf("%s",exp);
	length = strlen(exp);
	printf("您输入的表达式是：");
	printf("%s\n",&exp[0]);

	result = calPrefix(exp,length);
	//result = calInfix(exp);
	//result = calPostfix(exp);
	printf("表达式计算结果为：%.2f\n",result);

	return 0;
}
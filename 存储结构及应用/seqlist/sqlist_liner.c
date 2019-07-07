#include<stdio.h>

# define maxsize 100

// 定义ADT
typedef struct
{
	int data[maxsize];
	int length;
}sqlist;

// 顺序表初始化
sqlist Sqlistinit()
{
	sqlist L; //定义顺序表为L
	L.length = 0; //表长为0
	return L;//返回一个空顺序表
}

// 查找
// 按值查找
int sqlist_search(sqlist L, int x)
{
	int i = 0;
	while(i <= L.length-1 && L.data[i] != x)
	{
		i++;
	}
	if(i <= L.length)
		return i; //查找成功，返回位置
	else 
		return 0;//查找失败
}

// 线性表判空
int isEmpty(sqlist L)
{
	return(L.length==0 ?1:0);

}

//插入运算
// 按位置插入
sqlist elem_install(sqlist L, int q, int e)
{
	if(q < 0 || q > L.length || L.length == maxsize)
	{	
		printf("错误");
	}

	for(int i = L.length-1 ; i >= q ; --i )
	{
		L.data[i+1] = L.data[i];
	}
	L.data[q] = e;
	L.length++;
	return L;

}

// 删除元素运算
// 按值删除
sqlist delete_elem(sqlist L,int e)
{	
	int i = 0;
	while(i <= L.length-1 && L.data[i] != e)
	{
		i++;
	}
	
	if(i <= L.length-1)
	{	while(i <= L.length-1)
		{
			L.data[i] = L.data[i+1];
			++i;
		}
		return L;
	}
}

// 合并非递减有序表
sqlist sqlist_merge(sqlist a,sqlist b)
{
	sqlist c;
	c.length = 0;
	int i=0,j=0,k=0;
	while(i<a.length && j<b.length)
	{
		if(a.data[i] < b.data[j])
		{	c.data[k] = a.data[i];
			++k;++i;
		}
		else if(a.data[i] > b.data[j])
		{
			c.data[k] = b.data[j];
			++k;++j;
		}
	}
	while(i<a.length)
	{	c.data[k] = a.data[i];
		++k;++i;
	}
	while(j<b.length)
	{
		c.data[k] = b.data[j];
		++k;++j;
	}
	c.length = k+1;
	return c;
}

// 显示表的内容
void ShowData(sqlist L)
{
	for(int i=0;i<L.length; ++i)
	{
		printf("%d ",L.data[i]);
	}
	printf("\n");
}

int main()
{

	//sqlist l = Sqlistinit();
	
	//for(int i=0; i < 10; ++i)
		//l = elem_install(l,i,i+1);
	sqlist a = Sqlistinit();

	sqlist b = Sqlistinit();

	sqlist c = Sqlistinit();

	for(int i = 1; i<=5; ++i)
		a = elem_install(a,i,i+2);
	
	for(int i = 0; i<=4; ++i)
		b = elem_install(b,i,i+2);

	c = sqlist_merge(a,b);

	ShowData(a);
	ShowData(b);
	ShowData(c);

	return 0;

	//l = elem_install(l,2,11);

	//ShowData(l);

	//l = delete_elem(l,5);
	//s = sqlist_search(l,6);

	//ShowData(l);
}



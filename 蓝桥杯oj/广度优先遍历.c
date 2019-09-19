//广度优先遍历
#include<stdio.h>

typedef struct node{
	int d;//记录s到该节点的距离 
	int u;//记录该节点的父节点 
	int color;//记录该节点是否被访问过 
	struct node* p;//直线下一个节点 
} node;


int main() 
{
	//根据输入的数据，构造邻接链表
	int n=0;//n表示节点的个数；
	scanf("%d",&n);
	node H[n+1];
	return 0;
}

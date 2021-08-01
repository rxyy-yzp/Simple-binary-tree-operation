#include"stdio.h"
#include"stdlib.h"
#include"string.h"

#define   TRUE	         1
#define   FALSE           0
#define   OK	             1
#define   ERROR		     0
#define   INFEASIBLE      -1

typedef int Status;
typedef char TElemType;

//二叉链表存储结构 
typedef struct BiTNode
{
	TElemType data;    //数据域
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//函数声明
Status CreateBiTree(BiTree& T);
BiTree SearchBiTree(BiTree T, TElemType x);
int LeafCount(BiTree T);
Status CountLeaf(BiTree T, TElemType x, int& count);
void DispBiTree(BiTree T, int level);

//先序遍历建立二叉树的二叉链表 
Status CreateBiTree(BiTree& T)
{
	char ch;
	scanf("%c", &ch);
	if (ch == '#')
		T = NULL;
	else
	{
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

//查找值为x的结点
BiTree SearchBiTree(BiTree T, TElemType x)
{
	BiTree bt = NULL;
	if (T)
	{
		if (T->data == x)
		{
			return T;
		}
		bt = SearchBiTree(T->lchild, x);
		if (bt == NULL) //若左子树为空 
			bt = SearchBiTree(T->rchild, x);
		return bt;
	}
	return NULL;
}

//统计二叉树中叶子结点个数
int LeafCount(BiTree T)
{
	if (!T)
		return 0;	//空树叶子结点个数为0
	if ((!T->lchild) && (!T->rchild))
		return 1;   //若根节点没有左右孩子叶子结点个数为1
	return LeafCount(T->lchild) + LeafCount(T->rchild);	//否则为左右叶子结点个数之和
}

//统计以值为x的结点为根的子树中叶子结点的数目
Status CountLeaf(BiTree T, TElemType x, int& count)
{
	BiTree bt;
	bt = SearchBiTree(T, x);
	if (bt != NULL)
	{
		count = LeafCount(bt);
		printf("以值为x的结点为根的子树中叶子结点的数目为%d\n", count);
	}
	else
	{
		printf("查找错误!\n");
	}
	return ERROR;
}

//按照右中左的顺序打印二叉树
void DispBiTree(BiTree T, int level)
{
	int i;
	if (T)
	{
		DispBiTree(T->rchild, level + 1);
		for (i = 0;i < level;i++)
		{
			printf("#");
		}
		printf("%c\n", T->data);
		DispBiTree(T->lchild, level + 1);
	}
}

int main()
{
	BiTree T;
	int count = 0;
	TElemType x;
	printf("请输入要先序遍历序列字符串(以'#'代表空结点):\n");
	CreateBiTree(T);
	getchar();
	printf("\n");
	printf("请输入要查找结点的x的值:");
	scanf("%c", &x);
	CountLeaf(T, x, count);
	printf("\n");
	printf("按右中左的顺序打印的二叉树如下:\n");
	DispBiTree(T, 0);
	return 0;
}

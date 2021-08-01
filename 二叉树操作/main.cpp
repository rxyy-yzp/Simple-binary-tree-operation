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

//��������洢�ṹ 
typedef struct BiTNode
{
	TElemType data;    //������
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//��������
Status CreateBiTree(BiTree& T);
BiTree SearchBiTree(BiTree T, TElemType x);
int LeafCount(BiTree T);
Status CountLeaf(BiTree T, TElemType x, int& count);
void DispBiTree(BiTree T, int level);

//������������������Ķ������� 
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

//����ֵΪx�Ľ��
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
		if (bt == NULL) //��������Ϊ�� 
			bt = SearchBiTree(T->rchild, x);
		return bt;
	}
	return NULL;
}

//ͳ�ƶ�������Ҷ�ӽ�����
int LeafCount(BiTree T)
{
	if (!T)
		return 0;	//����Ҷ�ӽ�����Ϊ0
	if ((!T->lchild) && (!T->rchild))
		return 1;   //�����ڵ�û�����Һ���Ҷ�ӽ�����Ϊ1
	return LeafCount(T->lchild) + LeafCount(T->rchild);	//����Ϊ����Ҷ�ӽ�����֮��
}

//ͳ����ֵΪx�Ľ��Ϊ����������Ҷ�ӽ�����Ŀ
Status CountLeaf(BiTree T, TElemType x, int& count)
{
	BiTree bt;
	bt = SearchBiTree(T, x);
	if (bt != NULL)
	{
		count = LeafCount(bt);
		printf("��ֵΪx�Ľ��Ϊ����������Ҷ�ӽ�����ĿΪ%d\n", count);
	}
	else
	{
		printf("���Ҵ���!\n");
	}
	return ERROR;
}

//�����������˳���ӡ������
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
	printf("������Ҫ������������ַ���(��'#'����ս��):\n");
	CreateBiTree(T);
	getchar();
	printf("\n");
	printf("������Ҫ���ҽ���x��ֵ:");
	scanf("%c", &x);
	CountLeaf(T, x, count);
	printf("\n");
	printf("���������˳���ӡ�Ķ���������:\n");
	DispBiTree(T, 0);
	return 0;
}

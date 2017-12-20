#include<iostream>
#include<queue>
#include<string>
using namespace std;

/*
�ж���ȫ��������
��ȫ�������������һ���⣬ÿһ���ϵĽڵ������ﵽ�����ֵ�������һ����ֻȱ���ұߵ����ɽڵ㣡
�㷨˼·��
����Σ����ϵ��£������ң�������������������һ���ڵ��������Ϊ��ʱ����ýڵ�����������Ϊ�գ��Һ�������Ľڵ���
������������Ϊ�գ���������ȫ��������
*/

typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void InitBiTree(BiTree &T)
{
	T = NULL;
}

void DestroyBiTree(BiTree &T)
{
	if (T != NULL)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
	}
}

void CreateBiTree(BiTree &T)
{
	int t;
	cin >> t;
	if (t == -1)
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = t;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

bool IsCompleteBiTree(BiTree T)
{
	if (T == NULL)
		return false;

	queue<BiTree> q;
	q.push(T);
	bool mustHaveNoChild = false;
	bool result = true;
	while (!q.empty())
	{
		BiTree p = q.front();
		q.pop();
		if (mustHaveNoChild)
		{
			if (p->lchild != NULL || p->rchild != NULL)
			{
				result = false;
				break;
			}
		}
		else
		{
			if (p->lchild != NULL && p->rchild != NULL)
			{
				q.push(p->lchild);
				q.push(p->rchild);
			}
			else if (p->lchild == NULL && p->rchild == NULL)
			{
				mustHaveNoChild = true;
			}
			else if (p->lchild != NULL && p->rchild == NULL)
			{
				mustHaveNoChild = true;
				q.push(p->lchild);
			}
			else
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

int main()
{
	BiTree T;
	InitBiTree(T);
	cout << "Please input T (example:1 2 3 -1 -1 4 -1 -1 5 -1 -1):";
	CreateBiTree(T);
	string s = IsCompleteBiTree(T) ? "yes." : "no.";
	cout << "Is Complete BiTree ? " << endl << s << endl;

	DestroyBiTree(T);

	system("pause");
	return 0;
}
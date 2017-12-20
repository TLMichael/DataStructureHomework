#include <iostream>
using namespace std;

typedef struct BSTNode
{
	int data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode, *BSTree;

typedef struct 
{
	int *elem;
	int length;
}Table;

bool CreateTable(Table &T, int n)
{
	T.elem = (int *)malloc((n + 1) * sizeof(int));
	if (!T.elem)
		return false;
	for (int i = 1; i <= n; i++)
	{
		T.elem[i] = rand() % 100;
	}
	T.length = n;
	return true;
}

void TraverseTable(Table T)
{
	cout << "【Table】";
	for (int i = 1; i <= T.length; i++)
	{
		cout << " " << T.elem[i];
	}
	cout << endl;
}
void DestoryTable(Table &T)
{
	if (T.elem)
		free(T.elem);
	T.elem = NULL;
	T.length = 0;
}

bool SearchBST(BSTree BST, int key, BSTree f, BSTree &p)
{
	if (!BST)
	{
		p = f;
		return false;
	}
	else if (key == BST->data)
	{
		p = BST;
		return true;
	}
	else if (key < BST->data)
		return SearchBST(BST->lchild, key, BST, p);
	else
		return SearchBST(BST->rchild, key, BST, p);
}

bool InsertBST(BSTree &BST, int e)
{
	BSTree p, s;
	if (SearchBST(BST, e, NULL, p))
		return false;
	else
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->data = e;
		s->lchild = s->rchild = NULL;

		if (!p)
			BST = s;
		else if (e < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return true;
	}
}

bool CreateBSTree(BSTree &BST, Table T) 
{
	int i;
	BST = NULL;
	if (T.length)
	{
		for (i = 1; i <= T.length; i++)
			InsertBST(BST, T.elem[i]);
	}
	return true;
}

void InOrderTraverse_BST(BSTree BST)
{
	if (BST)
	{
		InOrderTraverse_BST(BST->lchild);
		cout << " " <<  BST->data;
		InOrderTraverse_BST(BST->rchild);
	}
}

bool Delete(BSTree &p)
{
	BSTree q, s;
	if (!p->rchild)
	{
		q = p;
		p = p->lchild;
		free(q);
	}
	else if (!p->lchild)
	{
		q = p;
		p = p->rchild;
		free(q);
	}
	else
	{
		q = p;
		s = p->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return true;
}

bool DeleteBST(BSTree &BST, int key)
{
	if (!BST)
		return false;
	else
	{
		if (key == BST->data)
			return Delete(BST);
		else if (key < BST->data)
			return DeleteBST(BST->lchild, key);
		else
			return DeleteBST(BST->rchild, key);
	}
}

int main()
{
	Table T;
	BSTree BST, p;

	cout << "创建并输出一个查找表...\n";
	CreateTable(T, 20);
	TraverseTable(T);
	cout << endl;

	cout << "构造二叉排序树：";
	CreateBSTree(BST, T);
	InOrderTraverse_BST(BST);
	cout << endl;

	cout << "查找关键字 8 :";
	if(SearchBST(BST, 8, NULL, p))
	{
		cout << "存在！" << endl;
	}
	else
	{
		cout << "不存在！" << endl;
		cout << "查找路径上最后一个结点：" << p->data << endl;
	}

	cout << "删除关键字 " << BST->data << ":";
	DeleteBST(BST, BST->data);
	InOrderTraverse_BST(BST);
	cout << endl;

	system("pause");
	return 0;
}

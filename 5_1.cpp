#include<iostream>
#include<queue>
using namespace std;

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

void ClearBiTree(BiTree &T)
{
	if(T!=NULL)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
	}
}

bool BiTreeEmpty(BiTree T)
{
	if (T == NULL)
		return true;
	else
		return false;
}

int BiTreeDepth(BiTree T)
{
	if (T == NULL)
		return 0;
	int ld = BiTreeDepth(T->lchild) + 1;
	int rd = BiTreeDepth(T->rchild) + 1;
	return ld > rd ? ld : rd;
}

BiTree Root(BiTree T)
{
	return T;
}

int Value(BiTree T, BiTNode e)
{
	return e.data;
}

void Assign(BiTree T, BiTNode &e, int value)
{
	e.data = value;
}

BiTree Parent(BiTree T, BiTNode e)
{
	BiTree p;
	if (T == NULL || e.data == T->data)
		return NULL;
	if (T->lchild->data == e.data || T->rchild->data == e.data)
		return T;
	p = Parent(T->lchild, e);
	if (p != NULL)
		return p;
	p = Parent(T->rchild, e);
	if (p != NULL)
		return p;
	return NULL;
}

BiTree LeftChild(BiTree T, BiTNode e)
{
	if (e.lchild != NULL)
		return e.lchild;
	else
		return NULL;
}

BiTree RightChild(BiTree T, BiTNode e)
{
	if (e.rchild != NULL)
		return e.rchild;
	else
		return NULL;
}

BiTree LeftSibling(BiTree T, BiTNode e)
{
	BiTree parent = Parent(T, e);
	if (parent->lchild != NULL && parent->rchild->data == e.data)
		return parent->lchild;
	else
		return NULL;
}

BiTree RightSibling(BiTree T, BiTNode e)
{
	BiTree parent = Parent(T, e);
	if (parent == NULL)
		return NULL;
	if (parent->rchild != NULL && parent->lchild->data == e.data)
		return parent->rchild;
	else
		return NULL;
}

void InsertChild(BiTree &T, BiTree &p, int LR, BiTree c)
{
	BiTree t = c;
	while (t->rchild != NULL)
		t = t->rchild;
	if (LR == 0)
	{
		t->rchild = p->lchild;
		p->lchild = c;
	}
	else
	{
		t->rchild = p->rchild;
		p->rchild = c;
	}
}

void DeleteChild(BiTree &T, BiTree &p, int LR)
{
	if (LR == 0)
	{
		DestroyBiTree(p->lchild);
		p->lchild = NULL;
	}
	else
	{
		DestroyBiTree(p->rchild);
		p->rchild = NULL;
	}
}

void PreOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
		cout << T->data << " ";
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

void InOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
		InOrderTraverse(T->lchild);
		cout << T->data << " ";
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T)
{
	if (T != NULL)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout << T->data << " ";
	}
}

void LevelOrderTraverse(BiTree T)
{
	queue<BiTree> q;
	q.push(T);
	while (!q.empty())
	{
		BiTree t = q.front();
		q.pop();
		if (t != NULL)
		{
			cout << t->data << " ";
			q.push(t->lchild);
			q.push(t->rchild);
		}
	}
}

int main()
{
	BiTree T;
	InitBiTree(T);
	cout << "Please input T (example:1 2 3 -1 -1 4 -1 -1 5 -1 -1):";
	CreateBiTree(T);
	cout << "PreOrderTraverse:";
	PreOrderTraverse(T);	cout << endl;
	cout << "InOrderTraverse:";
	InOrderTraverse(T);		cout << endl;
	cout << "PostOrderTraverse:";
	PostOrderTraverse(T);	cout << endl;
	cout << "LevelOrderTraverse:";
	LevelOrderTraverse(T);	cout << endl;
	cout << "Depth: " << BiTreeDepth(T) << endl;

	BiTree c;
	InitBiTree(c);
	cout << "Please input c (example:6 7 -1 -1 8 -1 -1):";
	CreateBiTree(c);
	InsertChild(T, T, 0, c);
	cout << "After inserted, LevelOrderTraverse:";
	LevelOrderTraverse(T);	cout << endl;

	BiTree tmp;
	tmp = LeftChild(T, *(T->lchild));
	if (tmp != NULL)
		cout << "LeftChild is " << tmp->data << endl;
	else
		cout << "Nothingness!" << endl;

	tmp = RightSibling(T, *(T->lchild));
	if (tmp != NULL)
		cout << "RightSibling is " << tmp->data << endl;
	else
		cout << "Nothingness!" << endl;

	DeleteChild(T, T->lchild, 0);
	cout << "After delete, LevelOrderTraverse:";
	LevelOrderTraverse(T); cout << endl;

	DestroyBiTree(T);

	system("pause");
	return 0;
}
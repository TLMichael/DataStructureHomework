#include <iostream>
#include <queue>
using namespace std;

typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void InitBiTree(BiTree &T)
{
	T = NULL;
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

void DestroyBiTree(BiTree &T)
{
	if (T != NULL)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
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

void LevelOrderDelete(BiTree &T, int x)
{
	if (T->data == x)
	{
		DestroyBiTree(T);
		return;
	}

	BiTree cur = T;
	queue<BiTree> q;
	q.push(cur);
	while (!q.empty())
	{
		BiTree cur = q.front();
		q.pop();
		if (cur->lchild != NULL && cur->rchild != NULL)
		{
			if (cur->lchild->data != x && cur->rchild->data != x)
			{
				q.push(cur->lchild);
				q.push(cur->rchild);
			}
			else if (cur->lchild->data == x && cur->rchild->data == x)
			{
				DestroyBiTree(cur->lchild);
				DestroyBiTree(cur->rchild);
				cur->lchild = NULL;
				cur->rchild = NULL;
			}
			else if (cur->lchild->data == x && cur->rchild->data != x)
			{
				DestroyBiTree(cur->lchild);
				cur->lchild = NULL;
				q.push(cur->rchild);
			}
			else if (cur->lchild->data != x && cur->rchild->data == x)
			{
				DestroyBiTree(cur->rchild);
				cur->rchild = NULL;
				q.push(cur->lchild);
			}
		}
		else if (cur->lchild == NULL && cur->rchild == NULL)
		{
			continue;
		}
		else if (cur->lchild != NULL && cur->rchild == NULL)
		{
			if (cur->lchild->data != x)
				q.push(cur->lchild);
			else
			{
				DestroyBiTree(cur->lchild);
				cur->lchild = NULL;
			}
		}
		else if (cur->lchild == NULL && cur->rchild != NULL)
		{
			if (cur->rchild->data != x)
				q.push(cur->rchild);
			else
			{
				DestroyBiTree(cur->rchild);
				cur->rchild = NULL;
			}
		}

	}
}

int main()
{
	BiTree T;
	InitBiTree(T);
	cout << "Please input T (example:1 2 8 -1 -1 4 -1 -1 8 -1 -1):";
	CreateBiTree(T);

	cout << "LevelOrderTraverse:";
	LevelOrderTraverse(T);	cout << endl;


	LevelOrderDelete(T, 8);
	cout << "After Delete..." << endl;
	cout << "LevelOrderTraverse:";
	LevelOrderTraverse(T);	cout << endl;

	DestroyBiTree(T);

	system("pause");
	return 0;
}
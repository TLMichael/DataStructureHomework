#include <iostream>
#include <stack>
#include <queue>
using namespace std;
const int INIT_STACK_SIZE = 1000;
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

void PreOrderTraverse(BiTree T)
{
	stack<BiTree> s;
	BiTree p = T;
	while (p != NULL || !s.empty())
	{
		if (p != NULL)
		{
			cout << p->data << " ";
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}

void InOrderTraverse(BiTree T)
{
	stack<BiTree> s;
	BiTree p = T;
	while (p != NULL || !s.empty())
	{
		if (p != NULL)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->data << " ";
			p = p->rchild;
		}
	}
}

void PostOrderTraverse(BiTree T)
{
	stack<BiTree> s;
	BiTree cur, pre;
	InitBiTree(cur);
	InitBiTree(pre);
	s.push(T);
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->lchild == NULL && cur->rchild == NULL) || (pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
		{
			cout << cur->data << " ";
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->rchild != NULL)
				s.push(cur->rchild);
			if (cur->lchild != NULL)
				s.push(cur->lchild);
		}
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

	DestroyBiTree(T);

	system("pause");
	return 0;
}
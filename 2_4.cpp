#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
}LNode, *LinkList;

void InitList_L(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
}

void CreateList_L(LinkList &L, int n)
{
	LinkList p;
	for (int i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = rand() % 100;
		p->next = L->next;
		L->next = p;
	}
}

void DestroyList_L(LinkList &L)
{
	LNode *p;
	while (L != NULL)
	{
		p = L->next;
		free(L);
		L = p;
	}
}

void ListTraverse_L(LinkList L)
{
	LinkList p = L->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void InsertSort_L(LinkList &L)
{
	LinkList p, q, s, t;
	s = L->next;
	L->next = NULL;
	while (s != NULL)
	{
		t = s->next;
		p = L;
		q = p->next;
		while (q != NULL && s->data > q->data)
		{
			p = q;
			q = q->next;
		}
		p->next = s;
		s->next = q;
		s = t;
	}
}

void MergeList_L(LinkList &L1, LinkList &L2)
{
	LinkList p, q, s, t;
	s = L2->next;
	L2->next = NULL;
	while (s != NULL)
	{
		t = s->next;
		q = L1;
		p = q->next;
		while (p != NULL && p->data < s->data)
		{
			q = p;
			p = p->next;
		}
		q->next = s;
		s->next = p;
		s = t;
	}
}

int main()
{
	LinkList L1, L2;
	InitList_L(L1);
	InitList_L(L2);
	cout << "正在初始化L1（长度为5）..." << endl;
	CreateList_L(L1, 5);
	InsertSort_L(L1);
	cout << "正在初始化L2（长度为8）..." << endl;
	CreateList_L(L2, 8);
	InsertSort_L(L2);

	cout << "L1:";
	ListTraverse_L(L1);
	cout << "L2:";
	ListTraverse_L(L2);

	cout << "正在合并..." << endl;
	MergeList_L(L1, L2);
	cout << "合并后\nL1：";
	ListTraverse_L(L1);

	DestroyList_L(L1);
	DestroyList_L(L2);
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
typedef struct LNode {
	int data;
	LNode *next;
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

int main()
{
	LinkList L;
	InitList_L(L);
	cout << "随机初始化一个长度为8的链表..." << endl;
	CreateList_L(L, 8);
	cout << "排序前：";
	ListTraverse_L(L);
	InsertSort_L(L);
	cout << "排序后：";
	ListTraverse_L(L);

	DestroyList_L(L);
	system("pause");
	return 0;
}
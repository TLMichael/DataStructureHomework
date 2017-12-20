#include <iostream>
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

void Inverse_L(LinkList &L)
{
	LinkList p, q;
	p = L->next;
	L->next = NULL;
	while (p != NULL)
	{
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}

int main() {
	LinkList L;
	InitList_L(L);
	cout << "�������ɹ���" << endl;
	cout << "���������ʼ��һ������Ϊ8������" << endl;
	CreateList_L(L, 8);
	cout << "�����ʱԪ�أ�";
	ListTraverse_L(L);

	Inverse_L(L); 
	cout << "ת�ú�:" << endl;
	ListTraverse_L(L);

	DestroyList_L(L);
	system("pause");
	return 0;
}
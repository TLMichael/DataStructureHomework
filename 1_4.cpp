#include <iostream>
using namespace std;

typedef struct LNode {
	int data;
	LNode *next;
}LNode, *LinkList;

void InitList_L(LinkList &L, int n) 
{
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	LNode *p, *t;
	t = L;
	t->data = 1;
	for (int i = 2; i <= n; i++) 
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = i;
		t->next = p;
		t = p;
	}
	t->next = L;
}

void Josephus(LinkList &L, int s, int m) 
{
	LNode *p = L, *q = p;
	while (p->data != s)
		p = p->next;
	while (q->next != p)
		q = q->next;
	cout << "out sequence:" << endl;
	while (p->next != p) 
	{
		for (int i = 1; i<m; i++) 
		{
			q = p;
			p = p->next;
		}
		cout << p->data << " ";
		q->next = p->next;
		free(p);
		p = q->next;
	}
	cout << endl << "the last:" << p->data << endl;
	free(p);
}
int main() 
{
	int n, s, m;
	LinkList L;
	cout << "输入人数n:";
	cin >> n;
	InitList_L(L, n);
	cout << "输入s(不大于n)和m:";
	cin >> s >> m;
	if (s > n)
	{
		cout << "s大于n，出错" << endl;
		return 0;
	}
	Josephus(L, s, m);

	system("pause");
	return 0;
}

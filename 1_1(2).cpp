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

void ClearList_L(LinkList &L)
{
	LNode *q;
	while (L->next != NULL)
	{
		q = L->next;
		L->next = q->next;
		free(q);
	}
}

bool ListEmpty_L(LinkList L)
{
	if (L->next == NULL)
		return true;
	else
		return false;
}

int ListLength_L(LinkList L)
{
	int len = 0;
	LNode *p = L->next;
	while(p != NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

bool GetElem_L(LinkList L, int i, int &e)
{
	LinkList p = L->next;
	int j = 1;
	while (p != NULL && j < i)
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i)
		return false;
	e = p->data;
	return true;
}

int LocateElem_L(LinkList L, int e)
{
	int loc = 1;
	LinkList p = L->next;
	while (p != NULL)
	{
		if (p->data == e)
			return loc;
		p = p->next;
		loc++;
	}
	return 0;
}

bool PriorElem_L(LinkList L, int cur_e, int &pre_e)
{
	LinkList p, q;
	while (L->next == NULL || L->next->next == NULL)
		return false;
	q = L->next;
	p = q->next;
	while (p != NULL)
	{
		if (p->data == cur_e)
		{
			pre_e = q->data;
			return true;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	return false;
}

bool NextElem_L(LinkList L, int cur_e, int &next_e)
{
	LinkList p, q;
	while (L->next == NULL || L->next->next == NULL)
		return false;
	q = L->next;
	p = q->next;
	while (p != NULL)
	{
		if (q->data == cur_e)
		{
			next_e = p->data;
			return true;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	return false;
}

bool ListInsert_L(LinkList &L, int i, int e)
{
	//�ڴ�ͷ�ڵ�ĵ�����L�ĵ�i��Ԫ��֮ǰ����Ԫ��
	LinkList p, s;
	p = L;
	int j = 0;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (p == NULL || j > i - 1)
		return false;
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

bool ListDelete_L(LinkList &L, int i, int &e)
{
	//�ڴ�ͷ�ڵ�ĵ�����L�У�ɾ����i��Ԫ�أ�����e������ֵ
	LinkList p, q;
	p = L;
	int j = 0;
	while (p->next != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if ((p->next) == NULL || j > i - 1)
		return false;
	q = p->next;
	p->next = q->next;
	free(q);
	return true;
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

int main()
{
	LinkList L;
	int e, pre_e, next_e;
	bool flag;
	InitList_L(L);
	cout << "�������ɹ���" << endl;
	if (ListEmpty_L(L))
		cout << "����Ϊ�ա�" << endl;
	cout << "�����������һ������Ϊ8������" << endl;
	CreateList_L(L,8);
	cout << "�����ʱԪ�أ�";
	ListTraverse_L(L);
	cout << "�����ʱ���ȣ�" << ListLength_L(L) << endl;

	GetElem_L(L, 2, e);
	cout << "����ĵڶ���Ԫ��Ϊ��" << e << endl << endl;
	cout << "����һ�����������LocateElem_L������";
	cin >> e;
	int loc = LocateElem_L(L, e);
	if (loc != 0)
		cout << e << "�������еĵ�" << loc << "��Ԫ�ء�" << endl;
	else
		cout << "�����в�����Ԫ��!" << e << endl;

	cout << "����һ�����������PriorElem_L������";
	cin >> e;
	flag =  PriorElem_L(L, e, pre_e);
	cout << "Ѱ��ǰ��Ԫ����"<< e <<"������" << endl;
	if (flag == true)
		cout << e << "��ǰһ��Ԫ���ǣ�" << pre_e << endl;
	else
		cout << "������" << e << "��ǰ��" << endl;

	cout << "����һ�����������NextElem_L������";
	cin >> e;
	flag = NextElem_L(L, e, next_e);
	cout << "Ѱ�Һ��Ԫ����" << e << "������" << endl;
	if (flag == true)
		cout << e << "�ĺ�һ��Ԫ���ǣ�" << next_e << endl << endl;
	else
		cout << "������" << e << "�ĺ��" << endl << endl;

	cout << "��ڶ���λ�ò���666..." << endl;
	if (ListInsert_L(L, 2, 666))
		cout << "�ɹ��ڵڶ���λ�ò���666��" << endl;
	else
		cout << "����ʧ�ܡ�" << endl;

	cout << "�����ʱ���£�" << endl;
	ListTraverse_L(L);
	cout << endl;

	cout << "ɾ������ĵ�һ��Ԫ��...";
	if (ListDelete_L(L, 1, e))
		cout << "�ɹ�ɾ����һ��λ���ϵ�Ԫ��" << e << endl;
	else
		cout << "ɾ��ʧ�ܡ�" << endl;

	cout << "�����ʱ���£�" << endl;
	ListTraverse_L(L);
	cout << endl;

	cout << "���Խ������ݻ�����\nлл�ۿ����ټ���" << endl<< endl;
	DestroyList_L(L);
	
	system("pause");
	return 0;
}
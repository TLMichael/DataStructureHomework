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
	//在带头节点的单链表L的第i个元素之前插入元素
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
	//在带头节点的单链表L中，删除第i个元素，并由e返回其值
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
	cout << "链表创建成功！" << endl;
	if (ListEmpty_L(L))
		cout << "链表为空。" << endl;
	cout << "现在随机创建一个长度为8的链表" << endl;
	CreateList_L(L,8);
	cout << "链表此时元素：";
	ListTraverse_L(L);
	cout << "链表此时长度：" << ListLength_L(L) << endl;

	GetElem_L(L, 2, e);
	cout << "链表的第二个元素为：" << e << endl << endl;
	cout << "输入一个数用来检查LocateElem_L函数：";
	cin >> e;
	int loc = LocateElem_L(L, e);
	if (loc != 0)
		cout << e << "是链表中的第" << loc << "个元素。" << endl;
	else
		cout << "链表中不存在元素!" << e << endl;

	cout << "输入一个数用来检查PriorElem_L函数：";
	cin >> e;
	flag =  PriorElem_L(L, e, pre_e);
	cout << "寻找前驱元素用"<< e <<"举例：" << endl;
	if (flag == true)
		cout << e << "的前一个元素是：" << pre_e << endl;
	else
		cout << "不存在" << e << "的前驱" << endl;

	cout << "输入一个数用来检查NextElem_L函数：";
	cin >> e;
	flag = NextElem_L(L, e, next_e);
	cout << "寻找后继元素用" << e << "举例：" << endl;
	if (flag == true)
		cout << e << "的后一个元素是：" << next_e << endl << endl;
	else
		cout << "不存在" << e << "的后继" << endl << endl;

	cout << "向第二个位置插入666..." << endl;
	if (ListInsert_L(L, 2, 666))
		cout << "成功在第二个位置插入666。" << endl;
	else
		cout << "插入失败。" << endl;

	cout << "链表此时如下：" << endl;
	ListTraverse_L(L);
	cout << endl;

	cout << "删除链表的第一个元素...";
	if (ListDelete_L(L, 1, e))
		cout << "成功删除第一个位置上的元素" << e << endl;
	else
		cout << "删除失败。" << endl;

	cout << "链表此时如下：" << endl;
	ListTraverse_L(L);
	cout << endl;

	cout << "测试结束，摧毁链表。\n谢谢观看，再见。" << endl<< endl;
	DestroyList_L(L);
	
	system("pause");
	return 0;
}
#include <iostream>
using namespace std;

typedef struct QNode {
	int data;
	struct QNode *next;
}QNode, *QueuePtr;
typedef struct {
	QueuePtr front;		//队头指针
	QueuePtr rear;		//队尾指针
}LinkQueue;

void InitQueue(LinkQueue &q)
{
	q.front = q.rear = (QueuePtr)malloc(sizeof(QNode));
	q.front->next = NULL;
}

void DestroyQueue(LinkQueue &q)
{
	while (q.front)
	{
		q.rear = q.front->next;
		free(q.front);
		q.front = q.rear;
	}
}

void ClearQueue(LinkQueue &q)
{
	QueuePtr p, s;
	p = q.front->next;
	while (p != NULL)
	{
		s = p->next;
		free(p);
		p = s;
	}
	q.front->next = NULL;
	q.rear = q.front;
}

bool QueueEmpty(LinkQueue q)
{
	if (q.front == q.rear)
		return true;
	else
		return false;
}

int QueueLength(LinkQueue q)
{
	int len = 0;
	QueuePtr p;
	p = q.front->next;
	while (p != NULL)
	{
		len++;
		p = p->next;
	}
	return len;
}

bool GetHead(LinkQueue q, int &e)
{
	if (QueueEmpty(q))
		return false;
	else
	{
		e = q.front->next->data;
		return true;
	}
}

bool EnQueue(LinkQueue &q, int e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)
		return false;
	p->data = e;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
	return true;
}

bool DeQueue(LinkQueue &q, int &e)
{
	if (QueueEmpty(q))
		return false;
	QueuePtr p = q.front->next;
	e = p->data;
	q.front->next = p->next;
	if (q.rear == p)
		q.rear = q.front;
	free(p);
	return true;
}

void QueueTraverse(LinkQueue q)
{
	QueuePtr p = q.front->next;
	while (p != NULL)
	{
		cout << " " << p->data;
		p = p->next;
	}
	cout << endl;
}

int main()
{
	LinkQueue q;
	int e;
	InitQueue(q);
	if (QueueEmpty(q))
		cout << "Queue is empty!" << endl;
	cout << "Dequeue five numbers randomly." << endl;
	for (int i = 0; i < 5; i++)
	{
		EnQueue(q, rand() % 100);
	}
	cout << "Queue: ";
	QueueTraverse(q);
	cout << "Length: " << QueueLength(q) << endl;
	cout << "Add 666 to tail...	" << endl;
	EnQueue(q, 666);
	cout << "Queue: ";
	QueueTraverse(q);
	GetHead(q, e);
	cout << "Head: " << e << endl;
	ClearQueue(q);
	cout << "ClearQueue, current length: " << QueueLength(q) << endl;

	DestroyQueue(q);
	system("pause");
	return 0;
}


#include <iostream>
using namespace std;
#define MAXQSIZE 10

typedef struct {
	int *base;
	int front;
	int rear;
}SqQueue;

bool InitQueue(SqQueue &Q)
{
	Q.base = (int *)malloc(MAXQSIZE * sizeof(int));
	if (!Q.base)
		exit(0);
	Q.front = Q.rear = 0;
	for (int i = 0; i < MAXQSIZE; i++)
	{
		Q.base[i] = 0;
	}
	return true;
}

int QueueLength(SqQueue Q)
{
	return(Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

void EnQueue(SqQueue &Q, int e)
{
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
}

bool DeQueue(SqQueue &Q, int &e)
{
	if (Q.front == Q.rear)
		return false;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;
}

int MaxQueue(SqQueue Q)
{
	int max = Q.base[0];
	for (int i = 1; i < MAXQSIZE; i++)
	{
		if (max < Q.base[i])
			max = Q.base[i];
	}
	return max;
}

void QueueTraverse(SqQueue Q)
{
	for(int i=0;i<MAXQSIZE;i++)
	{
		cout << "\t" << Q.base[i];
	}
}

void DestroyQueue(SqQueue &Q)
{
	free(Q.base);
}

int main()
{
	SqQueue Q;
	InitQueue(Q);
	cout << "Status : ";
	QueueTraverse(Q);
	cout << "\n\nStart simulation!" << endl;
	for (int i = 1; i <= 20; i++)
	{
		cout << "Time: " << i << "s\t";
		EnQueue(Q, rand() % 1000);
		cout << "Status:";
		QueueTraverse(Q);
		cout << "\tMax:" << MaxQueue(Q) << endl;
	}
	cout << "\nSimulation finished!" << endl;

	DestroyQueue(Q);
	system("pause");
	return 0;
}
#include<iostream>
using namespace std;
const int STACK_INIT_SIZE = 9;
const int N = 8;
const int inf = 0x3f3f3f3f;
typedef struct {
	int* base;
	int* top;
	int stacksize;
}SqStack;
int sum = 0;

void InitStack(SqStack &s)
{
	s.base = (int*)malloc(STACK_INIT_SIZE * sizeof(int));
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
}

int GetTop(SqStack s)
{
	return *(s.top - 1);
}

void Push(SqStack &s, int e)
{
	*s.top++ = e;
}

void Pop(SqStack &s, int &e)
{
	e = *(--s.top);
}

int StackLength(SqStack s)
{
	return s.top - s.base;
}

void Print(SqStack s)
{
	cout << "\n\nNo." << sum << endl << " ";
	for (int i = 0; i < N; i++)
		cout << " " << i + 1;
	for (int i = 0; i < N; i++)
	{
		cout << endl << i + 1 << " ";
		for (int j = 0; j < N; j++)
		{
			if (s.base[i + 1] == j + 1)
				cout << "Q ";
			else
				cout << "- ";
		}
	}
}

bool Judge(SqStack s, int k)
{
	if (k == 1)
		return true;
	int *q = s.base + k;
	for (int *p = s.base + 1; p < q; p++)
	{
		if (*p == *q || abs(p - q) == abs(*p - *q))
			return false;
	}
	return true;
}

void PutQueen(SqStack &s)
{
	int temp;
	Push(s, inf);
	Push(s, 0);
	while (StackLength(s) - 1 >= 1)
	{
		Pop(s, temp);
		Push(s, temp+1);
		while (GetTop(s) <= N && !Judge(s, StackLength(s) - 1))
		{
			Pop(s, temp);
			Push(s, temp + 1);
		}
		if (GetTop(s) <= N)
		{
			if (StackLength(s) - 1 == N)
			{
				sum++;
				Print(s);
			}
			else
			{
				Push(s, 0);
			}
		}
		else
		{
			Pop(s, temp);
		}
	}

}

int main()
{
	SqStack s;
	InitStack(s);
	PutQueen(s);

	system("pause");
	return 0;
}
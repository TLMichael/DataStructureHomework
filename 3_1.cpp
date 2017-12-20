#include <iostream>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT	10

typedef struct {
	int *base;
	int *top;
	int stacksize;
}SqStack;

void InitStack(SqStack &s)
{
	s.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	s.top = s.base;
	s.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &s)
{
	free(s.base);
}

void ClearStack(SqStack &s)
{
	s.top = s.base;
	s.stacksize = 0;
}

bool StackEmpty(SqStack s)
{
	if (s.top == s.base)
		return false;
	else
		return true;
}

int StackLength(SqStack s)
{
	return s.top - s.base;
}

bool GetTop(SqStack s, int &e)
{
	if (s.top == s.base)
		return false;
	e = *(s.top - 1);
	return true;
}

void Push(SqStack &s, int e)
{
	if (s.top - s.base == s.stacksize)
	{
		s.base = (int *)realloc(s.base, (s.stacksize + STACKINCREMENT) * sizeof(int));
		s.top = s.base + s.stacksize;
		s.stacksize += STACKINCREMENT;
	}
	*s.top++ = e;
}

bool Pop(SqStack &s, int &e)
{
	if (s.top == s.base)
		return false;
	e = *(--s.top);
	return true;
}

void StackTraverse(SqStack s)
{
	for (int *p = s.base; p != s.top; p++)
		cout << " " << *p;
	cout << endl;
}

int main()
{
	SqStack s;
	int e;
	InitStack(s);
	if (StackEmpty(s))
		cout << "Stack is empty!" << endl;

	cout << "Push five numbers randomly." << endl;
	for (int i = 0; i < 5; i++)
	{
		Push(s, rand() % 100);
	}
	cout << "Stack: ";
	StackTraverse(s);
	cout << "Length: " << StackLength(s) << endl;
	Pop(s, e);
	GetTop(s, e);
	cout << "Pop one, new top: " << e << endl;
	ClearStack(s);
	cout << "ClearStack, current length: " << StackLength(s) << endl;

	DestroyStack(s);
	system("pause");
	return 0;
}
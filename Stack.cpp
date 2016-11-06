#include "stdafx.h"
#include "Stack.h"
#define STACK_INIT_SIZE 2


template<typename Elemtype>
Stack<Elemtype>::Stack()
{
	Stack::base = new Elemtype[STACK_INIT_SIZE];
	Stack::top = Stack::base;
	Stack::stacksize = STACK_INIT_SIZE;
}

template<typename Elemtype>
Stack<Elemtype>::~Stack()
{
	delete[]Stack::base;
}

template<typename Elemtype>
void Stack<Elemtype>::DestroyStack()
{
	free(Stack::base);
	Stack::base = NULL;
	Stack::top = NULL;
	Stack::stacksize = 0;
}

template<typename Elemtype>
void Stack<Elemtype>::ClearStack()
{
	Stack::top = Stack::base;
}

template<typename Elemtype>
bool Stack<Elemtype>::StackEmpty()
{
	if (Stack::top == Stack::base)
		return true;
	else
		return false;
}

template<typename Elemtype>
int Stack<Elemtype>::StackLength()
{
	return Stack::top - Stack::base;
}

template<typename Elemtype>
void Stack<Elemtype>::GetTop(Elemtype & e)
{
	if (Stack::top>Stack::base)
	{
		e = *(Stack::top - 1);
	}
}

template<typename Elemtype>
void Stack<Elemtype>::Push(Elemtype e)
{
	if (Stack::top - Stack::base >= stacksize)
		return;
	*(Stack::top++) = e;
}

template<typename Elemtype>
void Stack<Elemtype>::Pop(Elemtype & e)
{
	if (top == base)
		return;
	e = *--top;
}


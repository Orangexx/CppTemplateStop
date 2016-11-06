#pragma once

template<typename Elemtype>
class Stack
{
public:
	Stack();
	~Stack();
	int stacksize;

	void DestroyStack();
	void ClearStack();
	bool StackEmpty();
	int StackLength();
	void GetTop(Elemtype &e);
	void Push(Elemtype e);
	void Pop(Elemtype &e);

private:
	Elemtype* base;
	Elemtype* top;
};

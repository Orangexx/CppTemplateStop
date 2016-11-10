#include "stdafx.h"
#include "Queue.h"
#define STACK_INIT_SIZE 2

template<class LNode,class ElemType>
Queue<LNode,ElemType>::Queue()
{
	Queue::front = Queue::rear = new LNode();
	Queue::front->next = NULL;
}

template<class LNode,class ElemType>
Queue<LNode,ElemType>::~Queue()
{
	while (Queue::front)
	{
		Queue::rear = Queue::front->next;
		delete(Queue::front);
		Queue::front = Queue::rear;
	}
}

template<class LNode, class ElemType>
void Queue<LNode, ElemType>::ClearQueue()
{
	LNode* p, q;
	Queue::rear = Queue::front;
	p = Queue::front->next;
	Queue::front->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
		delete(q);
	}
}

template<class LNode, class ElemType>
bool Queue<LNode, ElemType>::QueueEmpty()
{
	if (Queue::front == Queue::rear)
		return true;
	else
		return false;
}

template<class LNode, class ElemType>
int Queue<LNode, ElemType>::QueueLength()
{
	int i = 0;
	LNode* p;
	p = Queue::front;
	while (Queue::rear != p)
	{
		i++;
		p = p->next;
	}
	return i;
}

template<class LNode, class ElemType>
void Queue<LNode, ElemType>::GetHend(ElemType & e)
{
	LNode* p;
	if (Queue::front == Queue::rear)
		return;
	p = Queue::front->next;
	e = p->e;
}

template<class LNode, class ElemType>
void Queue<LNode, ElemType>::EnQueue( ElemType e)
{
	LNode* p;
	p = new LNode();
	p->e = e;
	p->next = NULL;
	Queue::rear->next = p;
	Queue::rear = p;
}

template<class LNode, class ElemType>
void Queue<LNode, ElemType>::DeQueue(ElemType & e)
{
	LNode* p;
	if (Queue::front == Queue::rear)
		return;
	p = Queue::front->next;
	e = p->e;
	Queue::front->next = p->next;
	if (Queue::rear == p)
		Queue::rear = Queue::front;
	delete(p);
}

template<class LNode, class ElemType>
void Queue<LNode, ElemType>::QueueTraverse(void(*vi)(LNode))
{
	LNode* p;
	p = Queue::front->next;
	while (p)
	{
		vi(p->T2);
		p = p->next;
	}
	printf("\n");
}

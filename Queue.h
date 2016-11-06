#pragma once


template<class LNode,class ElemType>
class Queue
{
public:
	Queue();
	~Queue();

	void ClearQueue();
	bool QueueEmpty();
	int QueueLength();
	void GetHend(ElemType &e);
	void EnQueue(ElemType e);
	void DeQueue(ElemType &e);
	void QueueTraverse(void(*vi)(LNode));

private:
	LNode* front;
	LNode* rear;
};



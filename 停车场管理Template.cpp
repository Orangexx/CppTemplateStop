// ͣ��������C++STL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include<iostream>
#include "Queue.h"
#include "Queue.cpp"
#include "Stack.h"
#include "Stack.cpp"

#define MAXSIZE 2

using namespace std;

typedef struct
{
	string status;
	int carnumber;
	int arrive;
	int left;
}car;

typedef struct QNode
{
	car e;
	struct QNode* next;
}QNode, *QueuePtr;

void handle(car &e, Stack<car> &Stop, Stack<car> &Temp,Queue<QNode,car> &Queue);

int main()
{
	Stack<car> Stop;
	Stack<car> Temp;

	Queue<QNode, car> Queue;


	while (true)
	{
		car e;
		cout << "�����복�ƺ���" << endl;
		cin >> e.carnumber;

		while (true)
		{
			cout << "�����복��Ҫִ�еĶ���:" << endl;
			cin >> e.status;

			if (e.status == "����")
			{
				cout << "������ʱ��(����ʱ�� ��01222301):";
				cin >> e.arrive;
				break;
			}
			else if (e.status == "�뿪")
			{
				cout << "������ʱ��(����ʱ�� ��01222301):";
				cin >> e.left;
				break;
			}
			else
			{
				cout << "������˼,�밴�ո�ʽ���복������" << endl;
			}
		}

		handle(e, Stop, Temp, Queue);

		cout << "����A�����˳� ���������������" << endl;
		char a;
		cin >> a;
		if (a == 'A' || a == 'a')
			break;
	}
}

void handle(car &e, Stack<car> &Stop, Stack<car> &Temp, Queue<QNode, car> &Queue)
{
	if (e.status == "����")
	{
		if (Stop.StackLength() >= Stop.stacksize)
		{
			if (Queue.QueueLength() >= MAXSIZE)
			{
				cout << "������˼,û��λ����" << endl;
				return;
			}

			else
			{
				Queue.EnQueue(e);
				cout << "�����Ŷ��У���" << Queue.QueueLength() << "��" << endl;
				return;
			}
		}

		else
		{
			Stop.Push(e);

			cout << "��ʻ���" << Stop.StackLength() << "�ų�λ" << endl;
			return;
		}
	}

	else if (e.status == "�뿪")
	{
		car a;

		int i = 0;

		if (Stop.StackEmpty())
		{
			cout << "������˼��ͣ����Ϊ�� Ѱ������˵����" << endl;
			return;
		}

		while (a.carnumber != e.carnumber)
		{
			Stop.Pop(a);
			Temp.Push(a);
			i++;
		}

		if (a.carnumber != e.carnumber)
			cout << "������˼��ͣ������û�д�����" << endl;

		int left = e.left;
		Temp.Pop(e);
		e.left = left;
		while (i != 1)
		{
			Temp.Pop(a);
			Stop.Push(a);
			i--;
		}

		int Price;
		Price = e.left - e.arrive;
		cout << "��������:" << e.arrive << endl;
		cout << "�뿪����:" << e.left << endl;
		cout << "��֧��:" << Price << "Ԫ" << endl;

		if (!Queue.QueueEmpty())
		{
			car b;
			b.arrive = e.left;
			Queue.DeQueue(b);
			Stop.Push(b);
			cout << b.carnumber << "�ų���ʻ��ͣ����" << endl;
		}
	}
}

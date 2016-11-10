// 停车场管理C++STL.cpp : 定义控制台应用程序的入口点。
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
		cout << "请输入车牌号码" << endl;
		cin >> e.carnumber;

		while (true)
		{
			cout << "请输入车辆要执行的动作:" << endl;
			cin >> e.status;

			if (e.status == "到达")
			{
				cout << "请输入时间(月日时分 如01222301):";
				cin >> e.arrive;
				break;
			}
			else if (e.status == "离开")
			{
				cout << "请输入时间(月日时分 如01222301):";
				cin >> e.left;
				break;
			}
			else
			{
				cout << "不好意思,请按照格式输入车辆动作" << endl;
			}
		}

		handle(e, Stop, Temp, Queue);

		cout << "按“A”键退出 按其余键继续操作" << endl;
		char a;
		cin >> a;
		if (a == 'A' || a == 'a')
			break;
	}
}

void handle(car &e, Stack<car> &Stop, Stack<car> &Temp, Queue<QNode, car> &Queue)
{
	if (e.status == "到达")
	{
		if (Stop.StackLength() >= Stop.stacksize)
		{
			if (Queue.QueueLength() >= MAXSIZE)
			{
				cout << "不好意思,没有位置了" << endl;
				return;
			}

			else
			{
				Queue.EnQueue(e);
				cout << "正在排队中，第" << Queue.QueueLength() << "号" << endl;
				return;
			}
		}

		else
		{
			Stop.Push(e);

			cout << "请驶入第" << Stop.StackLength() << "号车位" << endl;
			return;
		}
	}

	else if (e.status == "离开")
	{
		car a;

		int i = 0;

		if (Stop.StackEmpty())
		{
			cout << "不好意思，停车场为空 寻不到所说车辆" << endl;
			return;
		}

		while (a.carnumber != e.carnumber)
		{
			Stop.Pop(a);
			Temp.Push(a);
			i++;
		}

		if (a.carnumber != e.carnumber)
			cout << "不好意思，停车场中没有此辆车" << endl;

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
		cout << "到达日期:" << e.arrive << endl;
		cout << "离开日期:" << e.left << endl;
		cout << "请支付:" << Price << "元" << endl;

		if (!Queue.QueueEmpty())
		{
			car b;
			b.arrive = e.left;
			Queue.DeQueue(b);
			Stop.Push(b);
			cout << b.carnumber << "号车已驶入停车场" << endl;
		}
	}
}

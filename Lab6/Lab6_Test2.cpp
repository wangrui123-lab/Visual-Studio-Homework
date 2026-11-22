#include<iostream>
using namespace std;
typedef int DataType;
struct Node
{
	DataType data;
	Node* next;
};
struct LinkQueue
{
	Node* front;
	Node* rear;
};
void InitQueue(LinkQueue& q)
{
	Node* head = new Node;
	head->next = nullptr;
	q.front = head;
	q.rear = head;
}
bool IsEmpty(const LinkQueue& q)
{
	return q.front == q.rear;
}
void Enqueue(LinkQueue& q, DataType x)
{
	Node* newNode = new Node;
	newNode->data = x;
	newNode->next = nullptr;
	q.rear->next = newNode;
	q.rear = newNode;
}
bool Dequeue(LinkQueue& q, DataType& x)
{
	if (IsEmpty(q))
	{
		cout << "队列为空，出队失败" << endl;
		return false;
	}
	Node* p = q.front->next;
	x = p->data;
	q.front->next = p->next;
	if (q.rear == p)
	{
		q.rear = q.front;
	}
	delete p;
	return true;
}
bool GetFront(const LinkQueue& q, DataType& x)
{
	if (IsEmpty(q))
	{
		cout << "队列为空，没有队首元素" << endl;
		return false;
	}
	x = q.front->next->data;
	return true;
}
void DestroyQueue(LinkQueue& q)
{
	Node* p = q.front;
	while (p != nullptr)
	{
		Node* temp = p;
		p = p->next;
		delete temp;
	}
	q.front = nullptr;
	q.rear = nullptr;
}
int main()
{
	LinkQueue q;
	InitQueue(q);
	DataType x;
	cout << "测试入队" << endl;
	cout << "入队：10,20,30" << endl;
	Enqueue(q, 10);
	Enqueue(q, 20);
	Enqueue(q, 30);
	cout << "测试获取队首" << endl;
	if (GetFront(q, x))
	{
		cout << "当前队首元素为：" << x << endl;
	}
	cout << "测试出队" << endl;
	cout << "连续出队两个元素:" << endl;
	if (Dequeue(q, x))cout << "出队:" << x << endl;
	if (Dequeue(q, x))cout << "出队:" << x << endl;
	if (GetFront(q, x))
	{
		cout << "出队后，新的队首元素为：" << x << endl;
	}
	cout << "测试【出队最后一个元素】的极端情况" << endl;
	cout << "将最后一个元素出队:" << endl;
	(Dequeue(q,x));
	cout << "再次入队" << endl;
	cout << "在空队列入队：99" << endl;
	Enqueue(q, 99);
	if (GetFront(q, x))
	{
		cout << "当前队首元素为：" <<x<< endl;
	}
	DestroyQueue(q);
	cout << "程序结束，内存已全部释放" << endl;
	return 0;
}
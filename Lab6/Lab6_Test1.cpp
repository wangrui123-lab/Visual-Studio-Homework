#include <iostream>
using namespace std;
typedef int DataType;
struct SeqQueue
{
	int front;
	int rear;
	int maxsize;
	DataType* elements;
};
void InitQueue(SeqQueue& q, int max)
{
	q.maxsize = max;
	q.elements = new DataType[max];
	q.front = 0;
	q.rear = 0;
}
bool IsEmpty(const SeqQueue& q)
{
	return q.front == q.rear;
}
bool IsFull(const SeqQueue& q)
{
	return (q.rear + 1) % q.maxsize == q.front;
}
bool EnQueue(SeqQueue& q, DataType x)
{
	if (IsFull(q))
	{
		cout << "队列已满，入队失败" << endl;
		return false;
	}
	q.elements[q.rear] = x;
	q.rear = (q.rear + 1) % q.maxsize;
	return true;
}
bool Dequeue(SeqQueue& q, DataType& x)
{
	if (IsEmpty(q))
	{
		cout << "队列为空，出队失败" << endl;
		return false;
	}
	x = q.elements[q.front];
	q.front = (q.front + 1) % q.maxsize;
	return true;
}
bool GetHead(const SeqQueue q, DataType& x)
{
	if (IsEmpty(q))
	{
		cout << "队列为空，没有队首元素"<< endl;
		return false;
	}
	x = q.elements[q.front];
	return true;
}
int main()
{
	SeqQueue q;
	InitQueue(q, 5);
	EnQueue(q, 10);
	EnQueue(q, 20);
	EnQueue(q, 30);
	EnQueue(q, 40);
	cout << "尝试入队第5个元素50" << endl;
	EnQueue(q, 50);
	DataType x;
	cout << "测试获取队首元素" << endl;
	if (GetHead(q, x))
	{
		cout << "当前队首元素为：" << x << endl;
	}
	cout << "测试出队" << endl;
	cout << "连续出队两个元素：" << endl;
	if (Dequeue(q, x))cout << "出队：" << x << endl;
	if (Dequeue(q, x))cout << "出队：" << x << endl;
	cout << "测试循环特性" << endl;
	cout << "再次入队两个元素（50,60）:" << endl;
	EnQueue(q, 50);
	EnQueue(q, 60);
	if (GetHead(q, x))
	{
		cout << "现在新的队首元素为：" << x << endl;
	}
	delete[] q.elements;
	cout << "程序结束，内存已释放" << endl;
	return 0;
}
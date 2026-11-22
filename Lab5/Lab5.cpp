#include<iostream>
#include<new>
using namespace std;
typedef int DataType;
struct LinkStack {
	DataType data;
	LinkStack* next;
};
struct CharStack {
	char data;
	CharStack* next;
};
//初始化
template<class Node>
void InitStack(Node*& S) {
	S = nullptr;
}
//判空
template<class Node>
bool StackEmpty(Node* S) {
	return S == nullptr;
}
//入栈
template<class Node,class T>
bool Push(Node*& S, T x) {
	Node* p = new (nothrow) Node;
	if (!p)
	return false;
	p->data = x;
	p->next = S;
	S = p;
	return true;
}
//出栈
template<class Node,class T>
bool Pop(Node*& S, T& x) {
	if (StackEmpty(S))
	return false;
	Node* p = S;
	x = p->data;
	S = p->next;
	delete p;
	return true;
}
//取栈顶元素
template<class Node,class T>
bool GetTop(Node* S, T& x) {
	if (S == nullptr)
		return false;
	x = S->data;
	return true;
}
//销毁栈
template<class Node>
void DestroyStack(Node*& S) {
	while (S!=nullptr) {
		Node* p = S;
		S = S->next;
		delete p;
	}
}
bool BracketMatch(const char* str) {
	CharStack* stack;
	InitStack(stack);

	bool flag = true;
	int i = 0;
	char ch;
	while (flag && (ch = str[i++]) != '\0') {
		char top;
		switch (ch) {
		case'(':
		case'[':
		case'{':
			Push(stack, ch);
			break;
		case')':
			if (!StackEmpty(stack) && GetTop(stack, top) && top == '(')
				Pop(stack, top);
			else
				flag = false;
			break;
		case']':
			if (!StackEmpty(stack) && GetTop(stack, top) && top == '[')
				Pop(stack, top);
			else
				flag = false;
			break;
		case'}':
			if (!StackEmpty(stack) && GetTop(stack, top) && top == '{')
				Pop(stack, top);
			else
				flag = false;
			break;
		default:
			break;
		}
	}
		bool ok = flag && StackEmpty(stack);
		DestroyStack(stack);
		return ok;
	}
	int main(){
		cout << "1.链栈基本操作测试" <<endl;
		LinkStack* S;
		InitStack(S);
		cout << "初始化后栈是否为空:" <<(StackEmpty(S)?"是":"否") << endl;
		for (int i = 1; i <= 5; i++) {
			Push(S, i * 10);
		}
			cout << "将10 20 30 40 50 依次入栈" << endl;
			DataType x;
			if (GetTop(S, x))
				cout << "栈顶元素为:" << x << endl;
			cout << "出栈序列:" << endl;
			while (Pop(S, x))
				cout << x << " ";
			cout << endl;
			cout << "全部出栈后栈是否为空:" << (StackEmpty(S) ? "是" :"否") << endl;
			DestroyStack(S);
			cout << "2.括号匹配测试" << endl;
			const char* cases[] = { "()", "([])", "{[()]}", "([)]", "((())", };
			for (int i = 0;i < sizeof(cases)/sizeof(cases[0]);++i) {
				cout << "\"" << cases[i] << "\": " << (BracketMatch(cases[i]) ? "匹配" : "不匹配") << endl;
			}
			return 0;
	}
#include <iostream>
#include <cstring>
using namespace std;
//定义联系人生日结构体
struct Birthday //联系人生日
{
	int year; //年
	int month; //月
	int day; //日
};

//定义联系人结构体
struct Contact
{
	char name[50]; //联系人姓名
	char phone[12]; //联系人电话
	Birthday birthday; //联系人生日
	int age; //联系人年龄
};

//定义通讯录结点结构体
struct Node
{
	Contact data; //联系人信息
	Node* next; //指向下一个结点的指针
};

//在此区域完成通讯录功能的函数实现
/*函数功能：初始化一个空的通讯录链表*/
Node* InitAddressBook()
{
	Node* head = new Node;
	if (head == NULL)
	{
		cout << "内存分配失败！" << endl;
		return NULL;
	}
	head->next = NULL;
	return head;
}
/*函数功能：采用尾插法创建一个通讯录链表*/
bool CreateAddressBookTail(Node* head, Contact data)
{
	Node* node = new Node;
	if (node == NULL)
	{
		cout << "内存分配失败！" << endl;
		return false;
	}
	node->data = data;
	node->next = NULL;
	Node* tail = head;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = node;
	return true;
}
/*函数功能：输入单个联系人信息*/
Contact InputContact()
{
	Contact data;
	cout << "请输入联系人姓名:";
	cin >> data.name;
	cout << "请输入联系人电话:" << endl;
	cin >> data.phone;
	cout << "请输入联系人生日（年 月 日，用空格隔开）:" << endl;
	while (!(cin >> data.birthday.year >> data.birthday.month >> data.birthday.day))
	{
		if (cin.eof()) return data;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "【输入错误】年月日必须是数字，请重新输入:";
	}
	data.age = 2026 - data.birthday.year;
	return data;
}
/*函数功能：输出单个联系人信息*/
void OutputContact(Contact data)
{
	cout << "姓名：" << data.name << endl;
	cout << "电话：" << data.phone << endl;
	cout << "生日：" << data.birthday.year << "年" << data.birthday.month << "月" << data.birthday.day << "日" << endl;
	cout << "年龄:" << data.age << endl;
}
/*函数功能:输出通讯录中所有联系人信息*/
void OutputAddressBook(Node* head)
{
	Node* node = head->next;
	if (node == NULL)
	{
		cout << "通讯录为空！" << endl;
		return;
	}
	while (node)
	{
		OutputContact(node->data);
		cout << "---------------" << endl;
		node = node->next;
	}
}
/*函数功能:按姓名查找通讯录中指定联系人信息*/
Node* SearchContactByName(Node* head, char* name)
{
	Node* node = head->next;
	while (node)
	{
		if (strcmp(node->data.name, name) == 0)
			return node;
		node = node->next;
	}
	return NULL;
}
/*函数功能：查找指定联系人的前驱结点*/
Node* SearchPreNode(Node* head, Node* target)
{
	for (Node* pre = head;pre->next != NULL;pre = pre->next)
	{
		if (pre->next == target)
			return pre;
	}
	return NULL;
}
/*函数功能:删除指定联系人*/
bool DeleteContact(Node* head, Node* target)
{
	Node* pre = SearchPreNode(head, target);
	if (pre)
	{
		pre->next = target->next;
		delete target;
		return true;
	}
	return false;
}
/*函数功能：打印用户选择菜单*/
int PrintMenu()
{
	int choice;
	cout << "\n------通讯录管理程序-----" << endl;
	cout << "1.添加联系人" << endl;
	cout << "2.删除联系人" << endl;
	cout << "3.查找联系人" << endl;
	cout << "4.修改联系人" << endl;
	cout << "5.显示所有联系人" << endl;
	cout << "6.退出程序" << endl;
	cout << "请输入您的选择（1-6）:";
	while (!(cin >> choice))
	{
		if (cin.eof()) return 6;
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "【输入无效】请输入纯数字（1-6）：";
	}
	return choice;
}
int main()
{
	//主函数进行测试
	Node* head = InitAddressBook();
	if (head == NULL) return 1;
	int choice;
	do
	{
		choice = PrintMenu();
		switch (choice)
		{
		case 1:
		{
			Contact data = InputContact();
			if (CreateAddressBookTail(head, data))
				cout << "添加成功！" << endl;
			else
				cout << "添加失败！" << endl;
			break;
		}
		case 2:
		{
			char name[50];
			cout << "请输入要删除的联系人姓名:";
			cin >> name;
			Node* target = SearchContactByName(head, name);
			if (target)
			{
				if (DeleteContact(head, target))
					cout << "删除成功！" << endl;
				else
					cout << "删除失败！" << endl;
			}
			else
			{
				cout << "未找到该联系人！" << endl;
			}
			break;
		}
		case 3:
		{
			char name[50];
			cout << "请输入要查找的联系人姓名：";
			cin >> name;
			Node* target = SearchContactByName(head, name);
			if (target)
				OutputContact(target->data);
			else
				cout << "未找到该联系人！" << endl;
			break;
		}
		case 4:
		{
			char name[50];
			cout << "请输入要修改的联系人姓名：";
			cin >> name;
			Node* target = SearchContactByName(head, name);
			if (target)
			{
				cout << "已找到该联系人，请输入新的信息:" << endl;
				target->data = InputContact();
				cout << "修改成功！" << endl;
			}
			else
			{
				cout << "未找到该联系人！" << endl;
			}
			break;
		}
		case 5:
		{
			OutputAddressBook(head);
			break;
		}
		case 6:
		{
			cout << "感谢使用，程序退出！" << endl;
			break;
		}
		default:
		{
			cout << "输入无效，请输入1-6之间的数字！" << endl;
			break;
		}
		}
	} while (choice != 6);
	Node* p = head;
	while (p != NULL)
	{
		Node* q = p->next;
		delete p;
		p = q;
	}

	return 0;
}
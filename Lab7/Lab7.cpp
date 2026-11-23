#include<iostream>
using namespace std;
//定义二叉树结点结构
typedef char ElemType;
struct BiTNode {
	ElemType data;
	BiTNode* lchild;
	BiTNode* rchild;
};
typedef BiTNode* BiTree;
//利用先序遍历创建二叉树
void CreateBiTree(BiTree& T)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
//先序遍历
void PreOrderTraverse(BiTree T)
{
	if (T == NULL)return;
	cout << T->data << " ";
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}
//中序遍历
void InOrderTraverse(BiTree T)
{
	if (T == NULL)return;
	InOrderTraverse(T->lchild);
	cout << T->data << " ";
	InOrderTraverse(T->rchild);
}
//后序遍历
void PostOrderTraverse(BiTree T)
{
	if (T == NULL)return;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	cout << T->data << " ";
}
int main()
{
	BiTree root = NULL;
	cout << "请输入先序序列" << endl;
	CreateBiTree(root);
	cout << "遍历结果" << endl;
	cout << "先序遍历";
	PreOrderTraverse(root);
	cout << endl;
	cout << "中序遍历";
	InOrderTraverse(root);
	cout << endl;
	cout << "后序遍历";
	PostOrderTraverse(root);
	cout << endl;
	return 0;
}
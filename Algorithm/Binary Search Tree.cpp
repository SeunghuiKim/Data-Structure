#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

class TreeNode
{
public:
	int m_data;
	TreeNode *left, *right;
};

// ��ȯ Ž�� �Լ�
	/*
	TreeNode* searchNode(TreeNode *root, int key)
	{
		if (root == NULL)
			return NULL;
		if (root->m_data == key)
			return root;
		else if (root->m_data > key)
			return searchNode(root->left, key);
		else
			return searchNode(root->right, key);
	}
	*/

	// �ݺ� Ž�� �Լ�
TreeNode* searchNode(TreeNode *root, int key)
{
	while (root != NULL)
	{
		if (root->m_data == key)
			return root;
		else if (root->m_data > key)
			root = root->left;
		else
			root = root->right;
	}
	cout << "Ž���� Ű�� �����ϴ�." << endl;
	return NULL;
}

// ���� �Լ�
void insertNode(TreeNode **root, int key)
{
	TreeNode *parentNode = NULL, *currentNode, *newNode;
	currentNode = *root;

	while (currentNode != NULL)	// key�� ���ԵǾ�� �� ��ġ�� �ݺ������� ã�� while��
	{
		if (currentNode->m_data == key)	// ���� Ž�� Ʈ���� �����Ͱ� �����ϴ� ���
			return;

		parentNode = currentNode;
		if (currentNode->m_data > key)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}

	newNode = (TreeNode *)new TreeNode;	// ���ο� TreeNode ������� �Ҵ�� ������ ����
	if (newNode == NULL) return;

	newNode->m_data = key;
	newNode->left = newNode->right = NULL;


	if (parentNode != NULL)	// ���� Ž�� Ʈ���� key ���� ����Ǿ� �ִ� ���
		if (parentNode->m_data > key)	// ���� �ڽ� ���� ����
			parentNode->left = newNode;
		else parentNode->right = newNode;	// ������ �ڽ� ���� ����
	else
		*root = newNode;
}

// ���� �Լ�
void deleteNode(TreeNode **root, int key)
{
	TreeNode *pNode = NULL, *curNode;
	TreeNode *child, *succ, *succParent;
	curNode = *root;

	while (curNode != NULL && curNode->m_data != key) // key ���� ���� ��� ã��
	{
		pNode = curNode;	// pNode = �θ� ���
		if (curNode->m_data > key)	// curNode = key���� ���� ���
			curNode = curNode->left;
		else curNode = curNode->right;
	}

	if (curNode == NULL)
	{
		cout << "key is not int the tree" << endl;
		return;
	}

	if (curNode->left == NULL && curNode->right == NULL)	// �ڽ� ��尡 ���� ���. ��, ������ 0�� ���
	{
		if (pNode != NULL)	// pNode�� �ִ� ���
			if (pNode->left == curNode)
				pNode->left = NULL;
			else
				pNode->right = NULL;
		else  // pNode�� ���� ���
			*root = NULL;
	}
	else if (curNode->left == NULL || curNode->right == NULL)	// ������ 1�� ���
	{
		child = (curNode->left != NULL) ? curNode->left : curNode->right;
		if (pNode != NULL)	// pNode�� �ִ� ���
		{
			if (pNode->left == curNode)
				pNode->left = child;
			else
				pNode->right = child;
		}
		else  // pNode�� ���� ���
		{
			if (curNode->left == NULL)
			{
				curNode = child;
				curNode = curNode->left;
			}
			else
			{
				curNode = child;
				curNode = curNode->right;
			}
		}
	}
	else  // ������ ����� ������ 2�� ���
	{
		succParent = curNode;	// ��ü�� �θ� ���(succParent)
		succ = curNode->left;
		while (succ->right != NULL)
		{
			succParent = succ;
			succ = succ->right;
		}

		if (succParent->right == succ)
			succParent->right = succ->left;
		else
			succParent->left = succ->left;

		curNode->m_data = succ->m_data;
		curNode = succ;
	}
	delete(curNode);
}
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

// 순환 탐색 함수
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

	// 반복 탐색 함수
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
	cout << "탐색한 키가 없습니다." << endl;
	return NULL;
}

// 삽입 함수
void insertNode(TreeNode **root, int key)
{
	TreeNode *parentNode = NULL, *currentNode, *newNode;
	currentNode = *root;

	while (currentNode != NULL)	// key가 삽입되어야 할 위치를 반복적으로 찾는 while문
	{
		if (currentNode->m_data == key)	// 이진 탐색 트리에 데이터가 존재하는 경우
			return;

		parentNode = currentNode;
		if (currentNode->m_data > key)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}

	newNode = (TreeNode *)new TreeNode;	// 새로운 TreeNode 저장공간 할당과 데이터 저장
	if (newNode == NULL) return;

	newNode->m_data = key;
	newNode->left = newNode->right = NULL;


	if (parentNode != NULL)	// 이진 탐색 트리에 key 값이 저장되어 있는 경우
		if (parentNode->m_data > key)	// 왼쪽 자식 노드로 연결
			parentNode->left = newNode;
		else parentNode->right = newNode;	// 오른쪽 자식 노드로 연결
	else
		*root = newNode;
}

// 삭제 함수
void deleteNode(TreeNode **root, int key)
{
	TreeNode *pNode = NULL, *curNode;
	TreeNode *child, *succ, *succParent;
	curNode = *root;

	while (curNode != NULL && curNode->m_data != key) // key 값을 가진 노드 찾기
	{
		pNode = curNode;	// pNode = 부모 노드
		if (curNode->m_data > key)	// curNode = key값을 가진 노드
			curNode = curNode->left;
		else curNode = curNode->right;
	}

	if (curNode == NULL)
	{
		cout << "key is not int the tree" << endl;
		return;
	}

	if (curNode->left == NULL && curNode->right == NULL)	// 자식 노드가 없는 경우. 즉, 차수가 0인 경우
	{
		if (pNode != NULL)	// pNode가 있는 경우
			if (pNode->left == curNode)
				pNode->left = NULL;
			else
				pNode->right = NULL;
		else  // pNode가 없는 경우
			*root = NULL;
	}
	else if (curNode->left == NULL || curNode->right == NULL)	// 차수가 1인 경우
	{
		child = (curNode->left != NULL) ? curNode->left : curNode->right;
		if (pNode != NULL)	// pNode가 있는 경우
		{
			if (pNode->left == curNode)
				pNode->left = child;
			else
				pNode->right = child;
		}
		else  // pNode가 없는 경우
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
	else  // 삭제할 노드의 차수가 2인 경우
	{
		succParent = curNode;	// 대체할 부모 노드(succParent)
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
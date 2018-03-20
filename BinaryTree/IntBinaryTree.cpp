#include "IntBinaryTree.h"
#include <iostream>

using namespace std;

void IntBinaryTree::insertNode(int num)
{
	TreeNode *newNode;

	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = NULL;

	insert(root, newNode);
}

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == NULL)
	{
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value)
	{
		insert(nodePtr->left, newNode);
	}
	else
	{
		insert(nodePtr->right, newNode);
	}
}


void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}
void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->left);
		displayInOrder(nodePtr->right);
	}
}

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->right);
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
	}
}

bool IntBinaryTree::searchNode(int num)
{
	TreeNode *nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->value == num)
		{
			return true;
		}
		else if(num < nodePtr->value)
		{
			nodePtr = nodePtr->left;
		}
		else
		{
			nodePtr = nodePtr->right;
		}
	}
	return false;
}
void IntBinaryTree::remove(int num)
{
	deleteNode(num, root);
}
void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
	if (num < nodePtr->value)
	{
		deleteNode(num, nodePtr->left);
	}
	else if(num > nodePtr->value)
	{
		deleteNode(num, nodePtr->right);
	}
	else
	{
		makeDeletion(nodePtr);
	}
}
void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
	TreeNode *tempNodePtr;

	if (nodePtr == NULL)
	{
		cout << "Can't delete, empty node" << endl;
	}
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left)
		{
			tempNodePtr = tempNodePtr->left;
		}
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
		{
			destroySubTree(nodePtr->left);
		}
		if (nodePtr->right)
		{
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;
	}
}
//IntBinaryTree::IntBinaryTree()
//{
//	//root = NULL;
//}
//
//
//IntBinaryTree::~IntBinaryTree()
//{
//	//destroySubTree(root);
//}

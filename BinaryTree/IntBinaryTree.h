#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H

#include<iostream>
class IntBinaryTree
{
private:
	struct TreeNode
	{
		double value;
		TreeNode *left;
		TreeNode *right;
	};
	TreeNode *root;

	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(int, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;

public:
	IntBinaryTree()
	{
		root = NULL;
	}

	/*~IntBinaryTree()
	{
		destroySubTree(root);
	}*/

	//BinaryTree operation
	void insertNode(int);
	bool searchNode(int);
	void remove(int);

	void displayInOrder() const
	{
		displayInOrder(root);
	}
	void displayPreOrder() const
	{
		displayPreOrder(root);
	}
	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
};
#endif // !INTBINARYTREE_H





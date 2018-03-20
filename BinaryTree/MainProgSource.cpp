#include<iostream>
#include "IntBinaryTree.h"


using namespace std;

int main()
{
	IntBinaryTree tree;

	cout << "Inserting Node." << endl;
	tree.insertNode(5);
	tree.insertNode(8);
	tree.insertNode(3);
	tree.insertNode(12);
	tree.insertNode(9);


	cout << "Display in order. " << endl;
	tree.displayInOrder();

	cout << "Display pre order" << endl;
	tree.displayPreOrder();

	cout << "Display post order" << endl;
	tree.displayPostOrder();

	cout << "Delete 9.." << endl;
	tree.remove(9);
	tree.displayInOrder();

	cout << "Searching 9" << endl;
	if (tree.searchNode(9))
	{
		cout << "9 is found" << endl;
	}
	else
	{
		cout << "9 is no found" << endl;
	}
	cout << "Delete 8.." << endl;
	tree.remove(8);
	tree.displayInOrder();


	system("pause");
	return 0;
}
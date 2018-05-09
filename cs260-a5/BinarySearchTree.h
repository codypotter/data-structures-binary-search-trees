/*
Author: Cody Potter
Date:	2018-05-08
File:	BinarySearchTree.h
Desc:	Binary Search Tree class with methods for insertion
		and printing preOrder, postOrder, and inOrder
*/
#pragma once
#include<iostream>
#include<functional>
#include<string>
using namespace std;

/*
Class:		Binary Search Tree
Desc:		Binary Search Tree class with methods for insertion
			and printing preOrder, postOrder, and inOrder
*/
template <class dataType>
class BinarySearchTree {
public:
	struct node {
		dataType data;
		node* left;
		node* right;
	};
	BinarySearchTree();
	bool insert(dataType data);
	void printInOrder();
	void printPreOrder();
	void printPostOrder();

private:
	node* root;
	bool insert(node* &current, dataType data);
	void traverseInOrder(node* current, const function<void(string)> &funcToCall);
	void traversePreOrder(node* current, const function<void(string)> &funcToCall);
	void traversePostOrder(node* current, const function<void(string)> &funcToCall);
};

/*-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|*/
/*-\|/-\|/-\|/-\|/    PUBLIC METHODS   \|/-\|/-\|/-\|/-\|*/
/*-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|*/
/*
Method:		Insert
Desc:		Interface for calling recursive private insert method
Parameters:	data of type dataType
Return:		true if successful
*/
template <class dataType>
bool BinarySearchTree<dataType>::insert(dataType data) {
	return this->insert(root, data);
}

/*
Method:		Print inOrder
Desc:		Interface for calling recursive traverse inOrder method
			starts off traversal calling print function as it goes
Parameters:	void
Return:		void
*/
template<class dataType>
void BinarySearchTree<dataType>::printInOrder() {
	this->traverseInOrder(this->root, printThis);
}

/*
Method:		Print preOrder
Desc:		Interface for calling recursive traverse preOrder method
			starts off traversal calling print function as it goes
Parameters:	void
Return:		void
*/
template<class dataType>
void BinarySearchTree<dataType>::printPreOrder() {
	this->traversePreOrder(this->root, printThis);
}

/*
Method:		Print postOrder
Desc:		Interface for calling recursive traverse postOrder method
			starts off traversal calling print function as it goes
Parameters:	void
Return:		void
*/
template<class dataType>
void BinarySearchTree<dataType>::printPostOrder() {
	this->traversePostOrder(this->root, printThis);
}
/*-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|*/
/*-\|/-\|/-\|/-\|/    PRIVATE METHODS    /-\|/-\|/-\|/-\|*/
/*-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|*/
/*
Method:		Insert
Desc:		Traverses through tree until it finds the correct
			insertion point. Creates a new leaf there. 
Parameters:	node pointer to current, data of type dataType
Return:		true if successful
*/
template <class dataType>
bool BinarySearchTree<dataType>::insert(node* &current, dataType data) {
	if (current == NULL) {
		current = new node;
		current->data = data;
		current->left = NULL;
		current->right = NULL;
		return true;
	} else if (data < current->data) {
		return insert(current->left, data);
	} else {
		return insert(current->right, data);
	}
}

/*
Method:		Traverse In Order
Desc:		Traverses tree in order, calling a function on each item
Parameters:	pointer to current node and a function to call on that node
Return:		void
*/
template<class dataType>
void BinarySearchTree<dataType>::traverseInOrder(node* current, const function<void(string)> &funcToCall) {
	if (current) { 
		traverseInOrder(current->left, funcToCall);
		funcToCall(current->data);
		traverseInOrder(current->right, funcToCall);
	}
}

/*
Method:		Traverse Pre Order
Desc:		Traverses tree pre order, calling a function on each item
Parameters:	pointer to current node and a function to call on that node
Return:		void
*/
template<class dataType>
void BinarySearchTree<dataType>::traversePreOrder(node* current, const function<void(string)> &funcToCall) {
	if (current) {
		funcToCall(current->data);
		traversePreOrder(current->left, funcToCall);
		traversePreOrder(current->right, funcToCall);
	}
}

/*
Method:		Traverse Post Order
Desc:		Traverses tree post order, calling a function on each item
Parameters:	pointer to current node and a function to call on that node
Return:		void
*/
template<class dataType>
void BinarySearchTree<dataType>::traversePostOrder(node* current, const function<void(string)> &funcToCall) {
	if (current) {
		traversePostOrder(current->left, funcToCall);
		traversePostOrder(current->right, funcToCall);
		funcToCall(current->data);
	}
}

/*
Method:		Binary Search Tree Constructor
Desc:		Makes a new tree, setting root to NULL
Parameters:	void
Return:		void
*/
template <class dataType>
BinarySearchTree<dataType>::BinarySearchTree() {
	root = NULL;
}

/*-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|*/
/*-\|/-\|/-\|/-\|/    FUNCTIONS    \|/-\|/-\|/-\|/-\|/-\|*/
/*-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|/-\|*/
/*
Function:	Print This
Desc:		sends a string to cout
Parameters:	String to print
Return:		void
*/
void printThis(string stringToPrint) {
	cout << stringToPrint << ' ';
}

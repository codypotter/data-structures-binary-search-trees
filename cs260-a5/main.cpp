/*
Author: Cody Potter
Date:	2018-05-08
File:	main.cpp
Desc:	entry point for program, makes a binary tree object, fills it with some
		pokemon, and prints them in various orders
*/
#include"BinarySearchTree.h"

using namespace std;

int main(void) {
	cout << "CS260 Assignment 5a - Binary Trees, part 1" << endl;
	cout << "Cody Potter" << endl << endl;

	BinarySearchTree<string> tree;
	tree.insert("Jynx");
	tree.insert("Charmander");
	tree.insert("Snorlax");
	tree.insert("Clefairy");
	tree.insert("Diglett");
	tree.insert("Kakuna");
	tree.insert("Meowth");
	tree.insert("Nidorino");
	tree.insert("Pikachu");
	tree.insert("Blastoise");
	tree.insert("Squirtle");
	tree.insert("Ivysaur");
	tree.insert("Bulbasaur");
	tree.insert("Abra");

	
	tree.printInOrder();
	cout << endl;
	tree.printPreOrder();
	cout << endl;
	tree.printPostOrder();
	cout << endl;


	return 0;
}
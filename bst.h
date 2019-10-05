//bst.h
//jrlevin
#include<iostream>
using namespace std;
#include "tnode.h"
#ifndef BST_H
#define BST_H

class BST
{
	public:
		BST():  root(NULL) {};
		~BST(){ clean(root); root = NULL;
		};

		//insert value into tree
		bool insert(string akey, string aval)
		{ 
			if(root == NULL)
			{
				root = new Tnode(akey, aval);
				return true;
			}
			else
				root=insert(root, akey, aval); 
			return true;
		};

		//remove node with given string
		void remove(string akey)
		{
			root=remove(root, akey);
		};

		//print values of nodes inorder
		void print_inorder()
		{
			print_inorder(root);
			cout << endl;
		};

		//print values with specified prefix
		void findPrint(string akey)
		{
			findPrint(root, akey);
			cout<<endl;
		};

		//print heights of nodes inorder
		void heightPrint()
		{
			heightPrint(root);
			cout<<endl;
		};

		//print balance factors of nodes inorder
		void printBF()
		{
			printBF(root);
			cout<<endl;
		};

	private:
		Tnode *root = NULL;
		void clean(Tnode* cur);
		Tnode* insert(Tnode* cur, string akey, string aval);
		Tnode* remove(Tnode* cur, string akey);
		void print_inorder(Tnode* cur);
		void findPrint(Tnode* cur, string akey);
		void heightPrint(Tnode* cur);
		void printBF(Tnode* cur);

		int getHeight(Tnode* cur);  //return height of given node
		void updateHeight(Tnode* cur);  //update heighrt of given node
		int balanceFactor(Tnode* cur);  //return balance factor of given node
		Tnode* restoreBalance(Tnode* cur);  //restore balance of tree rooted at given node
		Tnode* rightRotation(Tnode* cur); //perform right rotation on given node
		Tnode* leftRotation(Tnode* cur);  //perform left rotation on given node
		Tnode* get_leftmost(Tnode* cur);  //return leftmost(smallest) node of tree rooted at given node
};


#endif

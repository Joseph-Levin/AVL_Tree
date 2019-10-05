//bst.cpp
//jrlevin
#include<iostream>
#include "bst.h"
using namespace std;

//prints key and values using inorder traversal
void BST::print_inorder(Tnode *cur)
{
	if (cur == NULL)
		return;
	print_inorder(cur->left);
	cout <<"("<<cur->key<<"){";
	for (int i=0; i< (int)(cur->value.size()); i++)
		cout<< (cur->value[i]) <<" ";
	cout<<"} ";
	print_inorder(cur->right);
}//print_inorder

//prints all values with given key
void BST::findPrint(Tnode* cur, string akey)
{
	if (cur == NULL)
		return;
	if (akey == cur->key)
	{
		for (int i=0; i< (int)(cur->value.size()); i++)
			cout<< (cur->value[i]) <<" ";
	}

	else if (akey < cur->key)
		findPrint(cur->left, akey);

	else if (akey > cur->key)
		findPrint(cur->right, akey);
}//findPrint

//prints heights of nodes in order
void BST::heightPrint(Tnode* cur)
{
	if (cur == NULL)
		return;
	heightPrint(cur->left);
	cout<< cur->height <<" ";
	heightPrint(cur->right);
}//heightPrint

//deletes Tree
void BST::clean(Tnode *cur)
{
	if(cur == NULL)
		return;
	clean(cur->left);
	clean(cur->right);
	delete cur;
}//clean()

//updates height of current node
void BST::updateHeight(Tnode* cur)
{
	if (cur == NULL)
		return;
	int lheight = getHeight(cur->left);
	int rheight = getHeight(cur->right);

	cur->height = 1 + max(lheight, rheight);
}//updateHeight

//returns height of node
int BST::getHeight(Tnode* cur)
{
	if (!cur)
		return -1;
	else
		return cur->height;
}//getHeight

//returns balance factor of current node; bf = height of left child - height of right child
int BST::balanceFactor(Tnode* cur)
{
	return getHeight(cur->left) - getHeight(cur->right);
}//balanceFactor

//prints balance factors using inorder traversal
void BST::printBF(Tnode* cur)
{
	if (cur == NULL)
		return;
	printBF(cur->left);
	cout<< balanceFactor(cur) <<" ";
	printBF(cur->right);
}//printBF

//inserts given value using prefix of specified length as a key
Tnode* BST::insert(Tnode* cur, string akey, string aval)
{
	int bf; //balance factor
	if (akey < cur->key)  //if given key is less than current key, go left
	{
		if (cur->left == NULL)  //if left child doesn't exist, insert new node here
		{
			cur->left = new Tnode(akey, aval);
			updateHeight(cur);
			return cur;
		}
		else  //continue search for correct location for value
		{
			cur->left = insert(cur->left, akey, aval);
			bf = balanceFactor(cur);  //after return, rebalance the subtree if necessary
			if (bf<-1 || bf>1)
				cur = restoreBalance(cur);
			updateHeight(cur);
			return cur;
		}
	}//if 

	else if (akey > cur->key) //if given key is greater than current key, go right
	{
		if (cur->right == NULL)  //if right child doesn't exist, insert new node here
		{
			cur->right = new Tnode(akey, aval);
			updateHeight(cur);
			return cur;
		}
		else  //continure serach for correct location for value
		{
			cur->right = insert(cur->right, akey, aval);
			bf = balanceFactor(cur);  //after return, rebalance subtree if necessary
			if (bf<-1 || bf>1)
				cur = restoreBalance(cur);
			updateHeight(cur);
			return cur;
		}
	}//else if

	else  //node with key already exists, emplace value in back of vector of strings
	{
		(cur->value).push_back(aval);
		return cur;
	}
}//insert

//Perform right rotation on current node
Tnode* BST::rightRotation(Tnode* cur)
{
	Tnode* leftChild = cur->left;
	cur->left = cur->left->right;
	updateHeight(cur);
	leftChild->right = cur;
	updateHeight(leftChild);
	return leftChild;
}//rightRotation

//Perform left rotation on current node
Tnode* BST::leftRotation(Tnode* cur)
{
	Tnode* rightChild = cur->right;
	cur->right = cur->right->left;
	updateHeight(cur);
	rightChild->left = cur;
	updateHeight(rightChild);
	return rightChild;
}//leftRotation

//Called when |bf of cur| is greater than 1;  Restores balance of subtree rooted at cur
Tnode* BST::restoreBalance(Tnode* cur)
{
	int bf = balanceFactor(cur);

	if (bf>1)  //Balance factore is 2
	{
		if (balanceFactor(cur->left) >= 0)  //Outside rotation
		{
			return rightRotation(cur);
		}
		else  //Inside Rotation
		{
			cur->left = leftRotation(cur->left);
			return rightRotation(cur);
		}
	}//if

	else  //Balance factor is -2
	{
		if (balanceFactor(cur->right) <= 0) //Outside rotation
		{
			return leftRotation(cur);
		}
		else  //Inside rotation
		{
			cur->right = rightRotation(cur->right);
			return leftRotation(cur);
		}
	}//else
}//restoreBalance

//Return leftmost(smallest) node of tree rooted at cur
Tnode* BST::get_leftmost(Tnode* cur)
{
	if (cur == NULL || cur->left == NULL)
		return cur;

	else
		return get_leftmost(cur->left);
}//get_leftmost

//Remove node with specified key, keeping tree balanced
Tnode* BST::remove(Tnode* cur, string akey)
{
	if (cur == NULL)  //if node does not exist
		return cur;

	int bf; //balance factor

	if (akey < cur->key)  //if key is less than current key, go left
	{
		cur->left = remove(cur->left, akey);
		bf = balanceFactor(cur);  //if unbalanced, restore balance
		if (bf < -1 || bf >1)
			cur = restoreBalance(cur);
		updateHeight(cur);
		return cur;
	}

	else if (akey > cur->key) //if key is greater than current key, go right
	{
		cur->right = remove(cur->right, akey);
		bf = balanceFactor(cur);  //if unbalanced, restore balance
		if (bf < -1 || bf > 1)
			cur = restoreBalance(cur);
		updateHeight(cur);
		return cur;
	}

	else //found node to remove
	{
		if (!cur->left && !cur->right) //node has no children, delete and return NULL
		{
			delete cur;
			return NULL;
		}

		else if (!cur->left || !cur->right) //node has 1 child, delete node and return child in its place
		{
			Tnode* temp = cur->left;
			if (!cur->left)
				temp = cur->right;
			delete cur;
			return temp;
		}

		else //node has 2 children, Find leftmost node(smallest) of subtree rooted at RIGHT child, replace current node with leftmost's values. Then remove leftmost node
		{
			Tnode* LM = get_leftmost(cur->right);
			cur->key = LM->key;
			cur->value = LM->value;
			cur->right = remove(cur->right, LM->key);
			bf = balanceFactor(cur);  //if unbalanced, restore balance
			if (bf < -1 || bf > 1)
				cur = restoreBalance(cur);
			updateHeight(cur);
			return cur;
		}
	}//else
}//remove

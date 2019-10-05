//main.cpp
//jrlevin
#include<iostream>
#include "bst.h"
using namespace std;

int main()
{
	BST tree; //create tree
	string command;

	int len;
	cout<< "Please specify length of key: ";
	cin>>len;

	cout<< "Enter command: " <<endl;
	while(cin>>command) //while commands are given, try to run command
	{
		if (command == "print_inorder") //prints values inorder
		{
			cout<< "Values in tree include: ";
			tree.print_inorder();
			cout<< endl << "Enter command:" <<endl;
		}

		else if (command == "heightPrint")  //prints heights of nodes inorder
		{
			cout<< "Heights inorder: ";
			tree.heightPrint();
			cout<< endl << "Enter command:" <<endl;
		}

		else if (command == "printBF")  //prints balance factors of nodes inorder
		{
			cout<< "Balance factors inorder: ";
			tree.printBF();
			cout<< endl << "Enter command:" <<endl;
		}

		else if (command == "findPrint")  //prints contents of node with user specified key(string)
		{
			cout<< "Enter key of length "<< len <<endl;
			string akey;
			cin>>akey;
			if ((int)akey.length() == len)
			{
				cout<< "Node contains: ";
				tree.findPrint(akey);
			}
			else
				cerr<< "Error: key must be " << len << " characters long." <<endl;
			cout<< "Enter command: " <<endl;
		}

		else if (command == "insert") //inserts user specified value(string) into tree with user specified prefix length(int)
		{
			string word;
			cout<< "Please enter string you would like to insert: " <<endl;
			cin>>word;
			tree.insert(word.substr(0, len), word);
			cout<< "Enter command: " <<endl;
		}

		else if (command == "remove") //removes node with user specified key(string)
		{
			string akey;
			cout<< "Please enter key of length "<< len << " that you would like to remove: " <<endl;
			cin>>akey;
			if ((int)akey.length() == len)
				tree.remove(akey);
			else
				cerr<< "Error: key must be " << len << " characters long." <<endl;
			cout<< "Enter command: " <<endl;
		}

		else if(command == "quit")
			return 0;

		else  //command does not exist
			cerr<< "Error: command " << command << " is not found." <<endl;
	}
}

//main.cpp
//jrlevin
#include<iostream>
#include "bst.h"
using namespace std;

int main()
{
  BST tree; //create tree
  string command;

  while(cin>>command) //while commands are given, try to run command
  {
    if (command == "print_inorder") //prints values inorder
    {
      tree.print_inorder();
      cout<<endl;
    }

    else if (command == "heightPrint")  //prints heights of nodes inorder
    {
      tree.heightPrint();
      cout<<endl;
    }

    else if (command == "printBF")  //prints balance factors of nodes inorder
    {
      tree.printBF();
      cout<<endl;
    }

    else if (command == "findPrint")  //prints contents of node with user specified key(string)
    {
      string akey;
      cin>>akey;
      tree.findPrint(akey);
    }

    else if (command == "insert") //inserts user specified value(string) into tree with user specified prefix length(int)
    {
      string word;
      int len;
      cin>>word>>len;
      tree.insert(word.substr(0, len), word);
    }

    else if (command == "remove") //removes node with user specified key(string)
    {
      string akey;
      cin>>akey;
      tree.remove(akey);
    }

    else  //command does not exist
      cerr<< "Error: command " << command << " is not found." <<endl;
  }
}

//tnode.h
//jrlevin
#include<vector>
#include<string>
using namespace std;

#ifndef TNODE_H
#define TNODE_H


class Tnode{
  public:
    Tnode(): key(""), left(NULL), right(NULL) {}; //initialize empty node
    Tnode(string akey, string aval) //initialize node with given key and value
    {
      key = akey;
      value.push_back(aval);
      height = 0;
      left = NULL;
      right = NULL;
    };
    string key; //string by which nodes are organized
    vector<string> value; //vector where strings with same prefix(key) are stored
    int height; //height of node
    Tnode* left;
    Tnode* right;
};

#endif

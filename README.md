# AVL_Tree
Balanced binary search tree(AVL tree)

To compile using Makefile: $make
  Results in an executable named "main"
To delete executable and object files use: $make clean
  
Included tests can be untarred by using: $tar -xvf avl_tests.tar

To see example output using tests: $ ./main <./tests/t'##'

Valid commands include:

"print_inorder" //prints values in tree inorder
"heightPrint" //prints heights of nodes inorder
"printBF" //prints balance factors of nodes inorder
"findPrint" //prints contents of node at specified key
"insert" //inserts word into string using prefix of word with length 'prefixlength' as key
"remove" //removes node with user specified key
"quit" //exits application

All other attempted commands will result in error message

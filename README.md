# AVL_Tree
Balanced binary search tree of strings
  Makes comparisons to each character in the string until it finds which string is "greater"(later in the alphabet) and sorts lower valued strings(abc) to the left and higher valued strings(xyz) to the right

To compile using Makefile: $make    //Results in an executable named "main"

To delete executable and object files use: $make clean
  
Valid commands include:

"print_inorder" //prints values in tree inorder

"heightPrint" //prints heights of nodes inorder

"printBF" //prints balance factors of nodes inorder

"findPrint" //prints contents of node at specified key

"insert" //inserts word into string using prefix of word with length 'prefixlength' as key

"remove" //removes node with user specified key

"quit" //exits application

All other attempted commands will result in error message

*testing*

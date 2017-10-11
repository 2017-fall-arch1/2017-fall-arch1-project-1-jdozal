#ifndef bst_included
#define bst_included

/* an Employee item */
typedef struct Employee {
  struct Employee *right, *left;
  char *name;
  int isLeaf;
} Employee;

typedef struct {
  Employee *root;
} BST;

extern int bstDoCheck;

/* create a new BST */ 
BST *BSTAlloc();

/* locate employee in BST */
void bstPut(BST *bst, char *n);

/* print tree ascending order*/
void printAsc(Employee *e);

#endif

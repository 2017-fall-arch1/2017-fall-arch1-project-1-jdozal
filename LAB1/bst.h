#ifndef bst_included
#define bst_included

/* an Employee item */
typedef struct Employee {
  struct Employee *right, *left;
  char *name;
} Employee;

typedef struct {
  Employee *root;
} BST;

extern int bstDoCheck;

/* create a new BST */ 
BST *BSTAlloc();

/* add employee to BST */
void bstPut(BST *bst, char *n);

/* print tree ascending order*/
void printAsc(Employee *e);

/* search for employee */
struct Employee *search(Employee *e, char *n);

/* removes employee */
void removeEmployee(Employee *e, Employee *parent);

/* Check if employee is a leaf in the bst */
int isLeaf(Employee *e);

/* replace parent node with newChild, used for remove fuction */
void replaceInParent(Employee *parent, Employee *child, Employee *newChild);

/* get last element on left child of given employee */
struct Employee *getLargestLeft(Employee *e);
  
/* search for parent */
struct Employee *getParent(Employee *curr, Employee *prev, char *n);

/* reads file to create bst */
BST *readFile(FILE *fp);

/* writes employees in file */
void printToFile(FILE *fp, Employee *e);
#endif

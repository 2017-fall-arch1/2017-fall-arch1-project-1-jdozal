#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "bst.h"		

int bstDoCheck = 1;

#define doCheck(_bst) (bstDoCheck)

/* create a new bst */
BST *BSTAlloc() {
  BST *bst = (BST *)malloc(sizeof(BST));
  bst->root = 0;
  doCheck(bst);
  return bst;
}

/* append a copy of name to end of list */
void bstPut(BST *bst, char *n) {
  int len;
  char *ncopy;
  Employee *e;

  doCheck(bst);
  /* w = freshly allocated copy of putWord */
  for (len = 0; n[len]; len++) /* compute length */
    ;
  ncopy = (char *)malloc(len+1);
  for (len = 0; n[len]; len++) /* copy chars */
    ncopy[len] = n[len];
  ncopy[len] = 0;			/* terminate copy */

  /* e = new Employee with copy of name */
  e = (Employee *)malloc(sizeof(Employee));
  e->name = ncopy;
  e->isLeaf = 1;

}

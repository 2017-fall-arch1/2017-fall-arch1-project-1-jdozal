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


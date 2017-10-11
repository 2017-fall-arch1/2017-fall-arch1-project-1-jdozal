#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include <string.h>             /* for strcmp */
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
  e->right = 0;
  e->left = 0;

  /* locate employee in bst */
  if(bst->root){
    printf("Employee: <%s>\n", ncopy);
    Employee *curr = bst->root;
    while(curr) {
      if(strcmp(curr->name, ncopy)<0){
	printf("enter if\n");
	if(curr->right == 0){
	  curr->isLeaf = 0;
	  curr->right = e;
	  return;
	}
	curr = curr->right;
      }else{
	printf("enter else\n");
	if(curr->left == 0){
	  curr->isLeaf = 0;
	  curr->left = e;
	  return;
	}
	curr = curr->left;
      }
    }
  }else{
    bst->root = e;
  }
}
void printAsc(Employee *e) {
  if(!e){
    return;
  }
  printAsc(e->left);
  printf("Employee: <%s>\n", e->name);
  printAsc(e->right);
}

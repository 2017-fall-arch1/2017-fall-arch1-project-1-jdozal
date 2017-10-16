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

/* Check if employee is a leaf in the bst */
int isLeaf(Employee *e){
  if(!e->right && !e->left)
    return 1;
  return 0;
}

/* return parent node */
struct Employee *getParent(Employee *curr, Employee *prev, char *n) {
  if(!curr){
    printf("%s is not on the list\n", n);
    return curr;
  }
  /* compare name of current employee with input name*/
  int cmp = strcmp(curr->name, n);

  /* if value of cmp is 0, strings are equal */ 
  if(cmp == 0)
    return prev;

  /* if value of cmp is less than 0, input string is after curr employee */
  if(cmp < 0){
    return getParent(curr->right, curr, n);
  }

  /* if value of cmp is less than 0, input string is before curr employee */ 
  if(cmp > 0){
    return getParent(curr->left, curr, n);
  }
  return curr;

}

/* append a copy of name to bst */
void bstPut(BST *bst, char *n) {
  int len;
  char *ncopy;
  Employee *e;

  doCheck(bst);
  /* ncopy = freshly allocated copy of n */
  for (len = 0; n[len]; len++) /* compute length */
    ;
  ncopy = (char *)malloc(len+1);
  for (len = 0; n[len]; len++) /* copy chars */
    ncopy[len] = n[len];
  ncopy[len] = 0;	       /* terminate copy */

  /* e = new Employee with copy of name */
  e = (Employee *)malloc(sizeof(Employee));
  e->name = ncopy;
  e->right = 0;
  e->left = 0;

  /* locate employee in bst */
  if(bst->root){
    Employee *curr = bst->root;
    /* looking for leaf*/
    while(curr) {
      if(strcmp(curr->name, ncopy)<0){ /* if new employee goes after curr */
	if(curr->right == 0){
	  curr->right = e;
	  return;
	}
	curr = curr->right;
      }else{
	if(curr->left == 0){ /* else new employee goes before curr */
	  curr->left = e;
	  return;
	}
	curr = curr->left;
      }
    }
  }else{
    /* if tree is empty */ 
    bst->root = e;
  }
}


/* Print employees in ascending order */
void printAsc(Employee *e) {
  if(!e){
    return;
  }
  printAsc(e->left);
  printf("%s\n", e->name); /* go left, print, go right */
  printAsc(e->right);
}

/* Print preorder to file to preserve "balance", and deletes employees that were removed */
void printToFile(FILE *fp, Employee *e) {
  if(!e)
    return;
   fprintf(fp,"%s\n", e->name); /* print, go left, go right */
  printToFile(fp, e->left);
  printToFile(fp, e->right);
}

/* search and return employee with name n */
struct Employee *search(Employee *e, char *n) {
  if(!e){
    printf("%s is not on the list\n", n);
    return e;
  }

  /* get value of string comparision between current node and string n */
  int cmp = strcmp(e->name, n);

  /* if cmp is 0, strings are the same, return curr employee */
  if(cmp == 0)
    return e;

  /* if cmp is less than 0, traverse to right child */
  if(cmp < 0)
    return search(e->right, n);

  /* if cmp is more than 0, traverse to left child */
  if(cmp > 0)
    return search(e->left, n);
  
  return e;
}

/* Read file and rebuild bst */
BST *readFile(FILE *fp){
  BST *bst = BSTAlloc();
  char line[255];
  char name[255];
 
  while(fgets(line, 255, fp) != NULL)
    {
      /* get a line, up to 255 chars from fp  done if NULL */
      sscanf  ( line, "%[^\t\n]s",name);
      /* add curr name to bst */
      bstPut(bst, name);
    }

  /* print in ascending order, for debugging purposes */
  /*printAsc(bst->root);*/
  return bst; 
}

/* replace parent node with newChild, used for remove fuction */ 
void replaceInParent(Employee *parent, Employee *child, Employee *newChild){
  /* replace right child */
  if(parent->right == child)
    parent->right = newChild;

  /* replace left child */
  else if(parent->left == child)
    parent->left = newChild;
  
}

/* get last element on left child of given employee */
struct Employee *getLargestLeft(Employee *e) {
  Employee *parent = e; /* set parent as e */
  Employee *largest = e->left; /* start at left child */ 

  /* if left employee is leaf replace node with left child */
  if(isLeaf(largest)) {
    parent->left = 0;
    return largest;
  }
  /* traverse left node to find last employee */
  while(!isLeaf(largest)){
    parent = largest;
    largest=largest->right;
  }
  /* delete pointer to largest element from immediate parent */ 
  parent->right = 0;
  return largest;
}

/* remove employee with employee to be removed, and parent as inputs */ 
void removeEmployee(Employee *e, Employee *parent){
  /* print employee to be removed, for debugging purposes */
  /* printf("<%s>\n", e->name);
     printf("p: <%s>\n", parent ->name); */

  /* if current employee has both children, replace with last element in left child */
  if(e->left && e->right){
    Employee *newChild = getLargestLeft(e);
    e->name = newChild->name;
  }
  
  /* if only left child is present, replace node with left child */
  else if(e->left){
    replaceInParent(parent, e, e->left);
  }

  /* if only left child is present, replace node with right child */
  else if(e->right){
    replaceInParent(parent, e, e->right);
  }

  /* if employee is leaf delete pointer from parent to employee */
  else{
    if(parent->right == e){
      parent->right = 0;
    }else{
      parent->left = 0;
    }
  }
}

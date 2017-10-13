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

/* Check if employee is leaf */
int isLeaf(Employee *e){
  if(!e->right && !e->left)
    return 1;
  return 0;
}

/* append a copy of name to bst */
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
  e->right = 0;
  e->left = 0;

  /* locate employee in bst */
  if(bst->root){
    Employee *curr = bst->root;
    /* looking for leaf*/
    while(curr) {
      if(strcmp(curr->name, ncopy)<0){
	if(curr->right == 0){
	  curr->right = e;
	  return;
	}
	curr = curr->right;
      }else{
	if(curr->left == 0){
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

struct Employee *search(Employee *e, char *n) {
  if(!e){
    printf("%s is not on the list\n", n);
    return e;
  }
  int cmp = strcmp(e->name, n);

  if(cmp == 0)
    return e;
  if(cmp < 0){
    return search(e->right, n);
  }
  if(cmp > 0){
    return search(e->left, n);
  }
  return e;
}

/* Read file and rebuild bst */
BST *readFile(FILE *fp){
  BST *bst = BSTAlloc();
  char line[100];
  char name[100];
  printf("TEST READ\n");
  /* fprintf(fp, "This is testing for fprintf...\n");
     fputs("This is testing for fputs...\n", fp);*/
  int i = 1;
  while(fgets(line, 255, fp) != NULL)
    {
      /* get a line, up to 255 chars from fp  done if NULL */
      sscanf  ( line, "%s",name);
      bstPut(bst, name);
      i++;
    }

  printAsc(bst->root);
  return bst;
  /*fscanf(fp, "%s", buff);
  printf("1 : %s\n", buff );

  fgets(buff, 255, (FILE*)fp);
  printf("2: %s\n", buff );

  fgets(buff, 255, (FILE*)fp);
  printf("3: %s\n", buff ); */
  
}
void removeEmployee(Employee *e){

  printf("<%s>\n", e->name);
  printf("right = %s", e->right->name);
  if(e->left && e->right){
    printf("both children present");
  } else if(e->left){
    printf("only left present");
  } else if(e->right){
    printf("only right  present");
  } else{
    printf("is leaf");
    
  }
}

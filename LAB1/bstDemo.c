#include <stdio.h>		/* for printf */
#include <stdlib.h>		/* for free() */
#include <string.h> 		/* for strlen */
#include "bst.h"		/* for list operations */

  
/* read no more than limit chars into s, return #chars read.  Doesn't include trailing \n */
int gets_n(char *s, int limit) {
  char *p = s;
  char c;

  if(fgets(s, limit, stdin)) {
    while((c = *p) && c != '\n')
      p++;
    if(c == '\n')
      *p = 0;
  }
  return(p-s);
  
}
int main(){
  char buf[100];

  /* Make empty BST */
  BST *bst = BSTAlloc();

  while(gets_n(buf, 100))
    bstPut(bst, buf);

  printf("Start printing list ascending order: \n");
  Employee *r = bst->root;
  printAsc(r);
  
  return 0;
}

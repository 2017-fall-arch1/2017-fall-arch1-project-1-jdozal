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

void add(BST *bst){
  char name[100];

  printf("Enter new employee: ");
  scanf("%s", name);
  bstPut(bst, name);
  printAsc(bst);
}
int main(){
  char buf[100];

  /* Make empty BST */
  BST *bst = BSTAlloc();

  printf("Welcome to the Personnel Management System\n\n Enter a number to perform an action:\n  1: Add a new employee\n  2: Remove an employee\n  3: List  all employees\n\n");

  printf("Option: ");
  int option = getchar();

  printf("\n");

  switch (option) {
  case '0':
    printf("Bye");
    return 0;
  case '1':
    printf("add");
    add(bst);
    break;
  case '2':
    printf("remove");
    break;
  case '3':
    printAsc(bst->root);
    break;
  default:
    printf("Not a valid option");
  }
  /* if(option =='0'){
    printf("Tenkiubai\n");
    return 0;
  }
  if(option == '1'){
    printf("Add\n");
  }if(option == '2'){
    printf("Remove\n");
  }if(option == '3'){
    printf("List\n");
  }else{
    printf("Not a valid option");
  }
  */
  
  /*while(gets_n(buf, 100))
    bstPut(bst, buf);

  printf("Start printing list ascending order: \n");
  Employee *r = bst->root;
  printAsc(r);
  */
  return 0;
}

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

/* helper function to remove, scans employee to remove, calls seach and remove  */
void rmv(BST *bst) {
  char name[100];

  printf("Enter employee to remove: ");
  scanf("%s", name);
  Employee *e = search(bst->root, name);
  /* if employee is indeed in the bst call removeEmployee */
  if(e)
    removeEmployee(e);
  
}

/* helper function to add, scans name to add and calls bstPut  */
void add(BST *bst){
  char name[100];

  printf("Enter new employee: ");
  scanf("%s", name);
  bstPut(bst, name);
  printAsc(bst->root);
}
int main(){
  char buf[100];

  /* Make empty BST */
  BST *bst = BSTAlloc();

  printf("Welcome to the Personnel Management System\n\n Enter a number to perform an action:\n  1: Add a new employee\n  2: Remove an employee\n  3: List  all employees 0: Exit\n\n");

   for(;;){
     printf("\nOption: ");
     int option = getchar();
    switch (option) {
    case '0':
      printf("\nBye");
      return 0;
    case '1':
      add(bst);
      break;
    case '2':
      rmv(bst);
      break;
    case '3':
      printAsc(bst->root);
      break;
    default:
      printf("\nNot a valid option");
  }
    getchar(); /* getting rid of new lines */
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

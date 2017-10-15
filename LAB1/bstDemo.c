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
  Employee *parent = getParent(bst->root, bst->root, name);
  Employee *e = search(bst->root, name);
  /* if employee is indeed in the bst call removeEmployee */
  if(e)
    removeEmployee(e, parent);
  
}

/* helper function to add, scans name to add and calls bstPut  */
void add(BST *bst, const char * filename){
  FILE *fw = fopen(filename, "a");
  char name[100];
  printf("Enter new employee: ");
  scanf("%s", name);
  bstPut(bst, name);
  fprintf(fw, "%s\n", name);
  printAsc(bst->root);
}

void interface(){
 BST *bst;
 const char *filename="test.txt";
  FILE *fp;
  fp = fopen(filename, "r+");
  if(fp){
    bst = readFile(fp);
  } else {
    printf("Not such file\n");
  }
  fclose(fp);
  
 printf("Welcome to the Personnel Management System\n\n Enter a number to perform an action:\n  1: Add a new employee\n  2: Remove an employee\n  3: List  all employees\n  0: Exit\n\n");

   for(;;){
     printf("\nOption: ");
     int option = getchar();
    switch (option) {
    case '0':
      printf("");
      return;
    case '1':
      add(bst,filename);
      break;
    case '2':
      rmv(bst);
      break;
    case '3':
      printf("Listing all employees in alphabetical order: \n");
      printAsc(bst->root);
      break;
    default:
      printf("\nNot a valid option");
  }
    getchar(); /* getting rid of new lines */
   }
}

int main(){
  interface();
  /*  printf("Start printing list ascending order: \n");
  Employee *r = bst->root;
  printAsc(r);
  */
  return 0;
}

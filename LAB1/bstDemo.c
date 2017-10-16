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
  char name[255];

  printf("Enter employee to remove: ");
  getchar(); /* getting rid of new line */
  scanf("%[^\t\n]", name); /* reads input from terminal */

  /* search for employee node  */
  Employee *e = search(bst->root, name);
  /* if employee is indeed in the bst call removeEmployee */
  if(e) {
    Employee *parent = getParent(bst->root, bst->root, name);
    removeEmployee(e, parent);
    printf("New list after removal: \n");
    printAsc(bst->root);
  }
  
}

/* helper function to add, scans name to add and calls bstPut  */
void add(BST *bst, const char * filename){
  /* open file to append new employee */
  FILE *fw = fopen(filename, "a");
  char name[255];
  printf("Enter new employee: ");
  getchar(); /* getting rid of new line */
  scanf("%[^\t\n]", name); /* scan name from terminal */
  bstPut(bst, name); /* add employee to bst */ 
  fputs(name, fw); /* add employee to text file */ 
  printf("New list after addition: \n");
  printAsc(bst->root); 
}

/* simple user interface so that a user may: Add a new employee name, remove an employee name, list all employee names, */
void interface(){
  BST *bst; /* binary search tree */
 const char *filename="names.txt"; 
  FILE *fp;

  /* opens a file for reading. The file must exist. */ 
  fp = fopen(filename, "r");
  if(fp){
    bst = readFile(fp);
  } else {
    /* if file does not exist create file */
    printf("File <%s> does not exist, creating file... \n", filename);
    fp = fopen(filename, "w+");
    fprintf(fp, "");
  }
  fclose(fp);
  
 printf("Welcome to the Personnel Management System\n\n Enter a number to perform an action:\n  1: Add a new employee\n  2: Remove an employee\n  3: List  all employees\n  0: Exit\n\n");

   for(;;){
     printf("\nOption: ");
     int option = getchar();
    switch (option) {
    case '0':
      /* Rewriting tree into file to make it more "balanced" */
      fp = fopen(filename, "w+");
      printToFile(fp, bst->root);
      fclose(fp);
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
  return 0;
}

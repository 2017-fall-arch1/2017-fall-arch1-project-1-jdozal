#ifndef bst_included
#define bst_included

/* an Employee item */
typedef struct Employee {
  struct Employee *right, *left;
  char *name;
} Employee;

#endif

#include <stdio.h>
#include <stdlib.h>

enum { MAXNAMESIZE = 100 };
typedef struct
{
  unsigned long phone;
  char name[MAXNAMESIZE];
} Data;

typedef struct Node
{
  struct Node *left, *right;
  Data data;
} Node;

void insert(Node **nodeptr, Data data)
{
  Node *node = *nodeptr;
  if (!node)
  {
    (*nodeptr) = calloc(1, sizeof*node);
    (*nodeptr)->data = data;
  }
  else
    if (node->left && node->left->data.phone >= data.phone)
      insert(&node->left, data);
    else
      if (node->right && node->right->data.phone < data.phone)
        insert(&node->right, data);
      else
        if (node->data.phone > data.phone)
        {
          Node *tmp = node->left;
          node->left = calloc(1, sizeof*node);
          node->left->data = data;
          node->left->left = tmp;
        }
        else
          if (node->data.phone < data.phone)
          {
            Node *tmp = node->right;
            node->right = calloc(1, sizeof*node);
            node->right->data = data;
            node->right->right = tmp;
          }
          else
          {
#if 0
            printf("schon vorhanden %lu\n", data.phone);
#endif
          }

}

void print(const Node *node)
{
  if (node->left) print(node->left);
  printf("%lu\t%s\n", node->data.phone, node->data.name);
  if (node->right) print(node->right);
}

int main()
{
  Node * root = NULL;

  insert(&root, (Data) { 9, "Bowie" });
  insert(&root, (Data) { 8, "Prince" });
  insert(&root, (Data) { 6, "Michael" });
  insert(&root, (Data) { 7, "Cohen" });
  insert(&root, (Data) { 5, "Parfitt" });
  insert(&root, (Data) { 1, "Frey" });
  insert(&root, (Data) { 3, "Emerson" });
  insert(&root, (Data) { 2, "Lake" });
  insert(&root, (Data) { 4, "Cicero" });
  insert(&root, (Data) { 10, "White" });
  print(root);
  puts("");

  insert(&root, (Data) { 9, "aaa" });
  insert(&root, (Data) { 8, "b" });
  insert(&root, (Data) { 6, "CCC" });
  print(root);

  return 0;
}


#include <stdio.h>

#include "mem.h"

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

void insert(Node **nodeptr, Data data, Memmanager *mm)
{
	Node *node = *nodeptr;
	if (!node)
	{
		(*nodeptr) = memalloc(mm, sizeof*node);
		(*nodeptr)->data = data;
	}
	else
		if (node->left && node->left->data.phone >= data.phone)
			insert(&node->left, data, mm);
		else
			if (node->right && node->right->data.phone < data.phone)
				insert(&node->right, data, mm);
			else
				if (node->data.phone > data.phone)
				{
					Node *tmp = node->left;
					node->left = memalloc(mm, sizeof*node);
					node->left->data = data;
					node->left->left = tmp;
				}
				else
					if (node->data.phone < data.phone)
					{
						Node *tmp = node->right;
						node->right = memalloc(mm, sizeof*node);
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
	Memmanager mm = { 0 };

	insert(&root, (Data) { 9, "Bowie" }, &mm);
	insert(&root, (Data) { 8, "Prince" }, &mm);
	insert(&root, (Data) { 6, "Michael" }, &mm);
	insert(&root, (Data) { 7, "Cohen" }, &mm);
	insert(&root, (Data) { 5, "Parfitt" }, &mm);
	insert(&root, (Data) { 1, "Frey" }, &mm);
	insert(&root, (Data) { 3, "Emerson" }, &mm);
	insert(&root, (Data) { 2, "Lake" }, &mm);
	insert(&root, (Data) { 4, "Cicero" }, &mm);
	insert(&root, (Data) { 10, "White" }, &mm);
	print(root);
	puts("");

	insert(&root, (Data) { 9, "aaa" }, &mm);
	insert(&root, (Data) { 8, "b" }, &mm);
	insert(&root, (Data) { 6, "CCC" }, &mm);
	print(root);

	memfreeall(&mm);

	return 0;
}



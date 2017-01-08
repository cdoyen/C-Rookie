#include <stdlib.h>

enum { LISTSIZE = 4096, BLOCKSIZE = 65536 };

typedef struct {
	size_t blocksize, index, last;
	int i;
	char *list[LISTSIZE];
} Memmanager;

void *memalloc(Memmanager *mm, size_t size);
void *memresetlast(Memmanager *mm, size_t size);
void memfreeall(Memmanager *mm);

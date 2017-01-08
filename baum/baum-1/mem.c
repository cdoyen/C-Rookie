#include "mem.h"

void *memalloc(Memmanager *mm, size_t size)
{
	if (!mm->blocksize || mm->blocksize - mm->index < size)
	{
		if (mm->i == LISTSIZE - 1) return 0;
		mm->blocksize = mm->blocksize ? mm->blocksize < size ? size : mm->blocksize : BLOCKSIZE;
		mm->list[mm->i] = calloc(1, mm->blocksize);
		mm->index = size;
		mm->last = size;
		return &mm->list[mm->i++][0];
	}
	else
	{
		mm->last = size;
		return &mm->list[mm->i - 1][(mm->index += size) - size];
	}
}

void *memresetlast(Memmanager *mm, size_t size)
{
	if (mm->last)
	{
		mm->index -= mm->last;
		mm->last = 0;
		return &mm->list[mm->i - 1][mm->index];
	}
	return 0;
}

void memfreeall(Memmanager *mm)
{
	while (mm->i--) free(mm->list[mm->i]);
	mm->blocksize = mm->last = mm->index = mm->i = 0;
}
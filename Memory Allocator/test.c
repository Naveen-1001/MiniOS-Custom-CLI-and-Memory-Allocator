#include <stdio.h>
#include "mem_alloc.h"

void *head;
typedef unsigned long ul;

int main()
{
	Mem_Init(4096);
	printf("Starting Memory Location (Head) : %lu\n", (ul)head);
	int *a = (int *)Mem_Alloc(1000);
	int *b = (int *)Mem_Alloc(10);
	int *c = (int *)Mem_Alloc(100);

	printf("a : %lu\n", (ul)a);
	printf("b : %lu\n", (ul)b);
	printf("c : %lu\n", (ul)c);
	
	printf("\nMemory Allocated to a : %lu\n", (ul)b-(ul)a-9); 
	printf("Memory Allocated to b : %lu\n", (ul)c-(ul)b-9);
	
	printf("\nMem_IsValid returns 1 if memory is allocated for given memory location.\nOtherwise 0\n\n");

	printf("a : %d\n", Mem_IsValid((void *)((ul)a + 500)));
	printf("b : %d\n", Mem_IsValid((void *)((ul)b + 5)));
	printf("c : %d\n", Mem_IsValid((void *)((ul)c + 20)));

	Mem_Free((void *)((ul)a + 500));
	Mem_Free((void *)((ul)b + 5));
	Mem_Free((void *)((ul)c + 20));

	printf("All allocated memory released\n");

	printf("a : %d\n", Mem_IsValid((void *)((ul)a + 500)));
	printf("b : %d\n", Mem_IsValid((void *)((ul)b + 5)));
	printf("c : %d\n", Mem_IsValid((void *)((ul)c + 20)));

	return 0;
}
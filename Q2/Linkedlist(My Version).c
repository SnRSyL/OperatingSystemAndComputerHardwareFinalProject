#include <stdio.h>

#define SIZE 32   // total number of disk blocks

int nextBlock[SIZE];   // pointer to next block
int freeStart = 0;     // first free block

/*
 Initializes the free list.
 Each block points to the next free block.
*/
void initList() {
    int i;
    for (i = 0; i < SIZE - 1; i++) {
        nextBlock[i] = i + 1;
    }
    nextBlock[SIZE - 1] = -1;
}

/*
 Allocates a given number of blocks using linked list allocation.
 Returns the starting block index or -1 if allocation fails.
*/
int allocateList(int need) {
    int i;
    int current = freeStart;
    int last = -1;

    for (i = 0; i < need; i++) {
        if (current == -1) {
            return -1;   // not enough free blocks
        }
        last = current;
        current = nextBlock[current];
    }

    freeStart = current;
    nextBlock[last] = -1;

    return freeStart == -1 ? 0 : freeStart;
}

/*
 Frees a file by adding its blocks back to the free list.
*/
void freeList(int start) {
    int temp = start;

    while (nextBlock[temp] != -1) {
        temp = nextBlock[temp];
    }

    nextBlock[temp] = freeStart;
    freeStart = start;
}

/*
 Prints the linked list of free blocks.
*/
void showFreeList() {
    int i = freeStart;
    while (i != -1) {
        printf("%d -> ", i);
        i = nextBlock[i];
    }
    printf("end\n");
}


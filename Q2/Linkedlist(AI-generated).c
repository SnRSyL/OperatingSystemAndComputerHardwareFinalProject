#include <stdio.h>
#include <stdlib.h>

#define DISK_SIZE 32

int next[DISK_SIZE];
int freeHead = 0;

void initDisk() {
    for (int i = 0; i < DISK_SIZE - 1; i++) {
        next[i] = i + 1;
    }
    next[DISK_SIZE - 1] = -1;
}

int allocate_linked(int size) {
    int start = freeHead;
    int prev = -1;
    int current = freeHead;

    for (int i = 0; i < size; i++) {
        if (current == -1) {
            return -1;
        }
        prev = current;
        current = next[current];
    }

    freeHead = current;
    next[prev] = -1;

    return start;
}

void free_linked(int start) {
    int temp = start;
    while (next[temp] != -1) {
        temp = next[temp];
    }
    next[temp] = freeHead;
    freeHead = start;
}

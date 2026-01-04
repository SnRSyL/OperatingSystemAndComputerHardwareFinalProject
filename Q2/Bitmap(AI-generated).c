#include <stdio.h>

#define DISK_SIZE 32

int bitmap[DISK_SIZE];

int allocate_bitmap(int size) {
    int count = 0;

    for (int i = 0; i < DISK_SIZE; i++) {
        if (bitmap[i] == 0) {
            count++;
            if (count == size) {
                for (int j = i; j > i - size; j--) {
                    bitmap[j] = 1;
                }
                return i - size + 1;
            }
        } else {
            count = 0;
        }
    }
    return -1;
}

void free_bitmap(int start, int size) {
    for (int i = start; i < start + size; i++) {
        bitmap[i] = 0;
    }
}


#include <stdio.h>

#define DISK_SIZE 32   // Total number of disk blocks on disk

int diskMap[DISK_SIZE];  // Bitmap: 0 = free, 1 = allocated

/*
 Tries to allocate 'requestSize' consecutive blocks.
 Returns the starting block index if successful, otherwise -1.
*/
int bitmapAllocate(int requestSize) {
    int freeCount = 0;

    for (int i = 0; i < DISK_SIZE; i++) {
        if (diskMap[i] == 0) {
            freeCount++;

            // Enough consecutive free blocks found
            if (freeCount == requestSize) {
                int startIndex = i - requestSize + 1;

                // Mark selected blocks as allocated
                for (int j = startIndex; j <= i; j++) {
                    diskMap[j] = 1;
                }
                return startIndex;
            }
        } else {
            // Reset counter when an allocated block is found
            freeCount = 0;
        }
    }

    // Allocation failed
    return -1;
}

/*
 Frees previously allocated blocks by setting them back to 0.
*/
void bitmapFree(int startIndex, int size) {
    for (int i = startIndex; i < startIndex + size; i++) {
        diskMap[i] = 0;
    }
}

/*
 Prints the current state of the bitmap.
*/
void printDiskMap() {
    for (int i = 0; i < DISK_SIZE; i++) {
        printf("%d ", diskMap[i]);
    }
    printf("\n");
}

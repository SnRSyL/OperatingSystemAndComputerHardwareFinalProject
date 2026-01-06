Memory Allocation Algorithms Project
Overview

In this project, I implemented and tested different memory allocation techniques used in operating systems.
The main goal of this project is to understand how different allocation algorithms behave in terms of fragmentation, allocation pattern, and performance.

The project includes implementations and experiments for:

Bitmap allocation

Linked list based allocation

Best Fit, Worst Fit, and Next Fit algorithms

Implemented Allocation Methods
Bitmap Allocation

In bitmap allocation, memory blocks are represented using a bitmap structure.
Each bit shows whether a memory block is free or allocated.
This method is simple and space-efficient but scanning the bitmap can take time for large memories.

Linked List Allocation

In linked list allocation, free memory blocks are stored as nodes in a linked list.
Each node keeps the starting address and size of a free block.
This structure makes it easier to split and merge blocks during allocation and deallocation.

Allocation Algorithms

The following allocation algorithms are implemented using the linked list free list:

Best Fit:
Searches the entire free list and allocates the smallest block that can satisfy the request.

Worst Fit:
Searches the free list and allocates the largest available block.

Next Fit:
Similar to First Fit, but continues searching from the last allocated position instead of starting from the beginning.

Experiments and Tests
1. Allocation Trace Test

In this test, I performed step-by-step allocations and printed the free list after each operation.
This helps visualize how memory blocks are split and how the free list changes over time.

2. Fragmentation Test

In the fragmentation test:

I performed multiple random allocations.

Then I freed some blocks to create fragmentation.

Finally, I attempted a large allocation (size 25).

This test shows how external fragmentation can prevent large allocations even when total free memory is sufficient.

3. Speed Test

In the speed test, I measured the execution time of Best Fit, Worst Fit, and Next Fit algorithms.
Each algorithm was tested using the same allocation workload, and execution time was recorded to compare performance.

Project Structure
src/
  allocation_trace.c
  fragmentation_test.c
  speed_test.c
  bitmap_allocation.c
  linked_list_allocation.c

results/
  allocation_trace_output.txt
  fragmentation_output.txt
  speed_test_output.txt

README.md

How to Compile and Run

All programs are written in C and can be compiled using gcc.

Example:

gcc allocation_trace.c -o allocation_trace
./allocation_trace


The same steps can be followed for other test files.

Notes on Reproducibility

I organized the files using clear names and a simple folder structure to make the project easy to understand.
Each test is separated into its own source file, and experiment outputs are saved in result files.
This allows the experiments to be reproduced and verified easily.

Conclusion

Through this project, I observed how different memory allocation algorithms behave under fragmentation and performance tests.
Each algorithm has its own advantages and disadvantages depending on speed and memory usage patterns.

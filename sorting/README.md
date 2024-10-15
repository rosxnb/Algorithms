# SORTING

Covered sorting algorithms list:
- [Insertion Sort](#insertion-sort)
- [Bubble Sort](#bubble-sort)
- [Merge Sort](#merge-sort)

# RUNNING THE PROGRAMS

Each algorithm is contained in a single file. 
There are utilities used by programs like to fill the container with random numbers and check if container is sorted.
So include `misc/utilities.cpp` file along with algorithmic program file during compilation.
Also try using latest C++ version with flag `-std=c++20`.

An example to compile merge sort program: `clang++ -std=c++20 misc/uilities.cpp merge_sort.cpp`

```bash
# go into root directory for sorting algorithms
cd sorting

# to build executable for insertion sort only
make insertion_sort

# to build all executables at once
make

# finally, clean object files and binary files
make clean
```


## Insertion Sort

[prog](./insertion_sort.cpp)

- Concept: Left hand keeps a sorted deck of cards, and when a new card arrives, it is compared and inserted into the correct position.
- Data is already sorted and new data point needs to inserted and sorted.
- **Best Case:** $O(n)$
- **Worst Case:** $O(n^2)$

## Bubble Sort

[prog](./bubble_sort.cpp)

- Concept: Repeatedly swaps adjacent elements if they are in the wrong order. It "bubbles" the largest unsorted element to the correct position in each pass.
- **Best Case:** $O(n)$
- **Worst Case:** $O(n^2)$

## Merge Sort

[prog](./merge_sort.cpp)

- Concept: Splits the data into smaller sub-arrays, sorts them, and then merges them back together in sorted order.
- Merge step take sorted containers as input.
- **Best Case:** $O(n)$
- **Worst Case:** $O(n \log n)$

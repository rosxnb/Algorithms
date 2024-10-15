#include <cstddef>
#include <iostream>
#include "misc/utilities.hpp"


template <typename T>
void insertion_sort(T* keys, size_t const left, size_t const right, bool const asc = true)
{
    auto compare = asc
        ? [](const T& a, const T& b) -> bool { return a < b; }
        : [](const T& a, const T& b) -> bool { return a > b; };

    // assume that first element is already sorted
    for (size_t i = left; i <= right; ++i)
    {
        T ckey = keys[i];
        size_t j = i;

        // if current key is smaller than previous items (for ascending case)
        // find corrent position for current key
        // by moving all greater items to right by one position
        while (j > 0 and compare(ckey, keys[j - 1]))
        {
            keys[j] = keys[j - 1];
            j--;
        }

        // place current key in correct index to maintain sorted array
        keys[j] = ckey;
    }
}
// Best Case: O(n)
// Worst Case: O(n^2)


int main(void)
{
    int N;
    std::cout << "N = "; std::cin >> N;

    int* arr = new int[N];

    fill_array(arr, N);
    std::cout << "Before bubble sort: (arr)  "; print_array(arr, N);

    insertion_sort(arr, 0, N - 1);

    std::cout << "After bubble sort:  (arr)  "; print_array(arr, N);
    std::cout << std::boolalpha << is_sorted(arr, N, true) << std::endl;

    delete[] arr;

    return 0;
}

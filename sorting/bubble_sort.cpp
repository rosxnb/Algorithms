#include <cstddef>
#include <iostream>
#include "misc/utilities.hpp"


template <typename T>
void bubble_sort(T* keys, size_t const left, size_t const right, bool const asc = true)
{
    auto compare = asc
        ? [](T const a, T const b) { return a < b; }
        : [](T const a, T const b) { return a > b; };

    bool is_swapped = true;
    for (size_t i = left; i < right && is_swapped; ++i)
    {
        is_swapped = false;
        for (size_t j = right; j > i; --j)
        {
            // compare till the left position
            // swap positions if comparision is true
            // moving the smallest key to leftmost (for ascending)
            if (compare(keys[j], keys[j - 1]))
            {
                T temp      = keys[j];
                keys[j]     = keys[j - 1];
                keys[j - 1] = temp;
                is_swapped  = true;
            }
        }
    }
}
// Time Complexity: O(n^2)


int main(void)
{
    int N;
    std::cout << "N = "; std::cin >> N;

    int* arr = new int[N];

    fill_array(arr, N);
    std::cout << "Before bubble sort: (arr)  "; print_array(arr, N);

    bubble_sort(arr, 0, N - 1);

    std::cout << "After bubble sort:  (arr)  "; print_array(arr, N);
    std::cout << std::boolalpha << is_sorted(arr, N, true) << std::endl;

    delete[] arr;

    return 0;
}

#include <iostream>
#include <cstddef>
#include "misc/utilities.hpp"


#define DIVCONQ_MERGE_IMPL_OPTIMIZED 1

#if DIVCONQ_MERGE_IMPL_OPTIMIZED

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

template <typename T>
void merge(T* arr, size_t const left, size_t const middle, size_t const right, T* storage)
{
    size_t l = left;
    for (int i = left, j = middle + 1; l <= right; ++l)
    {
        bool use_right = i > middle || (j <= right && (storage[j] < storage[i]));
        arr[l] = storage[ (use_right ? j : i)++ ];
    }
}
// Time complexity: O(N)


template <typename T>
void merge_sort(T* arr, size_t const left, size_t const right, T* storage)
{
    if (right - left < 17) {
        insertion_sort(arr, left, right);
        return ;
    }

    size_t middle = left + ( (right - left) >> 1 );

    merge_sort(storage, left, middle, arr);
    merge_sort(storage, middle + 1, right, arr);

    merge(arr, left, middle, right, storage);
}
// Time complexity: O(N log(N))


template <typename T>
void merge_sort(T* arr, size_t const left, size_t const right)
{
    T* storage = new T[ right - left + 1 ];

    for (size_t i = left, j = 0; i <= right; ++i, ++j) 
        storage[j] = arr[i];

    merge_sort(arr, left, right, storage);

    delete[] storage;
}
// Time complexity: O(N log(N))

#else // NAIVE MERGE SORT

template <typename T>
void merge(T* arr, size_t const left, size_t const middle, size_t const right)
{ // assumes A[p : q] and A[q+1 : r] is sorted
    T* buffer = new T[right - left + 1];

    size_t i = 0;
    size_t l = left;
    size_t r = middle + 1;
    while (l <= middle and r <= right)
    {
        if (arr[l] <= arr[r])
            buffer[i++] = arr[l++];
        else
            buffer[i++] = arr[r++];
    }

    while (l <= middle)
        buffer[i++] = arr[l++];

    while (r <= right)
        buffer[i++] = arr[r++];

    size_t k = left;
    for (size_t j = 0; j < i; ++j)
        arr[k++] = buffer[j];

    delete[] buffer;
}
// Time complexity: O(N)


template <typename T>
void merge_sort(T* arr, size_t const left, size_t const right)
{
    // base case
    if (left >= right)
        return ;

    // calculate midpoint, get divide conditions
    size_t middle = left + ( (right - left) >> 1 );

    // conquer
    merge_sort(arr, left, middle);
    merge_sort(arr, middle + 1, right);

    // combine
    merge(arr, left, middle, right);

    return ;
}
// Time complexity: O(N log(N))


#endif // DIVCONQ_MERGE_IMPL_OPTIMIZED


int main()
{
    int N;
    std::cout << "N = "; std::cin >> N;

    int* arr = new int[N];

    fill_array(arr, N, -1'000, 10'000);
    std::cout << "Before merge sort: (arr)  "; print_array(arr, N);

    merge_sort(arr, 0, N - 1);

    std::cout << "After merge sort:  (arr)  "; print_array(arr, N);
    std::cout << std::boolalpha << is_sorted(arr, N, true) << std::endl;

    delete[] arr;

    return 0;
}

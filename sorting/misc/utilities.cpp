#include <chrono>
#include <random>
#include <iostream>
#include "utilities.hpp"

template <typename T>
void fill_array(T* arr, const size_t N, const size_t lbound, const size_t hbound)
{
    using dtype = typename std::conditional<
        std::is_integral_v<T>,
        std::uniform_int_distribution<T>,
        std::uniform_real_distribution<T>
    >::type;

    std::mt19937     engine(std::chrono::system_clock::now().time_since_epoch().count());
    dtype            distribution(lbound, hbound);

    auto generator = std::bind(distribution, engine);
    std::generate(arr, arr + N, generator);
    return ;
}

template void fill_array<int>(int* arr, const size_t N, const size_t lbound, const size_t hbound);
template void fill_array<long>(long* arr, const size_t N, const size_t lbound, const size_t hbound);
template void fill_array<float>(float* arr, const size_t N, const size_t lbound, const size_t hbound);
template void fill_array<double>(double* arr, const size_t N, const size_t lbound, const size_t hbound);


template <typename T>
void print_array(T const * const arr, const size_t N)
{
    for (size_t i = 0; i < N; ++i)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\n";
}

template void print_array<int>(int const * const arr, const size_t N);
template void print_array<long>(long const * const arr, const size_t N);
template void print_array<float>(float const * const arr, const size_t N);
template void print_array<double>(double const * const arr, const size_t N);


template <typename T>
bool is_sorted(T const * const arr, const size_t N, bool asc)
{
    auto compare = asc
        ? [] (const T& a, const T& b) -> bool { return a <= b; }
        : [] (const T& a, const T& b) -> bool { return a >= b; };

    for (size_t i = 1; i < N; ++i)
    {
        if (!compare(arr[i - 1], arr[i]))
            return false;
    }

    return true;
}

template bool is_sorted<int>(int const * const arr, const size_t N, bool asc);
template bool is_sorted<long>(long const * const arr, const size_t N, bool asc);
template bool is_sorted<float>(float const * const arr, const size_t N, bool asc);
template bool is_sorted<double>(double const * const arr, const size_t N, bool asc);

#pragma once

#include <cstddef>

template <typename T>
void fill_array(T* arr, const size_t N, const size_t lbound = -10, const size_t hbound = 99);

template <typename T>
void print_array(T const * const arr, const size_t N);

template <typename T>
bool is_sorted(T const * const arr, const size_t N, bool asc = true);

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // For size_t

// Definition of the iter function template
// arrayAddress: Pointer to the first element of the array
// length: Number of elements in the array
// f: A function (or functor) to be applied to each element of the array
template <typename T, typename Func>
void iter(T *arrayAddress, size_t length, Func f) {
    if (arrayAddress == NULL) // Optional: handle null pointer case
        return;
    for (size_t i = 0; i < length; ++i) {
        f(arrayAddress[i]);
    }
}

/*
// Alternatively, if the function f needs to modify the elements
// and those modifications should be reflected in the original array,
// and T is not a pointer type itself, T could be taken by reference.
// However, the subject implies calling a function ON every element,
// not necessarily modifying it through the function call signature directly.
// The function 'f' itself can take a reference if needed.
template <typename T, typename Func>
void iter(T *arrayAddress, size_t length, Func f) {
    if (arrayAddress == NULL)
        return;
    for (size_t i = 0; i < length; ++i) {
        f(arrayAddress[i]); // If f takes T&, modifications will persist
    }
}
*/

#endif // ITER_HPP

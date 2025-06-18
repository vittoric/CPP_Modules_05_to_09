#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // Required for std::find
#include <stdexcept> // Required for std::out_of_range

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::out_of_range("Element not found in container");
    }
    return it;
}

#endif // EASYFIND_HPP

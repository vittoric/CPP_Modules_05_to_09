#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // Changed from <cstdint> for C++98 compatibility
#include "Data.hpp"

class Serializer {
    private:
        Serializer(); // Private constructor
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif

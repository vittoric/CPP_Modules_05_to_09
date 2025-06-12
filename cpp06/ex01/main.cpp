#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data myData;
    myData.intValue = 42;
    myData.floatValue = 3.14f;
    myData.stringValue = "Hello, Serialization!";

    uintptr_t serializedPtr = Serializer::serialize(&myData);
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    std::cout << "Original Data Address: " << &myData << std::endl;
    std::cout << "Serialized Pointer:    " << serializedPtr << std::endl;
    std::cout << "Deserialized Pointer:  " << deserializedPtr << std::endl;

    if (deserializedPtr == &myData) {
        std::cout << "\nSerialization and Deserialization successful!" << std::endl;
        std::cout << "Data content through deserialized pointer:" << std::endl;
        std::cout << "Int Value:    " << deserializedPtr->intValue << std::endl;
        std::cout << "Float Value:  " << deserializedPtr->floatValue << std::endl;
        std::cout << "String Value: " << deserializedPtr->stringValue << std::endl;
    } else {
        std::cout << "\nSerialization and Deserialization FAILED!" << std::endl;
        std::cout << "Original pointer and deserialized pointer do not match." << std::endl;
    }

    // Test with NULL
    std::cout << "\n--- Testing with NULL pointer ---" << std::endl;
    Data* nullData = NULL;
    uintptr_t serializedNull = Serializer::serialize(nullData);
    Data* deserializedNull = Serializer::deserialize(serializedNull);

    std::cout << "Original NULL Data Address: " << nullData << std::endl;
    std::cout << "Serialized NULL Pointer:    " << serializedNull << std::endl;
    std::cout << "Deserialized NULL Pointer:  " << deserializedNull << std::endl;

    if (deserializedNull == nullData) {
        std::cout << "Serialization and Deserialization of NULL successful!" << std::endl;
    } else {
        std::cout << "Serialization and Deserialization of NULL FAILED!" << std::endl;
    }


    return 0;
}

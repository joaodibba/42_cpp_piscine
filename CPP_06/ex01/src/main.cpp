
#include "../includes/Serializer.hpp"

int main() {
    Data originalData = {42, 3.14f};
    Data* ptr = &originalData;

    std::cout << "Original: " << ptr->number << ", " << ptr->value << std::endl;

    uintptr_t serialized = Serializer::serialize(ptr);

    std::cout << "Serialized: " << serialized << std::endl;
    
    Data* deserializedPtr = Serializer::deserialize(serialized);

    std::cout << "Deserialized: " << deserializedPtr->number << ", " << deserializedPtr->value << std::endl;

    return 0;
}
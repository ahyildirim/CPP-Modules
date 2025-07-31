#include "Serializer.hpp"

int main() 
{
	Data data;
	data.x = 42;
	data.y = 84;

	uintptr_t raw = Serializer::serialize(&data);
	Data* deserializedData = Serializer::deserialize(raw);

	std::cout << "-----------POINTERS-----------" << std::endl;
	std::cout << "Original Pointer: " << &data << std::endl;
	std::cout << "Serialized Pointer: " << raw << std::endl;
	std::cout << "Deserialized Pointer: " << deserializedData << std::endl;

	std::cout << std::endl;
	std::cout << "-----------DATA-----------" << std::endl;
	std::cout << "Original Data: x = " << data.x << ", y = " << data.y << std::endl;
	std::cout << "Deserialized Data: x = " << deserializedData->x << ", y = " << deserializedData->y << std::endl;

	if (deserializedData == &data) {
		std::cout << "Deserialized pointer points to the same address as the original." << std::endl;
	} else {
		std::cout << "Deserialized pointer does NOT point to the same address as the original." << std::endl;
	}

	return 0;
}
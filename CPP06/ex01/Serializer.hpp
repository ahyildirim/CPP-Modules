#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

struct Data {
	int x;
	int y;
};

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator=(const Serializer &copy);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
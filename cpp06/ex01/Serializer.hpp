#pragma once
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string name;
	size_t		age;
}	Data;

class Serializer
{
	public:
		// orthodox canonical form
		Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);
		~Serializer();

		// member function
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};


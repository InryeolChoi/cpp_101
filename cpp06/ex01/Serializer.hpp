#pragma once
#include <iostream>

typedef struct t_Data
{
	std::string name;
	size_t		age;
	Data		*next
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
		uintptr_t serializer(Data* ptr);
		Data* deserialize(uintptr_t raw);
};


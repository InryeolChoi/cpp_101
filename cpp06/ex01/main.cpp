#include "Serializer.hpp"

int main(void)
{
	Data ptr;
	ptr.name = "inchoi";
	ptr.age = 25;

	std::cout << "< 기본 구조체 >" << std::endl;
	std::cout << "address: " << &ptr << std::endl;
	std::cout << "name: " << ptr.name << std::endl;
	std::cout << "age: " << ptr.age << std::endl;
	std::cout << std::endl;

	Serializer a;
	Data *ptr2 = a.deserialize(a.serialize(&ptr));
	std::cout << "serialize() -> deserialize() 실행" << std::endl;
	std::cout << std::endl;

	std::cout << "< after >" << std::endl;
	std::cout << "address: " << ptr2 << std::endl;
	std::cout << "name: " << ptr2->name << std::endl;
	std::cout << "age: " << ptr2->age << std::endl;

	return 0;
}
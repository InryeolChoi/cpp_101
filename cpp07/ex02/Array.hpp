 #pragma once
#include <iostream>

template <typename T>

class Array
{
	private:
		T 				*array;
		unsigned int	size;

	public:
		// orthodox canonical form
		Array() : size(0) {
			array = new T[size];
		}

		Array(unsigned int n) : size(n) {
			array = new T[size];
		}

		Array(const Array &other) : size(other.getsize()) {
			array = NULL;
			*this = other;
		}

		Array &operator=(const Array &other) {
			if (array != NULL)
				delete[] array;
			if (other.getsize())
			{
				size = other.getsize();
				array = new T[size];
				for (unsigned int i = 0; i < getsize(); i++)
					array[i] = other.array[i];
			}
			return (*this);
		}

		~Array() {
			if (array != NULL)
				delete[] array;
		}

		// member function
		unsigned int getsize() const
		{
			return (size);
		}

		// operator overload : []
		T &operator[](unsigned int index) 
		{
			if (index >= size || array == NULL) {
				throw InvalidIndexException();
			}
			return (array[index]);
		}

		// Exception
		class InvalidIndexException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
const char *Array<T>::InvalidIndexException::what() const throw()
{
	return ("Error : Invalid index");
}
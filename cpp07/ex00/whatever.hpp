#pragma once
#include <iostream>

class whatever
{
	public:
		// orthodox canonical form
		whatever();
		whatever(const whatever &other);	
		whatever &operator=(const whatever &other);
		~whatever();

		// member function
		swap();
		min();
		max();
};
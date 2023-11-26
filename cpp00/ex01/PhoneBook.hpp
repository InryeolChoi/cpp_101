#pragma once

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>

class PhoneBook {
	private:
		Contact contacts[8];
		int		idx;
		size_t	size;
		void	TableOfContact(void);
		int		FindContact(void);
	public:
		PhoneBook();
		int 	AddContact(void);
		int		SearchContact(void);
};

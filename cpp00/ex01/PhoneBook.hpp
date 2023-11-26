#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <string>

class PhoneBook {
	private:
		Contact contacts[8];
		int		idx;
		int		size;
		void	TableOfContact(void);
		int		FindContact(void);
	public:
		PhoneBook();
		int 	AddContact(void);
		int		SearchContact(void);
};

#endif

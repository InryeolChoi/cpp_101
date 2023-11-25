#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook {
	private:
		Contact contacts[8];
		int		idx;
		int		size;
	public:
		PhoneBook();
		int 	AddContact(void);
		void	SearchContact(void);
};

#endif

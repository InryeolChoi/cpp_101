#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class PhoneBook {
	private:
		Contact contacts[8];
		int		idx;
	public:
		void 	AddContact(void);
		void	SearchContact(void);
};

#endif

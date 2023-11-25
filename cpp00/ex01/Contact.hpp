#pragma once
# define CONTACT_HPP
# define SUBSTR 1
# include <iostream>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		int			check_str(std::string str, int check);
		int			check_str(std::string str);

	public:
		std::string get_fname(void);
		std::string get_lname(void);
		std::string	get_nickname(void);
		std::string	get_pnum(void);
		std::string	get_secret(void);
		int 		set_fname(void);
		int			set_lname(void);
		int			set_nickname(void);
		int			set_pnum(void);
		int			set_secret(void);
};

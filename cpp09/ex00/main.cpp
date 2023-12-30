#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw BitcoinExchange::NotVaildFile();

		// data 파일 & input 파일 열기
		BitcoinExchange bx(av[1]);

		// data를 map에 넣기
		bx.datamap_init();
		bx.input_init();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
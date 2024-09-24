#include "../inc/BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Error: wrong nb of arguments" << std::endl;
		return (1);
	}
	BitcoinExchange btc(argv[1]);
	return 0;
}

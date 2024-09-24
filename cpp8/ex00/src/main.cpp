#include "../inc/easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> numbers;
	numbers.push_back(10);
	numbers.push_back(11);
	numbers.push_back(13);
	numbers.push_back(16);
	numbers.push_back(20);

	int target = 10;

	while (target <= 20)
	{
		try
		{
			std::vector<int>::iterator result = easyfind(numbers, target);
			if (result != numbers.end())
			{
				std::cout << "La valeur " << target << " a été trouvée à la position : " << std::distance(numbers.begin(), result) << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << target << " : " << e.what() << std::endl;
		}
		target++;
	}
	return 0;
}

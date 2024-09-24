#include "../inc/RPN.hpp"

int main(int argc, char **argv)
{
	std::string defense = "defense";
	if (argc != 2)
	{
		std::cout << "Error" << std::endl;
		return 0;
	}
	if (defense.compare(argv[1]))
	{
		std::string input = argv[1];
		RPN calculus(input);
	}
	else
	{
		RPN rpn(true);

		std::cout << std::endl;
		std::cout << "Test 0: Aucun opérateur: 5 3 6" << std::endl;
		rpn.calculate("5 3 6");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 1: Expression RPN valide: 5 3 +" << std::endl;
		rpn.calculate("5 3 +");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 2: Opérations plus complexes: 7 3 * 2 -" << std::endl;
		rpn.calculate("7 3 * 2 -");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 3: Division par zéro: 8 0 /" << std::endl;
		rpn.calculate("8 0 /");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 4: Expression RPN correcte avec espaces: 2 5 +   3 *" << std::endl;
		rpn.calculate("2 5 +   3 *");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 5: Opérations mixtes: 4 2 + 8 / 7 *" << std::endl;
		rpn.calculate("4 2 + 8 / 7 *");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 6: Expression RPN avec plusieurs opérations: 5 3 + 4 * 2 - 6 / 2 +" << std::endl;
		rpn.calculate("5 3 + 4 * 2 - 6 / 2 +");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 7: Expression RPN complexe: 5 3 + 4 2 - *" << std::endl;
		rpn.calculate("5 3 + 4 2 - *");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 8: Expression RPN complexe avec espaces: 5   3 +   4 2 - *" << std::endl;
		rpn.calculate("5   3 +   4 2 - *");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 9: Expression RPN vide" << std::endl;
		rpn.calculate("");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 10: RPN avec caractère '-' non comme opérateur: 5 - 3 +" << std::endl;
		rpn.calculate("5 - 3 +");
		std::cout << std::endl;
		std::cout << SEPARATOR << std::endl;
		std::cout << "Test 11: 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 * * * * * * * * *" << std::endl;
		rpn.calculate("9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 * * * * * * * * * * *");
		std::cout << std::endl;
	}
	return 0;
}

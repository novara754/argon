#include <iostream>
#include <string>
#include "Parser.h"

void help();

int main()
{
	std::cout << "Argon REPL. Enter `.help` for a list of meta commands." << std::endl << std::endl;

	while (true)
	{
		std::cout << "> " << std::flush;

		std::string input;
		std::getline(std::cin, input);

		if (input == ".help")
		{
			help();
			continue;
		}
		else if (input == ".quit")
			break;

		Parser parser(input);
		auto tree = parser.Parse();
		std::cout << tree->AsStr() << std::endl;
	}

	return 0;
}

void help()
{
	std::cout << ".help\t- Display this list of commands" << std::endl
		<< ".quit\t- Quit the REPL" << std::endl;
}

#include "Span.hpp"
#include <stdexcept>

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		// sp.randomFill();
		// sp.print();
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	}
	catch(const std::out_of_range& e)
	{
		std::cerr << "Out Of Range: " << e.what() << std::endl;
	}
	catch (const std::logic_error& e) {
       std::cerr << "Logic Error: " << e.what() << std::endl;
	}
	return 0;
}

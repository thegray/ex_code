#include <iostream>

int main()
{
	int num = 1;
	while (num > 0)
	{
		if (num % 3 == 0 && num % 5 == 0)
			std::cout << "fizz buzz, ";
		else if (num % 3 == 0)
			std::cout << "fizz, ";
		else if (num % 5 == 0)
			std::cout << "buzz, ";
		else
			std::cout << num << ", ";
		num++;
	}

	return 0;
}

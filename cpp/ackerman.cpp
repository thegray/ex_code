#include <iostream>

int ack(int m, int n)
{
	int ret = 0;
	if (m == 0)
		ret = n + 1;
	else if (n == 0)
		ret = ack(m-1, 1);
	else
		ret = ack(m-1, ack(m, n-1));
	return ret;
}

int main()
{
	int i = 4;
	int j = 1;
	std::cout << "ackerman :" << i << "," << j << ": " << ack(i,j);
	std::cin >> i;
	return 0;
}

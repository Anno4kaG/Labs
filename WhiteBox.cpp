#include <iostream>
#include <cmath>
#include <iomanip>

int sizechecker()
{
	int n;

	std::cout << "Enter size of the array: ";

	while (true)
	{
		try
		{
			if (!(std::cin >> n))
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "Size is non digit!";
			}
			else
				if (n <= 0 || n > 10)
					throw "Size is out of range!";
				else
					break;

		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new size: ";
		}
	}
	return n;
}

double checkparam(int n)
{
	double param;

	std::cout << "Type parameter: ";

	while (true)
	{
		try
		{
			if (!(std::cin >> param))
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "parameter is non digit!";
			}
			else
				break;
		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new parameter: ";
		}
	}
	return param;
}

void finder(double C, int n, int* arr)
{
	int k = 0;

	std::cout << "Indexes of founded element: ";

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < C)
		{
			k++;

			std::cout << i << " ";
		}
	}

	std::cout << std::endl;

	if (k > 0)
		std::cout << "Amount of elements less than C: " << k;
	else
		std::cout << "Nothing found!";
}

int main()
{
	int n;

	double C;

	n = sizechecker();

	int* arr = new int[n];

	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	C = checkparam(n);

	finder(C, n, arr);

	delete[] arr;

	return 0;
}

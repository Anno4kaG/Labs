#include <iostream>
#include <cmath>
#include <iomanip>

double task(double* arr, int n)
{
	double sum = 0;

	int s = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > 0)
		{
			s = i;
			break;
		}
	}

	if (s != 0)
	{
		for (int i = 0; i < s; i++)
			sum += arr[i];
	}
	else
		std::cout << "Sum is empty!\n";

	return sum;

}

double checkelem(int n)
{
	double elem;

	std::cout << "Type element: ";

	while (true)
	{
		try
		{
			if (!(std::cin >> elem))
			{
				std::cin.clear();

				while (std::cin.get() != '\n');

				throw "element is non digit!";
			}
			else
				break;
		}

		catch (const char* exception)
		{
			std::cout << exception << '\n';

			std::cout << "Type new element: ";
		}
	}
	return elem;
}


int sizechecker(int n)
{
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

int main()
{
	int n = 0;

	double t;

	std::cout << "Type size of the array: ";

	n = sizechecker(n);

	double* arr = new double[n];

	std::cout << "Type elements of the array: \n";

	for (int i = 0; i < n; i++)
		arr[i] = checkelem(n);

	t = task(arr, n);

	std::cout << "Sum: " << t;

	delete[] arr;

	return 0;
}

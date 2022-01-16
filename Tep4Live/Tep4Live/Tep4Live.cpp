#include <iostream>
#include "CQueue.h"
#include <random>

int main()
{
	CQueue<int> cque;
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> int_dist(-10000, 10000);

	std::cout << "Adding element to queue test:\n";
	int val_to_add;
	for (int i = 0; i < 20; i++)
	{
		val_to_add = int_dist(generator);

		std::cout << "Value to add: " << val_to_add << '\n';

		cque.add_elem(val_to_add);

		std::cout << "Queue structure after add operation:\n";
		cque.print_struct();
		std::cout << '\n';
	}

	std::cout << "\nFinding element in queue test:\n";
	int val_to_find;
	for (int i = 0; i < 2000; i++)
	{
		val_to_find = int_dist(generator);
		if (cque.in_queue(val_to_find))
		{
			std::cout << "Value: " << val_to_find << " exists in queue\n";
		}
	}

	std::cout << "\nRemoving element from queue test:\n";
	int val;
	for (int i = 0; i < 20; i++)
	{
		cque.get_elem(val);
		std::cout << "\nValue from get_elem nr " << i << ": " << val << '\n';

		std::cout << "Queue state after get_elem operation:\n";
		cque.print_struct();
	}
}
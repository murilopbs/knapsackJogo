#include "../headers/knapsack.hpp"

bool compare(std::pair<float, int> p1, std::pair<float, int> p2)
{
	return p1.first > p2.first;
}

int Knapsack::fractional_knapsack(std::vector<int> weights, std::vector<int> values, int capacity)
{
	int len = weights.size();
	int total_value = 0;

	// vector to store the items based on their value/weight ratios
	std::vector<std::pair<float, int>> ratio(len, std::make_pair(0.0, 0));

	for(int i = 0; i < len; i++)
		ratio[i] = std::make_pair(values[i]/weights[i], i);

	// now sort the ratios in non-increasing order
	// for this purpose, we will use our custom
	// comparator function
	sort(ratio.begin(), ratio.end(), compare);

	// start selecting the items
	for(int i = 0; i < len; i++)
	{
		if(capacity == 0)
			break;

		int index = ratio[i].second;

		if(weights[index] <= capacity)
		{
			// we item can fit into the knapsack
			// hence take the whole of it
			capacity -= weights[index];

			// add the value of this item to the
			// final answer
			total_value += values[index];
		}
		else
		{
			// this item doesn't fit into the bag
			// and thus we take a fraction of it
			//int value_to_consider = values[index] * (float(capacity)/float(weights[index]));
			//total_value += value_to_consider;
			//capacity = 0;
		}
	}

	return total_value;
}

/*int main()
{
	std::cout << "Enter the weights of the items, press -1 to stop" << std::endl;

	std::vector <int> weights;

	while(true)
	{
		int weight;
		std::cin >> weight;

		if(weight == -1)
			break;

		weights.push_back(weight);
	}

	std::cout << "Enter the values of each item, press -1 to stop" << std::endl;
	
	std::vector <int> values;

	while(true)
	{
		int value;
		std::cin >> value;

		if(value == -1)
			break;

		values.push_back(value);
	}

	std::cout << "Enter the capacity of the knapsack" << std::endl;

	int capacity;
	std::cin >> capacity;

	std::cout << "The maximum value possible based on current list is: " << fractional_knapsack(weights, values, capacity) << std::endl;
}*/
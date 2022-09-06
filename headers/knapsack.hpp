#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>

class Knapsack{
    public:
        int fractional_knapsack(std::vector<int> weights, std::vector<int> values, int capacity);
};
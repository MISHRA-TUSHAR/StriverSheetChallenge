#include <iostream>
#include <vector>

int findMinimumCoins(int amount)
{
    std::vector<int> coins{1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int minCoins = 0;
    int i = 0;

    while (amount > 0)
    {
        if (amount >= coins[i])
        {
            amount -= coins[i];
            minCoins++;
        }
        else
        {
            i++;
        }
    }

    return minCoins;
}
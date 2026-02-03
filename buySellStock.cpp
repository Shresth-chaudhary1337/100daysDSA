#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int &buyDay, int &sellDay) {

        int minPrice = prices[0];
        int minIndex = 0;

        int maxProfit = 0;
        buyDay = 0;
        sellDay = 0;

        for(int i = 1; i < prices.size(); i++) {

            // found new cheaper price → update buy day
            if(prices[i] < minPrice) {
                minPrice = prices[i];
                minIndex = i;
            }

            int profit = prices[i] - minPrice;

            // found better profit → update sell day
            if(profit > maxProfit) {
                maxProfit = profit;
                buyDay = minIndex;
                sellDay = i;
            }
        }

        return maxProfit;
    }
};

int main() {
    int n;

    std::cout << "Enter number of days: ";
    std::cin >> n;

    std::vector<int> prices(n);

    std::cout << "Enter prices: ";
    for(int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    Solution obj;

    int buyDay, sellDay;
    int profit = obj.maxProfit(prices, buyDay, sellDay);

    std::cout << "\nMaximum Profit = " << profit << std::endl;

    if(profit > 0) {
        std::cout << "Buy on day  : " << buyDay + 1 << std::endl;
        std::cout << "Sell on day : " << sellDay + 1 << std::endl;
    } else {
        std::cout << "No profitable transaction possible\n";
    }

    return 0;
}

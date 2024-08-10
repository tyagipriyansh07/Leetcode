// Solution to the Best Time to Buy and Sell Stock problem
// Approach: Single Pass
// The idea is to iterate through the prices while keeping track of the minimum price seen so far.
// At each step, we calculate the potential profit by subtracting the minimum price from the current price.
// We then update the maximum profit if the calculated profit is higher than the current maximum.
// This approach ensures that we find the maximum profit with a single pass through the prices.
// Time Complexity: O(n), where n is the number of elements in the prices array.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                int profit = prices[i] - minPrice;
                maxProfit = max(profit, maxProfit);
            }
        }
        return maxProfit;
    }
};

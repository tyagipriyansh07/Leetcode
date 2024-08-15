// Solution to the Single Number problem where every element appears three times except one
// Approach: Using Hash Map (unordered_map)
// The problem states that every element in the array appears three times except for one element that appears exactly once. 
// The goal is to find the element that appears only once.
// 
// **Step 1**: Iterate through the array and populate the hash map.
// Each element is used as a key, and the value is the count of occurrences of that element.
// 
// **Step 2**: Iterate through the array again and check the counts in the hash map.
// The element that has a count not divisible by 3 is the one that appears exactly once.
// 
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), where n is the number of unique elements in the hash map.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;

        // Step 1: Count the occurrences of each number
        for (int i = 0; i < n; i++) {
            map[nums[i]]++;
        }

        // Step 2: Identify the unique number that appears only once
        for (int i = 0; i < n; i++) {
            if (map[nums[i]] % 3 != 0) {
                return nums[i];
            }
        }

        // This return statement is a fallback. In the context of the problem, we should
        // always find a number that satisfies the condition, so this line should never be reached.
        return -1;
    }
};

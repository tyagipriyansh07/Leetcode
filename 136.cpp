// Solution to the Single Number problem
// Approach: Using XOR Operation
// The goal is to find the element that appears only once.
// 
// The XOR (^) operation has some useful properties that make it ideal for solving this problem:
// 1. **Identity Property**: a ^ 0 = a
// 2. **Self-Cancellation Property**: a ^ a = 0
// 3. **Commutative and Associative**: a ^ b ^ a = a ^ a ^ b = 0 ^ b = b
// 
// By XORing all elements in the array, the elements that appear twice will cancel each other out (because x ^ x = 0),
// and the element that appears only once will be the result of all XOR operations.
// 
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), since no extra space is used beyond the result variable.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        // Iterate over each element in the array
        for(int i = 0; i < nums.size(); i++){
            ans ^= nums[i];  // XOR the current element with the result
        }
        // After processing all elements, 'ans' will hold the single number
        return ans;
    }
};

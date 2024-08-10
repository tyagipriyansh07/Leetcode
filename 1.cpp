// Solution to the Two Sum problem
// Approach: Brute Force
// The brute force approach involves checking every pair of numbers
// in the array to see if they sum up to the target value. 
// We use two nested loops to iterate over the array. The outer loop 
// starts with the first element, and the inner loop checks all 
// subsequent elements for a pair that adds up to the target.
// Time Complexity: O(n^2) where n is the number of elements in the array.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

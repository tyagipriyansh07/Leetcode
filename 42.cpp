/*
Approach:
The problem is solved using the two-pointer technique, with one pointer starting from the left (lpos) and the other from the right (rpos). We track the maximum height encountered so far from both sides using two variables: lmax (left max) and rmax (right max).

Steps:
1. Initialize lmax and rmax to the first and last heights, respectively. 
2. Use a while loop to iterate until the left pointer (lpos) surpasses the right pointer (rpos).
3. If the current height at lpos is greater than or equal to lmax, update lmax and move the left pointer to the right.
4. If the current height at rpos is greater than or equal to rmax, update rmax and move the right pointer to the left.
5. If lmax is less than or equal to rmax and the height at lpos is less than lmax, calculate trapped water (lmax - height[lpos]) and move the left pointer.
6. Otherwise, calculate trapped water for the right side (rmax - height[rpos]) and move the right pointer.
7. Continue this process until the two pointers meet, adding trapped water at each step.
8. Return the total trapped water.

Time Complexity: O(n), where n is the number of heights.
Space Complexity: O(1), as no extra space is used apart from variables.
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lmax = height[0];
        int rmax = height[n-1];
        int lpos = 1;
        int rpos = n-2;
        int water = 0;
        while(lpos <= rpos)
        {
            if(height[lpos] >= lmax)
            {
                lmax = height[lpos];
                lpos++;
            }
            else if(height[rpos] >= rmax)
            {
                rmax = height[rpos];
                rpos--;
            }
            else if(lmax <= rmax && height[lpos] < lmax)
            {
                water += lmax - height[lpos];
                lpos++;
            }
            else
            {
                water += rmax - height[rpos];
                rpos--;
            }
        }
        return water;
    }
};

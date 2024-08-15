// Solution to the Largest Rectangle in Histogram problem
// Approach: Stack-Based Monotonic Decreasing Stack
// The idea is to calculate the largest rectangle area by finding the width of the largest rectangle
// for each bar in the histogram. This is done by calculating the "next smaller element" and "previous smaller element"
// for each bar in the histogram using two separate passes.
// The "next smaller element" for a bar is the first bar to the right that is shorter, and the "previous smaller element"
// is the first bar to the left that is shorter. The width of the rectangle can then be computed as the distance between 
// these two smaller elements, and the area is the width multiplied by the height of the current bar.
// The maximum area across all bars is the solution.
//
// Time Complexity: O(n), where n is the number of elements in the histogram. The use of stacks ensures that each bar is pushed and popped only once.
//
// Space Complexity: O(n) for the stacks and the auxiliary arrays used to store the indices of the next and previous smaller elements.

class Solution {
private:
    // Helper function to find the index of the next smaller element for each element in the array
    vector<int> nextSmaller(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();  // Storing the index of the next smaller element
            s.push(i);  // Pushing the index instead of the value
        }

        return ans;
    }

    // Helper function to find the index of the previous smaller element for each element in the array
    vector<int> prevSmaller(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();  // Storing the index of the previous smaller element
            s.push(i);  // Pushing the index instead of the value
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Calculate the next smaller element indices for each bar
        vector<int> next = nextSmaller(heights, n);

        // Calculate the previous smaller element indices for each bar
        vector<int> prev = prevSmaller(heights, n);

        int area = 0;  // Initialize maximum area as 0

        // Iterate over each bar to calculate the area and update the maximum area
        for(int i = 0; i < n; i++) {
            int l = heights[i];  // The height of the current bar

            // If there is no smaller element to the right, set it to the end of the array
            if(next[i] == -1) {
                next[i] = n; 
            }

            int b = next[i] - prev[i] - 1;  // Calculate the width of the rectangle
            int newArea = l * b;  // Calculate the area of the rectangle

            area = max(area, newArea);  // Update the maximum area if the current one is larger
        }

        return area;  // Return the maximum area found
    }
};

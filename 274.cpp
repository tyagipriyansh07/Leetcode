    /**
     * Approach:
     * 1. First, sort the array of citations in descending order.
     *    This helps to check how many papers have at least a certain number of citations.
     * 2. Then, iterate over the sorted array. For each paper, check if the number of citations 
     *    is greater than or equal to the current index + 1 (because we need at least 'i + 1' papers 
     *    with 'i + 1' citations).
     * 3. If the condition is satisfied, update the h-index to 'i + 1'.
     * 4. If not, break out of the loop since further papers have fewer citations.
     * 5. Return the maximum h-index found.
     *
     * Time Complexity:
     * - Sorting the array takes O(n log n), where n is the number of papers (size of the citations array).
     * - The loop that calculates the h-index runs in O(n), so the overall time complexity is O(n log n).
     * 
     * Space Complexity: 
     * - O(1) additional space, ignoring the input storage.
     */
class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(),citations.end(),greater<int>());

        int h=0;

        for(int i=0;i<citations.size();i++){
            if(citations[i]>=i+1){
                h=i+1;
            }
            else{
                break;
            }
        }
        return h;
    }
};

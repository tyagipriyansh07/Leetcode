// approch to the problem 
// i used the recursive approch where i solved the first case and then call the function for the rest.
// the edge case has also been solved if the list is empty or only 1 element is present

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* first = head;
        ListNode* second = head->next;

        first->next = swapPairs(second->next);
        second->next = first;

        return second;
    }
};

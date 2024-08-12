// Solution to the Add Two Numbers problem
// Approach: Linked List Iteration
// The idea is to iterate through the two linked lists representing the numbers digit by digit,
// simulating the addition process as you would do by hand. We maintain a carry that is initially 0.
// For each pair of nodes, we sum their values with the carry from the previous addition, 
// create a new node with the digit of the result (sum % 10), and move to the next nodes.
// If one list is shorter, we continue with the remaining nodes of the longer list. 
// If there's still a carry after processing both lists, we add an additional node.
// Time Complexity: O(max(n, m)), where n and m are the lengths of the input lists.

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* temp = new ListNode(0);
        ListNode* curr=temp;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0){
            int sum=carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
              sum+=l2->val;
              l2=l2->next;
            }
            carry=sum/10;
            curr->next=new ListNode(sum%10);
            curr=curr->next;
        }
        // ListNode* result=temp->next;
        
        return temp->next;
    }
};

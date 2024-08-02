 // approch to the problem
 // I used merge sort, here are the detailed steps:
 // step1: find middle node using the fast and slow pointers
 // step2: break the original list into two half: left and right
 // step3: recursively sort both left and right 
 // step4: merge the list after sorting
 // step5: return merged list
 
class Solution {
    private:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        ListNode* ans = new ListNode(-1);
        ListNode* temp=ans;

        while(left!=NULL && right!=NULL)
        {
            if(left->val < right->val)
            {
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else
            {
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }

        while(left!=NULL)
        {
                temp->next=left;
                temp=left;
                left=left->next; 
        }

        while(right!=NULL)
        {
                temp->next=right;
                temp=right;
                right=right->next;
        }

        ans=ans->next;
        return ans;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return head;
        }
        //step1:
        ListNode* mid=findMiddle(head);
        //step2:
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        //step3:
        left=sortList(left);
        right=sortList(right);
        //step4:
        ListNode* answer = merge(left,right);
        //step5:
        return answer;
    }
};

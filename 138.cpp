//approch
//step1:clone the original list
//step2:create an map which will have old nodes mapped with clone nodes
//step3:copy random pointer
//step4:return clonehead

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        //step 1: Create a Clone List
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp -> next;
        }
        
        // step 2: 
        unordered_map<Node*,Node*> oldTonew;
        Node* originalnode = head;
        Node* cloneNode = cloneHead;

        while(originalnode != NULL && cloneNode != NULL){
            oldTonew[originalnode]=cloneNode;
            originalnode=originalnode->next;
            cloneNode=cloneNode->next;
        }
        // step 3: Random pointer copy
        originalnode = head;
        cloneNode = cloneHead;
        while(originalnode != NULL){
            cloneNode->random=oldTonew[originalnode->random];
            originalnode=originalnode->next;
            cloneNode=cloneNode->next;     
        }

        // step 4 answer return
        return cloneHead;    
    }
};


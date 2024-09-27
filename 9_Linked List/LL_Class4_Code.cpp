//1. Linked List Cycle(Loop)

//Using map
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, bool> table;
        
        ListNode* temp = head;

        //Inside the loop, we check if the current node temp is present 
        //in the map table. If it's not present (i.e., table[temp] is false), 
        //we mark it as visited by setting table[temp] to true.

        while(temp != NULL){
            if(table[temp] == false){
                table[temp] = true;
            }

            else{
                //cycle present
                return true;
            }

            temp = temp->next;
        }

        //cycle not present 
        return false;
    }
};

//Method - 2 : Slow and fast method
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }

            if(slow == fast){
                return true;
            }
        }

        return false;
    }
};    



//2. Starting point of loop (Linked List Cycle II)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        //check cycle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }

            if(fast == slow){
                break;
            }
        }

        if(fast == NULL){
            //No cycle present
            return NULL;
        }

        //Yaha pahucha matlab slow and fast meet kar chuke h
        slow = head;

        // Slow and fast ek - ek step
        while(fast != slow){
            slow = slow -> next;
            fast = fast -> next;
            
        }
        // return starting point
        return slow;
        
    }
};


// 3. Remove loop in Linked List

class Solution {
public:
    void removeLoop(Node* head){
        
        Node* slow = head;
        Node* fast = head;

        // Detecting loop using Floyd’s cycle detection algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if (slow == fast) {
                break;
            }
        }

        // No cycle found
        if (fast == NULL || fast->next == NULL) {
            return;
        }

        // Reset slow to head to find the start of the loop
        slow = head;

        // Now fast and slow both move one step at a time
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        while (fast->next != slow) {
            fast = fast->next;   
        }
        fast->next = NULL;  
    }
};
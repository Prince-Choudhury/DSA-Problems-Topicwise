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

// 4. Add 1 to a Linked List
class Solution {
  public:
  
 
    Node* reverseLL(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr!=NULL){
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    Node* addOne(Node* head) {
        
        //Step 1 : Reverse LL
        head = reverseLL(head);
        
        Node* temp = head;
        int carry = 1;
        
        //Step 2 : Add 1
        while(temp->next!=NULL){
            
            int totalSum = temp->data + 1;
            int digit = totalSum%10;
            carry = totalSum/10;
            
            temp->data = digit;
            temp = temp->next;
            
            if(carry == 0){
                break;
            }
            
        }
        
        //Process last Node
        if(carry!=0){
            int totalSum = temp->data + 1;
            int digit = totalSum%10;
            carry = totalSum/10;
            
            temp->data = digit;
            
            if(carry!=0){
                Node* newNode = new Node(carry);
                temp->next = newNode;
            }
        }
        
        //Step 3 : Reverse LL
        head = reverseLL(head);
        
        return head;
        
    }
};

// 5. Add 2 numbers represented by Linked list

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0); // Dummy node to store result
        ListNode* temp = result; // Pointer to iterate over result list
        int carry = 0; // To store carry during addition

        // Loop until both lists are exhausted or there is a carry left
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int sum = carry;

            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }

            int digit = sum % 10;
            carry = sum / 10; // Calculate carry for the next step
            temp->next = new ListNode(digit); // Create a new node for the current digit
            temp = temp->next; // Move to the next node
        }

        return result->next; // Return the result list, skipping the dummy node
    }
};


// 6. Reverse Nodes in K-groups

class Solution {
public:
    int getLength(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL ) {
            return head;
        }
        if(head->next == NULL) {
            return head;
        }

        //1 case solve kiya
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;
        int pos = 0;
        
        int len = getLength(head);
        if(len < k) {
            return head;
        }

        while(pos < k ){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }

        ListNode* recursionKaAns = NULL;
        if(nextNode != NULL) {
            recursionKaAns = reverseKGroup(nextNode, k);
            head->next = recursionKaAns;
        }

        return prev;
    }
};



// 7. Remove Duplicates from Sorted List

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        while(temp != NULL){
          if(temp->next!=NULL && temp->val == temp->next->val){
            //Remove Node
            ListNode* nextNode = temp->next;
            temp->next = nextNode->next;
            nextNode->next = NULL;
            delete nextNode;
          }
          else{
            temp = temp->next;
          }
        }

        return head;
    }
};



// 8. Quick sort and Merge sort For LL and Array

Quick Sort and Merge Sort behave differently in terms of performance depending on whether you are working with arrays or linked lists due to the underlying structures and how data is accessed. Here's a comparison of how they perform on each:

1. Quick Sort:
For Arrays:
Best choice: Quick Sort performs well on arrays because it allows random access to elements, which is important for efficiently partitioning the array.

In-place: Quick Sort is an in-place sorting algorithm, meaning it does not require additional space (beyond recursion stack space).
For Linked Lists:
Less efficient: Quick Sort does not perform as well on linked lists because linked lists do not support random access. To partition a linked list, we would need to traverse it multiple times, making it inefficient compared to arrays.

O(nlogn) on average, but due to the need for sequential access in linked lists, it tends to perform poorly in practice.


2. Merge Sort:

For Arrays:
Good choice: Merge Sort works well on arrays, but it is not an in-place sorting algorithm, requiring 

O(n) extra space for the merging step (since arrays need to be copied).

O(nlogn) time regardless of the input distribution.
Not in-place: Since arrays cannot be modified easily during the merging step, Merge Sort for arrays requires extra memory for the temporary arrays used in the merge operation.


For Linked Lists:
Best choice: Merge Sort is ideal for linked lists because it efficiently merges two halves of a list by simply adjusting pointers, avoiding the overhead of copying elements like in arrays.

O(nlogn), but it does not require extra space for linked lists (aside from the recursive call stack). This is because merging linked lists only requires pointer manipulation.
In-place for Linked Lists: Merge Sort can be considered almost in-place for linked lists because it doesn’t need extra arrays for merging.

Quick Sort performs better on arrays due to random access.
Merge Sort performs better on linked lists because it avoids the overhead of array copying and works well with sequential access.

Quick Sort → Arrays
Merge Sort → Linked Lists


// 9. 



// 10. 
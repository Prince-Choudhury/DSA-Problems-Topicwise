#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(){
            this->data = 0;
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            cout<<"Destructor called for : "<<this->data<<endl;
        }
};

void insertAtHead(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

int lengthLL(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void deleteNode(Node* &head, Node* &tail, int position){
    
    int len = lengthLL(head);

    //1. empty List
    if(head == NULL){
        cout<<"Can not delete, coz LL is empty"<<endl;
        return;
    }

    //2. single element
    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    //3. delete from head
    if(position == 1){
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }

    //4. delete from tail
    else if(position == len){
        Node* prev = NULL;
        while(position != 1){
            position--;
            prev = prev->next;
        }

        prev->next = NULL;
        delete tail;
        tail = prev;
    }

    else{
        //5. Delete from middle
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            position--;
            prev = curr;
            curr = curr->next;
        }

        prev-> next = curr->next;
        curr->next = NULL;  

        delete curr;

    }
    
}

void printLL(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}


int main(){
    
    Node* head = NULL;
    Node* tail = NULL;
    //insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);

    deleteNode(head, tail, 4);
    printLL(head);
    cout<<lengthLL(head)<<endl;
    return 0;
}

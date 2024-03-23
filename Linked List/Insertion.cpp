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

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
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

void insertAtPosition(Node* &head, Node* &tail, int pos, int data){
    int len = lengthLL(head);

    if(pos == 1){
        insertAtHead(head, tail, data);
        return;
    }

    else if(pos == len){
        insertAtTail(head, tail, data);
        return;
    }

    else{
        Node* newNode = new Node(data);
        Node* prev = NULL;
        Node* curr = head;
        while(pos!=1){
            pos--;
            prev = curr;
            curr = curr->next;
        }

        prev->next = newNode;

        newNode->next = curr;

        
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
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    insertAtPosition(head, tail, 4, 35);
    printLL(head);
    cout<<lengthLL(head)<<endl;
    return 0;
}
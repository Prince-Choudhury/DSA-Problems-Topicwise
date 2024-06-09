#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Stack class using linked list
class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    // Push an element onto the stack
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop the top element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Get the top element of the stack
    int getTop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    // Get the size of the stack
    int getSize() {
        return size;
    }

    // Print the current state of the stack
    void print() {
        cout << "Top: " << (top ? top->data : -1) << endl;
        cout << "Stack: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Creation
    Stack st;

    // Push
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();

    // Top element
    cout << "Top element: " << st.getTop() << endl;

    // Size of stack
    cout << "Size of stack: " << st.getSize() << endl;

    // Pop
    st.pop();
    st.pop();
    st.print();

    // Check if stack is empty
    if (st.isEmpty()) {
        cout << "Empty" << endl;
    } else {
        cout << "Not empty" << endl;
    }

    return 0;
}

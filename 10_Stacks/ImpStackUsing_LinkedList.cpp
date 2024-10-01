#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int data) {
      this->data = data;
      this->next = nullptr;
    }
};

class Stack {
  public:
    Node* top;  // Pointer to the top node
    int size;

    Stack() {
      this->top = nullptr;
      this->size = 0;
    }

    // Push operation
    void push(int data) {
      Node* newNode = new Node(data);
      if(!newNode) {
        cout << "Stack overflow" << endl;
        return;
      }
      newNode->next = top;  // Point newNode's next to the current top
      top = newNode;  // Update the top pointer
      size++;
    }

    // Pop operation
    void pop() {
      if(top == nullptr) {
        cout << "Stack underflow" << endl;
        return;
      }
      else {
        Node* temp = top;
        top = top->next;  // Move top to the next node
        delete temp;  // Free the memory of the popped node
        size--;
      }
    }

    // Check if stack is empty
    bool isEmpty() {
      return top == nullptr;
    }

    // Get the top element
    int getTop() {
      if(top == nullptr) {
        cout << "Stack is empty" << endl;
        return -1;
      }
      return top->data;
    }

    // Get the size of the stack
    int getSize() {
      return size;
    }

    // Print the stack
    void print() {
      if(top == nullptr) {
        cout << "Stack is empty" << endl;
        return;
      }
      Node* temp = top;
      cout << "Stack: ";
      while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }
};

int main() {
  // Creation
  Stack st;

  // Push elements
  st.push(10);
  st.push(20);
  st.push(30);

  st.print();  // Output: Stack: 30 20 10

  cout << "Top element: " << st.getTop() << endl;  // Output: Top element: 30
  cout << "Size of stack: " << st.getSize() << endl;  // Output: Size of stack: 3

  // Pop elements
  st.pop();
  st.print();  // Output: Stack: 20 10

  cout << "Top element: " << st.getTop() << endl;  // Output: Top element: 20
  cout << "Size of stack: " << st.getSize() << endl;  // Output: Size of stack: 2

  if(st.isEmpty()) {
    cout << "Stack is empty" << endl;
  } else {
    cout << "Stack is not empty" << endl;
  }

  return 0;
}

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree(){
    cout<<"Enter the value for Node : "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    //step1 : create Node
    Node* root = new Node(data);

    //step2 : create left Subtree
    cout<<"left of Node :"<<root->data<<endl;
    root->left = createTree();

    //step3 : create right Subtree
    cout<<"right of Node : "<<root->data<<endl;
    root->right = createTree();

    return root;
}

int main(){
    Node* root = createTree();
    cout<<root->data<<endl;
    
    return 0;
}
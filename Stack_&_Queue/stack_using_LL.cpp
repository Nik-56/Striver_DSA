#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Stack{
    public:
        Node* top;
        int size=0;

        void push(int x){
            Node* temp= new Node(x);
            temp->next = top;
            top = temp;
            size++;
            cout<<"Element pushed into stack.";
        }

        void pop(){
            if(size==0){
                cout<<"Stack Underflow";
                return;
            }
            Node* temp = top;
            top= top->next;
            delete temp;
            size--;
            cout<<"Element deleted from stack";
        }

        int peek(){
            if(size==0)
                return -1;
            return top->data;
        }

        int getSize(){
            return size;
        }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.peek() << endl;  // 30
    st.pop();
    cout << "Top element after pop: " << st.peek() << endl;  // 20
    cout << "Size of stack: " << st.getSize() << endl;  // 2
}
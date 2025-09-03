#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* next;
    int data;
    Node(int x){
        data= x;
        next = nullptr;
    }
};

Node* Input_LL(){
    Node* head = nullptr;
    Node* tail = nullptr;

    int val;
    while (cin >> val && val != -1) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main(){
        
}
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr){
        data = data1;
        next = next1;
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

int change2number(Node* LL){
    int res = LL->data;
    int tens = 10;
    LL = LL->next;
    while(LL){
        int temp = LL->data;
        LL = LL->next;
        temp = tens*temp;
        tens = tens*10;
        res += temp;
    }
    return res;
}

Node* change2LL(int num){
    Node* head = nullptr;
    Node* tail = nullptr;

    if (num == 0) return new Node(0); 
    while(num > 0){
        int temp = num % 10;
        Node* newNode = new Node(temp);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        num /= 10;
    }
    return head;

}

Node* Add_2_LL(Node* LL1, Node* LL2){
    int LL1_num = change2number(LL1);
    int LL2_num = change2number(LL2);
    int LL3_num = LL1_num + LL2_num;
    Node* res = change2LL(LL3_num);
    return res;
}

void traverse(Node* LL3){
    while(LL3) {
        cout << LL3->data << " ";
        LL3 = LL3->next;
    }
    cout << endl;
}

Node* Add_2_numbers(Node* LL1, Node* LL2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry=0;

    while(LL1 || LL2){
        int sum=carry;
        if(LL1)  sum+= LL1->data;
        if(LL2)  sum+= LL2->data;

        Node* NewNode = new Node(sum%10);
        carry = sum/10;

        curr->next = NewNode;
        curr= curr->next;
        
        if(LL1)     LL1=LL1->next;
        if(LL2)     LL2=LL2->next;
    }
    return dummyNode->next;
}

int main(){
    cout<<"Enter elements of 1st Linked List (-1 to stop): ";
    Node* LL1 = Input_LL();
    cout<<"Enter elements of 2nd Linked List (-1 to stop): ";
    Node* LL2 = Input_LL();

    Node* LL3 = Add_2_LL(LL1, LL2);
    Node* LL4 = Add_2_numbers(LL1, LL2);
    traverse(LL3);
    traverse(LL4);
}
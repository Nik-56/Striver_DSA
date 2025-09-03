#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            data=x;
            next=NULL;
        }
};

class Queue{
    public:
        Node* start= NULL;
        Node* end= NULL;
        int size=0;

        void push(int x){
            Node* temp = new Node(x);
            if(start==NULL){
                start=temp;
                end=temp;
            }
            else{
                end->next= temp;
                end= end->next;
            }    
            size++;
            cout<<"Element pushed in queue."<<endl;
        }

        void pop(){
            if(start==NULL){
                cout<<"Queue is empty"<<endl;
                return;
            }
            Node* temp= start;
            start= start->next;
            delete(temp);
            size--;
            if(start==NULL) end=NULL;
            cout<<"Element removed from queue"<<endl;
        }

        int peek(){
            if(start==NULL){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            return start->data;
        }

        int getSize(){
            return size;
        }
};

int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.peek()<<endl;
    q.pop();
    q.push(40);
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    cout<<q.getSize()<<endl;
}
#include <bits/stdc++.h>
using namespace std;

class quImpl {
    int start;
    int end;
    int curr_size;
    int size;
    int* q;   // pointer to dynamically allocate array

public:
    quImpl(int s) {
        size = s;
        q = new int[size];
        start = -1;
        end= -1;
        curr_size= 0;
    }

    // Push function
    void push(int x) {
        if(curr_size==size){
            cout<<"Queue is full";
            return;
        }
        if (start==-1 && end==-1) {
            start=0;
            end=0;
        }
        else{
            end = (end+1)%size;
        }
        q[end] = x;
        curr_size++;
        cout << x << " pushed into Queue\n";
    }

    void pop(){
        if(curr_size==0){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        if(curr_size==1){
            start=-1;
            end=-1;
        }
        else{
            start= (start+1)%size;
        }
        curr_size--;
        cout<<"Element removed from queue"<<endl;
    }

    int seek(){
        if(curr_size==0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return q[start];
    }

    int st_size(){
        return curr_size;
    }
};

int main(){
    int n;
    cout<<"Enter size of stack: ";
    cin>>n;
    quImpl q(n);

    q.push(10);
    q.push(20);
    q.push(30);
    cout<<q.seek()<<endl;
    q.pop();
    q.push(40);
    cout<<q.seek()<<endl;
    q.pop();
    cout<<q.seek()<<endl;
    cout<<q.st_size()<<endl;
}
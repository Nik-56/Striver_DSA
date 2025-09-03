#include <bits/stdc++.h>
using namespace std;

class Queue{
    public:
        stack<int> s1, s2;

        void q_push(int x){
            while(s1.size()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(s2.size()){
                s1.push(s2.top());
                s2.pop();
            }
        }

        void q_pop(){
            s1.pop();
        }

        int q_top(){
            return s1.top();
        }

        int q_size(){
            return s1.size();
        }
};

int main(){
    Queue q;

    q.q_push(10);
    q.q_push(20);
    q.q_push(30);
    cout<<q.q_top()<<endl;
    q.q_pop();
    q.q_push(40);
    cout<<q.q_top()<<endl;
    q.q_pop();
    cout<<q.q_top()<<endl;
    cout<<q.q_size()<<endl;
}
#include <bits/stdc++.h>
using namespace std;

class stImpl {
    int top;
    int size;
    int* st;   // pointer to dynamically allocate array

public:
    stImpl(int s) {
        size = s;
        st = new int[size];
        top = -1;
    }

    // Push function
    void push(int x) {
        if (top >= size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        st[top] = x;
        cout << x << " pushed into stack\n";
    }

    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        top--;
        cout<<"Removod top element of stack"<<endl;
    }

    int seek(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return st[top];
    }

    int st_size(){
        if(top==-1)
            return 0;
        return top;
    }
};

int main(){
    int n;
    cout<<"Enter size of stack: ";
    cin>>n;
    stImpl st(n);

    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top element is " << st.seek() << endl;

    st.pop();
    cout << "Top element after pop is " << st.seek() << endl;
}
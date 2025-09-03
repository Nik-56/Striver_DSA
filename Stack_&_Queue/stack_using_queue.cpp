#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
        queue<int> q;

        void st_push(int x){
            int st_size= q.size();
            q.push(x);

            for(int i=1; i<=st_size; i++){
                q.push(q.front());
                q.pop();
            }
            cout<<"Pushed element into stack"<<endl;
        }

        void st_pop(){
            q.pop();
        }

        int st_top(){
            return q.front();
        }

        int st_size(){
            return q.size();
        }
};

int main(){
    Stack st;

    st.st_push(10);
    st.st_push(20);
    st.st_push(30);
    cout << "Top element is " << st.st_top() << endl;

    st.st_pop();
    cout << "Top element after pop is " << st.st_top() << endl;
}
#include <bits/stdc++.h>
using namespace std;

bool isValid(string par){
    int n= par.length();
    if(n%2!=0)
        return false;
    stack<char> st;

    for(auto ch: par){
        if(ch=='(' || ch=='[' || ch=='{')
            st.push(ch);
        
        else if (ch == ')' || ch == ']' || ch == '}'){
            if(st.empty())
                return false;
            
            if((st.top()=='[' && ch==']') || (st.top()=='(' && ch==')') || (st.top()=='{' && ch=='}'))
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}

int main(){
    stack<int> st;
    string par;
    cout<<"Enter paranthesis combination: ";
    cin>>par;
    if(isValid(par))
        cout<<"Valid";
    else
        cout<<"Not Valid";
}
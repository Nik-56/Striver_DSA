#include <bits/stdc++.h>
using namespace std;

int precedence(char ch){
    if(ch=='^')
        return 4;
    else if(ch=='*' || ch=='/')
        return 3;
    else if(ch=='+' || ch=='-')
        return 2;
    else
        return 1;
}

string infixToPostfix(string s){
    stack<char> st;
    string ans = "";
    int n = s.length();
    for(int i=0; i<n; i++){
        if(isalnum(s[i])){
            ans += s[i];
        }
        else if(s[i]=='^' || s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-' || s[i]=='('){
            if(st.empty() || precedence(st.top()) < precedence(s[i]) || s[i]=='('){
                st.push(s[i]);
            }
            else {
                while(!st.empty() && st.top()!='(' && precedence(st.top()) >= precedence(s[i])){
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans += st.top();
                st.pop();
            }
            if(!st.empty()) st.pop(); // pop '('
        }
        cout<<ans<<endl;
        if(!st.empty()) cout<<st.top()<<endl;
    }

    // pop remaining operators
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    return ans;
}


int main(){
    string s;
    cout<<"Enter infix expression: ";
    cin>>s;
    cout<<infixToPostfix(s);
}
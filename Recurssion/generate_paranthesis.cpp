#include <bits/stdc++.h>
using namespace std;

void func(int op, int cl, int n, string st){
    if(op==n && cl==n){
        cout<<st<<endl;
        return;
    }
    if(op<n)
        func(op+1, cl, n, st+"(");
    if(op>cl)
        func(op, cl+1, n, st+")");
}

int main(){
    cout<<"Enter the paranthesis required: ";
    int n;
    cin>>n;
    func(0, 0, n, "");
}
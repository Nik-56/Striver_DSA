#include <bits/stdc++.h>
using namespace std;

void func(int ind, string st){
    if(ind == st.size()-1){
        cout<<st<<endl;
        return;
    }

    for(int i=ind; i<st.size(); i++){
        swap(st[ind], st[i]);
        func(ind+1, st);
        swap(st[ind], st[i]);
    }
}

int main(){
    string st;
    cout<<"Enter a string: ";
    cin>>st;
    func(0, st);
    
}
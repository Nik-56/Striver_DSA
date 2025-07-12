#include <bits/stdc++.h>
using namespace std;

void func(int index, string s, string temp, vector<string> &res){
    if(index==s.size()){
        res.push_back(temp);
        return;
    }
    func(index+1, s, temp+" "+s[index], res);
    func(index+1, s, temp+s[index], res);
}

int main(){
    cout<<"Enter string: ";
    string s;
    cin>>s;
    string temp;
    temp+=s[0];
    vector<string> res;
    func(1, s, temp, res);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<endl;
}
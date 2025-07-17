#include <bits/stdc++.h>
using namespace std;

void func(int ind, string str, int n, vector<int> arr, unordered_map<int, vector<char>> mp){
    if(ind==n){
        cout<<str<<"  ";
        return;
    }
    for(int i=0; i< mp[arr[ind]].size(); i++){
        str+= mp[arr[ind]][i];
        func(ind+1, str, n, arr, mp);
        str.pop_back();
    }
}

int main(){
    int n;
    cout<<"Enter number of digits: ";
    cin>>n;
    cout<<"Enter digits: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    unordered_map<int, vector<char>> mp;
    mp[2] = {'a', 'b', 'c'};
    mp[3] = {'d', 'e', 'f'};
    mp[4] = {'g', 'h', 'i'};
    mp[5] = {'j', 'k', 'l'};
    mp[6] = {'m', 'n', 'o'};
    mp[7] = {'p', 'q', 'r', 's'};
    mp[8] = {'t', 'u', 'v'};
    mp[9] = {'w', 'x', 'y', 'z'};

    func(0, "", n, arr, mp);
}
#include <bits/stdc++.h>
using namespace std;

void permutation_one(vector<int> arr, vector<int> freq, vector<int> ds){
    if(ds.size()==arr.size()){
        for(int i=0; i<ds.size(); i++)
            cout<<ds[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i=0; i<arr.size(); i++){
        if(!freq[i]){
            freq[i]=true;
            ds.push_back(arr[i]);
            permutation_one(arr, freq, ds);
            ds.pop_back();
            freq[i]=false;
        }
    }
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter elements of array: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vector<int> freq(n, 0);
    vector<int> ds;
    vector<vector<int>> ans;
    permutation_one(arr, freq, ds);
}
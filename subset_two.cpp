#include <bits/stdc++.h>
using namespace std;

void subset_two(int ind, vector<int> arr, vector<int> ds, int n){
    for(int i=0; i<ds.size(); i++){
            cout<<ds[i]<<" ";
    }
    cout<<endl;
    for(int i=ind; i<n; i++){
        if(arr[i]==arr[i-1] && i>ind)   continue;
        ds.push_back(arr[i]);
        subset_two(i+1, arr, ds, n);
        ds.pop_back();
    }
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter elements of array: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> ds;
    subset_two(0, arr, ds, n);
}
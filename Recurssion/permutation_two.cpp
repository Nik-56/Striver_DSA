#include <bits/stdc++.h>
using namespace std;

void permutation_two(int ind, vector<int> arr, int n){
    if(ind>=n){
        for(int i=0; i<n; i++)
            cout<<arr[i];
        cout<<endl;
        return;
    }
    for(int i=ind; i<n; i++){
        swap(arr[ind], arr[i]);
        permutation_two(ind+1, arr, n);
        swap(arr[ind], arr[i]);
    }
}

int main(){
    int n;
    cout<<"ENTER SIZE OF ARRAY: ";
    cin>>n;
    cout<<"ENTER ELEMENTS: ";
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    permutation_two(0, arr, n);
}
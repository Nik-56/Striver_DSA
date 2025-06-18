#include <bits/stdc++.h>
using namespace std;

void subset_one(int ind, int* arr, int sum, int n){
    if(ind>=n){
        cout<<sum<<" ";
        return;
    }
    subset_one(ind+1, arr, sum+arr[ind], n);
    subset_one(ind+1, arr, sum, n);
}

int main() {
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    subset_one(0, arr, 0, n);
    return 0;
}
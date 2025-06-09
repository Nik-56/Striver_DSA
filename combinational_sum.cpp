#include <bits/stdc++.h>
using namespace std;

void comb_sum(int arr[], int n, int ind, int target, vector<int> &ds, vector<vector<int>> &res) {
    if(ind==n){
        if(target==0){
            res.push_back(ds);
        }
        return;
    }

    if(arr[ind]<= target){
        ds.push_back(arr[ind]);
        comb_sum(arr, n, ind, target - arr[ind], ds, res);
        ds.pop_back();
    }
    comb_sum(arr, n, ind+1, target, ds, res);
}

int main(){
    vector<vector<int>> res;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int sum;
    cout<<"Enter target sum: ";
    cin>>sum;
    vector<int> ans;
    comb_sum(arr, n, 0, sum, ans, res);
    cout << "Combinations:\n";
    for (auto& combo : res) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}
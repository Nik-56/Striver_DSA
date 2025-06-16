#include <bits/stdc++.h>
using namespace std;

void comb_sum_two(int ind, int target, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans){
    if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind; i<arr.size(); i++){
        if(arr[i]>target) break;
        if(arr[i]==arr[i-1] && i>ind)   continue;
        ds.push_back(arr[i]);
        comb_sum_two(i+1, target-arr[i], arr, ds, ans);
        ds.pop_back();
    }
}

int main(){
    int n, k;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"Enter target: ";
    cin>>k;

    sort(arr.begin(), arr.end());
    vector<int> ds;
    vector<vector<int>> ans;
    comb_sum_two(0, k, arr, ds, ans);

    cout << "Combinations:\n";
    for (auto& vec : ans) {
        cout << "[ ";
        for (int val : vec) cout << val << " ";
        cout << "]\n";
    }

    return 0;
}
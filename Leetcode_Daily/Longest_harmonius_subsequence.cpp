#include <bits/stdc++.h>
using namespace std;

void findLHS(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int left=0;
    int res = 0;
    for(int right=0; right<nums.size(); right++){
        while (nums[right] - nums[left] > 1) 
            left++;

        if (nums[right] - nums[left] == 1) 
            res = max(res, right - left + 1);
    }
    cout<<res;    
}

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    findLHS(arr);
}
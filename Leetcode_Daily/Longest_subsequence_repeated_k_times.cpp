#include <bits/stdc++.h>
using namespace std;

string result = "";

bool isSubsequence(string &s, string &sub, int k){
    int i=0, j=0, L=sub.length(), n= s.length();
    while(i<n && j<k*L){
        if(s[i]==sub[j%L])
            j++;
        i++;
    }
    return j==k*L;
}

bool backtracking(string& s, string &curr, vector<bool>& canUse, vector<int>& requiredFreq, int k, int maxLen){
    if(curr.length()==maxLen){      // If length of subsequence is equal to maxLen
        if(isSubsequence(s, curr, k)){  // isSubsequence check whether the subsequence we get from this func occur k times in s
            result = curr;
            return true;
        }
        return false;
    }

    for(int i=25; i>=0; i--){   // Start making subsequence from last alphabet as we need lexographically large subsequence
        if(canUse[i] == false || requiredFreq[i]==0)
            continue;

        char ch = i+'a';
        curr.push_back(ch);
        requiredFreq[i]--;

        // If we got true we will not run further as we got our best answer, lexographically and length wise too
        if(backtracking(s, curr, canUse, requiredFreq, k, maxLen) == true)
            return true;
        
        curr.pop_back();
        requiredFreq[i]++;
    }
    return false;
}

string longestSubsequenceRepeatedK(string s, int k) {
    int n= s.length();

    // Frequency of each character in string
    int freq[26] = {};
    for(char &ch:s){
        freq[ch-'a']++;
    }
    
    // CanUse check whether a character can be used or not if freq is greater then k then it can be used else not
    vector<bool> canUse(26, false);
    // If a character can be used to make sub sequence then how much character will be used in each subsequence
    vector<int> requiredFreq(26, 0);
    for(int i=0; i<26; ++i){
        if(freq[i]>=k){
            canUse[i] = true;
            requiredFreq[i] = freq[i]/k;
        }
    }
    // Maximum length of subsequence that can be used
    int maxLen = n/k;

    //Starts from maxLen as we need to find longest subsequence it will reduce TC.
    for(int len=maxLen; len>=0; len--){
        vector<int> tempRequiredFreq = requiredFreq;
        // Curr is just empty string to add and remove char in backtracking
        string curr="";
        if(backtracking(s, curr, canUse, tempRequiredFreq, k, len) == true)
            return result;
    }
    return result;
}

int main(){
    cout<<"Enter the string: ";
    string s;
    cin>>s;
    cout<<"Enter value of k: ";
    int k;
    cin>>k;
    string  res= longestSubsequenceRepeatedK(s, k);
    cout<<res;
}
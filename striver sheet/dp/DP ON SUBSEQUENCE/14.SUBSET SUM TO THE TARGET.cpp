#include <bits/stdc++.h> 
bool solve(int ind,int target,vector<int> &arr){
    //base cases
    if(target==0)  return true;
    if(ind==0)  return arr[0]==target;
  
    bool nottake=solve(ind-1,target,arr);
    bool take=false;
    if(target>=arr[ind])
    take=solve(ind-1,target-arr[ind],arr);
    return  (take | nottake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return solve(n-1,k,arr);
}
//DP OR MEMOIZATION
#include <bits/stdc++.h> 
bool solve(int ind,int target,vector<int> &arr,vector<vector<int>>&dp){
    //base cases
    if(target==0)  return true;
    if(ind==0)  return arr[0]==target;
    if(dp[ind][target]!=-1)  return dp[ind][target];
    bool nottake=solve(ind-1,target,arr,dp);
    bool take=false;
    if(target>=arr[ind])
    take=solve(ind-1,target-arr[ind],arr,dp);
    return  dp[ind][target]=take | nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
}
//tabulation
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)  dp[i][0]=true;
    dp[0][arr[0]]=true;
    for (int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[ind-1][target];
            bool take=false;
            if(target>=arr[ind])
                take=dp[ind-1][target-arr[ind]];
           dp[ind][target]=take|nottake;
        }
    }
    return dp[n-1][k];
}
//TABULATION SPACE OPTIMIZATION
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool>prev(k+1,0),curr(k+1,0);
    prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for (int ind=1;ind<n;ind++){
        for(int target=1;target<=k;target++){
            bool nottake=prev[target];
            bool take=false;
            if(target>=arr[ind])
                take=prev[target-arr[ind]];
           curr[target]=take|nottake;
        }
        prev=curr;
    }
    return prev[k];
}
//normal recurence
#include <bits/stdc++.h> 
long solve(int ind,int *arr,int T,vector<vector<long>>&dp){
    if(ind==0)   return T%arr[0]==0;
    if(dp[ind][T]!=-1)  return dp[ind][T];
    long nottake=solve(ind-1,arr,T,dp);
    long take=0;
    if(arr[ind]<=T)  take=solve(ind,arr,T-arr[ind],dp);
    return dp[ind][T]=take+nottake;
}
long countWaysToMakeChange(int *arr, int n, int T)
{
    vector<vector<long>>dp(n,vector<long>(T+1,-1));
   return solve(n-1,arr,T,dp);
}
//dp memoization
#include <bits/stdc++.h> 
long solve(int ind,int *arr,int T,vector<vector<long>>&dp){
    if(ind==0)   return T%arr[0]==0;
    if(dp[ind][T]!=-1)  return dp[ind][T];
    long nottake=solve(ind-1,arr,T,dp);
    long take=0;
    if(arr[ind]<=T)  take=solve(ind,arr,T-arr[ind],dp);
    return dp[ind][T]=take+nottake;
}
long countWaysToMakeChange(int *arr, int n, int T)
{
    vector<vector<long>>dp(n,vector<long>(T+1,-1));
   return solve(n-1,arr,T,dp);
}
//tabulation
#include <bits/stdc++.h> 
long countWaysToMakeChange(int *arr, int n, int T)
{
    vector<vector<long>>dp(n,vector<long>(T+1,0));
    for(int t=0;t<=T;t++)   dp[0][t]=(t%arr[0]==0);
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=T;t++){
            long notake=dp[ind-1][t];
            long take=0;
            if(arr[ind]<=t)   take=dp[ind][t-arr[ind]];
            dp[ind][t]=take+notake;
        }
    }
   return dp[n-1][T];
}
//tabulation optimization
#include <bits/stdc++.h> 
long countWaysToMakeChange(int *arr, int n, int T)
{
    vector<long>prev(T+1,0),curr(T+1,0);
    for(int t=0;t<=T;t++)   prev[t]=(t%arr[0]==0);
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=T;t++){
            long notake=prev[t];
            long take=0;
            if(arr[ind]<=t)   take=curr[t-arr[ind]];
            curr[t]=take+notake;
        }
        prev=curr;
    }
   return prev[T];
}
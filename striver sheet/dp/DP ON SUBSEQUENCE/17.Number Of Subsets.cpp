//MY APPROCH----time limit exceed
#include <bits/stdc++.h> 
int solve(int ind,vector<int>&arr,int tar){
    if(tar==0)  return 1;
    if(ind==0 && arr[0]==tar)  return 1;
    if(ind==0 && arr[0]!=tar)  return 0;
    int nottake=solve(ind-1,arr,tar);
    int take=0;
    if(tar>=arr[ind])  take=solve(ind-1,arr,tar-arr[ind]);
    return take+nottake;
    
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    return solve(n-1,num,tar);

}
//correct solution
#include <bits/stdc++.h>  
int solve(int ind,vector<int>&arr,int tar,vector<vector<int>>&dp){
    if(ind==0){
        if(tar==0 && arr[0]==0)  return 2;
        if(tar==0 || tar==arr[0]) return 1;
        return 0;
    }

    if(dp[ind][tar]!=-1)   return dp[ind][tar]; 
    int nottake=solve(ind-1,arr,tar,dp);
    int take=0;
    if(tar>=arr[ind])  take=solve(ind-1,arr,tar-arr[ind],dp);
    return dp[ind][tar]=take+nottake;
    
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return solve(n-1,num,tar,dp);
}
//tabulation
#include <bits/stdc++.h> 
int findWays(vector<int> &arr, int tar)
{
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    for(int i=0;i<n;i++)   dp[i][0]=1;
    if(arr[0]<=tar)        dp[0][arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int s=0;s<=tar;s++){
            int nottake=dp[ind-1][s];
            int take=0;
            if(arr[ind]<=s) take=dp[ind-1][s-arr[ind]];
            dp[ind][s]=take+nottake;
        }
    }
    return dp[n-1][tar];
}
//tabulation space optimization
#include <bits/stdc++.h> 
int findWays(vector<int> &arr, int tar)
{
    int n=arr.size();
   vector<int>prev(tar+1,0),curr(tar+1,0);
   prev[0]=curr[0]=1;
   if(arr[0]<=tar) prev[arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int s=0;s<=tar;s++){
            int nottake=prev[s];
            int take=0;
            if(arr[ind]<=s) take=prev[s-arr[ind]];
            curr[s]=take+nottake;
        }
        prev=curr;
    }
    return prev[tar];
}
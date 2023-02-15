#include <bits/stdc++.h>
int solve(int ind,int prev_ind,int arr[],int n,vector<vector<int>>&dp){
    if(ind==n)   return 0;
    if(dp[ind][prev_ind+1]!=-1)   return dp[ind][prev_ind+1];
    int nottake=0+solve(ind+1,prev_ind,arr,n,dp);
    int take=0;
    if(prev_ind==-1 || arr[ind]>arr[prev_ind])
        take=1+solve(ind+1,ind,arr,n,dp);
    return dp[ind][prev_ind+1]=max(take,nottake);
}
int longestIncreasingSubsequence(int arr[], int n)
{  
   vector<vector<int>>dp(n,vector<int>(n+1,-1));
   return solve(0,-1,arr,n,dp);
}
//tabulation
#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n)
{  
   vector<int>next(n+1,0),curr(n+1,0);
   for(int ind=n-1;ind>=0;ind--){
       for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
   int len=0+next[prev_ind+1];
 
    if(prev_ind==-1 || arr[ind]>arr[prev_ind])
        len=max(len,1+next[ind+1]);
     curr[prev_ind+1]=len;
       }
       next=curr;
   }
   return next[-1+1];
}

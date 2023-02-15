//dp solution memoization
#include <bits/stdc++.h>
int mod=int(1e9+7);
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
    return dp[ind][tar]=(take+nottake) % mod;
    
}
int findWays(vector<int> &num, int tar)
{
    int n=num.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return solve(n-1,num,tar,dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
    for(int i=0;i<n;i++)
        totalsum+=arr[i];
    if(totalsum-d<0 || (totalsum-d)%2)    return false;
    return findWays(arr,(totalsum-d)/2);
}


//tabulation solution
#include <bits/stdc++.h>
int mod=int(1e9+7);
int findWays(vector<int> &arr, int tar)
{
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,0));
    if(arr[0]==0) dp[0][0]=2;                 //these base case is here because to handle the number of zeores in the subset.
    else dp[0][0]=1;
    //arr[0]=0
    if(arr[0]!=0 && arr[0]<=tar)  dp[0][arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int s=0;s<=tar;s++){
            int nottake=dp[ind-1][s];
            int take=0;
            if(arr[ind]<=s) take=dp[ind-1][s-arr[ind]];
            dp[ind][s]=(take+nottake) % mod;
        }
    }
    return dp[n-1][tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
    for(int i=0;i<n;i++)
        totalsum+=arr[i];
    if(totalsum-d<0 || (totalsum-d)%2)    return false;
    return findWays(arr,(totalsum-d)/2);
}

//tabulation space optimization
#include <bits/stdc++.h>
int mod=int(1e9+7);
int findWays(vector<int> &arr, int tar)
{
    int n=arr.size();
   vector<int>prev(tar+1,0),curr(tar+1,0);
    if(arr[0]==0) prev[0]=2;
    else prev[0]=1;
    //arr[0]=0
    if(arr[0]!=0 && arr[0]<=tar)  prev[arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int s=0;s<=tar;s++){
            int nottake=prev[s];
            int take=0;
            if(arr[ind]<=s) take=prev[s-arr[ind]];
            curr[s]=(take+nottake) % mod;
        }
        prev=curr;
    }
    return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
    for(int i=0;i<n;i++)
        totalsum+=arr[i];
    if(totalsum-d<0 || (totalsum-d)%2)    return false;
    return findWays(arr,(totalsum-d)/2);
}





//normal#include <bits/stdc++.h> 
int solve(int ind,int T,vector<int>&arr){
    if(ind==0){
        if(T%arr[0]==0)   return T/arr[0];
        return 1e9;
    }
    int nottake=0+solve(ind-1,T,arr);
    int take=INT_MAX;
    if(arr[ind]<=T) take=1+solve(ind,T-arr[ind],arr);
    return min(take,nottake);
}
int minimumElements(vector<int> &num, int x)
{   int n=num.size();
   int ans=solve(n-1,x,num);
 if(ans>=1e9) return -1;
 return ans;
}
//dp or memoization top down
#include <bits/stdc++.h> 
int solve(int ind,int T,vector<int>&arr,vector<vector<int>>&dp){
    if(ind==0){
        if(T%arr[0]==0)   return T/arr[0];
        return 1e9;
    }
    if(dp[ind][T]!=-1)    return dp[ind][T];
    int nottake=0+solve(ind-1,T,arr,dp);
    int take=INT_MAX;
    if(arr[ind]<=T) take=1+solve(ind,T-arr[ind],arr,dp);
    return dp[ind][T]=min(take,nottake);
}
int minimumElements(vector<int> &num, int x)
    {  
     int n=num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));
     int ans=solve(n-1,x,num,dp);
     if(ans>=1e9) return -1;
     return ans;
}
//tabulation
#include <bits/stdc++.h> 
int minimumElements(vector<int> &arr, int x)
    {  
     int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(x+1,0));
    for(int t=0;t<=x;t++){
        if(t%arr[0]==0)  dp[0][t]=t/arr[0];
        else dp[0][t]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=x;T++){
            int nottake=0+dp[ind-1][T];
            int take=INT_MAX;
            if(arr[ind]<=T) take=1+dp[ind][T-arr[ind]];
            dp[ind][T]=min(take,nottake);
        }
    }
     int ans=dp[n-1][x];
     if(ans>=1e9) return -1;
     return ans;
//tabulation optimization
#include <bits/stdc++.h> 
int minimumElements(vector<int> &arr, int x)
    {  
     int n=arr.size();
    vector<int>prev(x+1,0),curr(x+1,0);
    for(int t=0;t<=x;t++){
        if(t%arr[0]==0)  prev[t]=t/arr[0];
        else prev[t]=1e9;
    }
    for(int ind=1;ind<n;ind++){
        for(int T=0;T<=x;T++){
            int nottake=0+prev[T];
            int take=INT_MAX;
            if(arr[ind]<=T) take=1+curr[T-arr[ind]];
           curr[T]=min(take,nottake);
        }
        prev=curr;
    }
     int ans=prev[x];
     if(ans>=1e9) return -1;
     return ans;
}
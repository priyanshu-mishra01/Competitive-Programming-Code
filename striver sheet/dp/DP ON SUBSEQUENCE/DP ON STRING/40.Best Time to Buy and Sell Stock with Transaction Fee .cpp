#include <bits/stdc++.h> 
int solve(int ind,int buy,vector<int>&values,int n,int fee,vector<vector<int>>&dp){
    if(ind==n)  return 0;
    int profit=0;
    if(dp[ind][buy]!=-1)   return dp[ind][buy];
    if(buy)    profit=max(-values[ind]+solve(ind+1,0,values,n,fee,dp),0+solve(ind+1,1,values,n,fee,dp));
    else profit =max(values[ind]-fee+solve(ind+1,1,values,n,fee,dp),0+solve(ind+1,0,values,n,fee,dp));
      return dp[ind][buy]=profit;
    
}
int maximumProfit(int n, int fee, vector<int> &prices) {
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return solve(0,1,prices,n,fee,dp);
}
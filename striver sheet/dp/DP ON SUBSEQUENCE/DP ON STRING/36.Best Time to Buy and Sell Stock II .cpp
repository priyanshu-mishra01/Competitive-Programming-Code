 #include <bits/stdc++.h>
long solve(int ind,int buy,long *values,int n,vector<vector<long>>&dp){
    if(ind==n)  return 0;
    long profit=0;
    if(dp[ind][buy]!=-1)   return dp[ind][buy];
    if(buy)    profit=max(-values[ind]+solve(ind+1,0,values,n,dp),0+solve(ind+1,1,values,n,dp));
    else profit =max(values[ind]+solve(ind+1,1,values,n,dp),0+solve(ind+1,0,values,n,dp));
      return dp[ind][buy]=profit;
    
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>>dp(n,vector<long>(2,-1));
    return solve(0,1,values,n,dp);
}
//tabulation
#include <bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>>dp(n+1,vector<long>(2,0));
    dp[n][0]=dp[n][1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
        long profit=0;
 if(buy)    profit=max(-values[ind]+dp[ind+1][0],dp[ind+1][1]);
    else profit =max(values[ind]+dp[ind+1][1],dp[ind+1][0]);
     dp[ind][buy]=profit;
        }
    }
    return dp[0][1];
}
//tabulation optimization
#include <bits/stdc++.h>
long getMaximumProfit(long *values, int n)
{
    vector<long>prev(2,0),curr(2,0);
    prev[0]=prev[1]=0;
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<=1;buy++){
        long profit=0;
 if(buy)    profit=max(-values[ind]+prev[0],prev[1]);
    else profit =max(values[ind]+prev[1],prev[0]);
     curr[buy]=profit;
        }
        prev=curr;
    }
    return prev[1];
}
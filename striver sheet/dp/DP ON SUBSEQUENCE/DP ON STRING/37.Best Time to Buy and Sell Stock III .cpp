//dp
#include <bits/stdc++.h> 
int solve(int ind,int buy,int cap,vector<int>&values,int n,vector<vector<vector<int>>>&dp){
    if(ind==n || cap==0)  return 0;
    if(dp[ind][buy][cap]!=-1)   return dp[ind][buy][cap];
    if(buy==1)    
return dp[ind][buy][cap]=max(-values[ind]+solve(ind+1,0,cap,values,n,dp),0+solve(ind+1,1,cap,values,n,dp));
    else return dp[ind][buy][cap]=max(values[ind]+solve(ind+1,1,cap-1,values,n,dp),0+solve(ind+1,0,cap,values,n,dp));

    
}
int maxProfit(vector<int>& prices, int n)
{
   vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,1,2,prices,n,dp);
}
//tabulation
#include <bits/stdc++.h>  

int maxProfit(vector<int>& values, int n)
{
   vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
  for(int ind=n-1;ind>=0;ind--){
      for(int buy=0;buy<=1;buy++){
          for(int cap=1;cap<=2;cap++){
              if(buy==1)    
dp[ind][buy][cap]=max(-values[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
else dp[ind][buy][cap]=max(values[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);

          }
      }
  }
    return dp[0][1][2];
}
//optimization
#include <bits/stdc++.h>  

int maxProfit(vector<int>& values, int n)
{
   vector<vector<int>>prev(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
  for(int ind=n-1;ind>=0;ind--){
      for(int buy=0;buy<=1;buy++){
          for(int cap=1;cap<=2;cap++){
              if(buy==1)    
curr[buy][cap]=max(-values[ind]+prev[0][cap],0+prev[1][cap]);
else curr[buy][cap]=max(values[ind]+prev[1][cap-1],0+prev[0][cap]);

          }
      }
      prev=curr;
  }
    return prev[1][2];
}
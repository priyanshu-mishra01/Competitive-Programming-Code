//dp
class Solution {
public:
    int solve(int ind,int buy,int n,vector<int>&val,vector<vector<int>>&dp){
        if(ind>=n)  return 0;
        if(dp[ind][buy]!=-1)   return dp[ind][buy];
        if(buy)
        return dp[ind][buy]=max(-val[ind]+solve(ind+1,0,n,val,dp),solve(ind+1,1,n,val,dp));
        else
        return dp[ind][buy]=max(val[ind]+solve(ind+2,1,n,val,dp),solve(ind+1,0,n,val,dp));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,n,prices,dp);
    }
};
//tabulation
class Solution {
public:

    int maxProfit(vector<int>& val) {
        int n=val.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
        if(buy)
        dp[ind][buy]=max(-val[ind]+dp[ind+1][0],dp[ind+1][1]);
        else
      dp[ind][buy]=max(val[ind]+dp[ind+2][1],dp[ind+1][0]);
                
            }
        }
        return dp[0][1];
    }
};
//tabulation optimization
class Solution {
public:

    int maxProfit(vector<int>& val) {
        int n=val.size();
        vector<int>prev1(2,0),prev2(2,0),curr(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
        if(buy)
       curr[buy]=max(-val[ind]+prev1[0],prev1[1]);
        else
      curr[buy]=max(val[ind]+prev2[1],prev1[0]);
                
            }
            prev2=prev1;
            prev1=curr;
        }
        return prev1[1];
    }
};
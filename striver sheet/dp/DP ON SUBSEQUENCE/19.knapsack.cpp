#include <bits/stdc++.h> 
int f(int ind,int W,vector<int>&wt,vector<int>&val,vector<vector<int>>&dp){
    if(ind==0){
        if(wt[0]<=W)  return val[0];
        return 0;
    }
    if(dp[ind][W]!=-1) return dp[ind][W];
    int nottake=0+f(ind-1,W,wt,val,dp);
    int take=-1e8;
    if(wt[ind]<=W)   take=val[ind]+f(ind-1,W-wt[ind],wt,val,dp);
    return dp[ind][W]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}
//tabulation
#include <bits/stdc++.h> 

int knapsack(vector<int> wt, vector<int> value, int n, int maxWeight) 
{   vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));
	for(int w=wt[0];w<=maxWeight;w++)  dp[0][w]=value[0];
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int nottake=0+dp[ind-1][W];
            int take=INT_MIN;
            if(wt[ind]<=W){
                take=value[ind]+dp[ind-1][W-wt[ind]];
            }
            dp[ind][W]=max(take,nottake);
        }
    }
 return dp[n-1][maxWeight];
}
//tabulation optimization
#include <bits/stdc++.h> 

int knapsack(vector<int> wt, vector<int> value, int n, int maxWeight) 
{  vector<int>prev(maxWeight+1,0),curr(maxWeight+1,0);
	for(int w=wt[0];w<=maxWeight;w++)  prev[w]=value[0];
    for(int ind=1;ind<n;ind++){
        for(int W=0;W<=maxWeight;W++){
            int nottake=0+prev[W];
            int take=INT_MIN;
            if(wt[ind]<=W){
                take=value[ind]+prev[W-wt[ind]];
            }
            curr[W]=max(take,nottake);
        }
        prev=curr;
    }
 return prev[maxWeight];
}
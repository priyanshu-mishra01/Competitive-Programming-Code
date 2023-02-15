//normal
//Unbounded Knapsack 
#include <bits/stdc++.h> 
int solve(int ind,int maxw,vector<int>&val,vector<int>&wt){
    if(ind==0){
        if(wt[0]<=maxw)   return ((int)(maxw/wt[0]))*val[0];
        return 0;
    }
    int nottake=solve(ind-1,maxw,val,wt);
    int take=-1e9;
    if(wt[ind]<=maxw)   take=val[ind]+solve(ind,maxw-wt[ind],val,wt);
    return max(take,nottake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return solve(n-1,w,profit,weight);
}
//dp
#include <bits/stdc++.h> 
int solve(int ind,int maxw,vector<int>&val,vector<int>&wt, vector<vector<int>>&dp){
    if(ind==0){
        if(wt[0]<=maxw)   return ((int)(maxw/wt[0]))*val[0];
        return 0;
    }
    if(dp[ind][maxw]!=-1)    return dp[ind][maxw];
    int nottake=solve(ind-1,maxw,val,wt,dp);
    int take=-1e9;
    if(wt[ind]<=maxw)   take=val[ind]+solve(ind,maxw-wt[ind],val,wt,dp);
    return dp[ind][maxw]=max(take,nottake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{   vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return solve(n-1,w,profit,weight,dp);
}
//tabulation
#include <bits/stdc++.h> 
int unboundedKnapsack(int n, int maxw, vector<int> &val, vector<int> &wt)
{   vector<vector<int>>dp(n,vector<int>(maxw+1,0));
    for(int w=0;w<=maxw;w++)  dp[0][w]=((int)(w/wt[0]))*val[0];
    for(int ind=1;ind<n;ind++)
        {
            for(int w=0;w<=maxw;w++){
                int nottake=dp[ind-1][w];
                int take=-1e9;
                if(wt[ind]<=w)  
                    take=val[ind]+dp[ind][w-wt[ind]];
                dp[ind][w]=max(take,nottake);
                        }
          }
        return dp[n-1][maxw];
        
        }   

//tabulation optimization
#include <bits/stdc++.h> 
int unboundedKnapsack(int n, int maxw, vector<int> &val, vector<int> &wt)
{   vector<int>prev(maxw+1,0),curr(maxw+1,0);
    for(int w=0;w<=maxw;w++)  prev[w]=((int)(w/wt[0]))*val[0];
    for(int ind=1;ind<n;ind++)
        {
            for(int w=0;w<=maxw;w++){
                int nottake=prev[w];
                int take=-1e9;
                if(wt[ind]<=w)  
                    take=val[ind]+curr[w-wt[ind]];
                curr[w]=max(take,nottake);
                        }
        prev=curr;
          }
        return prev[maxw];
        
        }   


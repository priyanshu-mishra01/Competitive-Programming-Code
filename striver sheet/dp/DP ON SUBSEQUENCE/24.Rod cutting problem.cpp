#include <bits/stdc++.h>
 int solve(int ind,int N,vector<int>&val){
     if(ind ==0)  return N*val[0];
     int nottake=solve(ind-1,N,val);
     int take=INT_MIN;
     int rodlength=ind+1;
     if(rodlength<=N)  take=val[ind]+solve(ind,N-rodlength,val);
     return max(take,nottake);
 }

int cutRod(vector<int> &price, int n)
{
	return solve(n-1,n,price);
}

//dp
#include <bits/stdc++.h>
 int solve(int ind,int N,vector<int>&val,vector<vector<int>>&dp){
     if(ind ==0)  return N*val[0];
     if(dp[ind][N]!=-1) return dp[ind][N];
     int nottake=solve(ind-1,N,val,dp);
     int take=INT_MIN;
     int rodlength=ind+1;
     if(rodlength<=N)  take=val[ind]+solve(ind,N-rodlength,val,dp);
     return dp[ind][N]=max(take,nottake);
 }

int cutRod(vector<int> &price, int n)
{   vector<vector<int>>dp(n,vector<int>(n+1,-1));
	return solve(n-1,n,price,dp);
}

//tabulation
#include <bits/stdc++.h>
int cutRod(vector<int> &val, int n)
{   
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    for(int i=0;i<=n;i++)  dp[0][i]=i*val[0];
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
             int nottake=dp[ind-1][N];
             int take=INT_MIN;
             int rodlength=ind+1;
             if(rodlength<=N)  take=val[ind]+dp[ind][N-rodlength];
             dp[ind][N]=max(take,nottake);
        }
    }
	return dp[n-1][n];
}
//tabulation optimized
#include <bits/stdc++.h>
int cutRod(vector<int> &val, int n)
{   
    vector<int>prev(n+1,0),curr(n+1,0);
    for(int i=0;i<=n;i++) prev[i]=i*val[0];
    for(int ind=1;ind<n;ind++){
        for(int N=0;N<=n;N++){
             int nottake=prev[N];
             int take=INT_MIN;
             int rodlength=ind+1;
             if(rodlength<=N)  take=val[ind]+curr[N-rodlength];
             curr[N]=max(take,nottake);
        }
        prev=curr;
    }
	return prev[n];
}

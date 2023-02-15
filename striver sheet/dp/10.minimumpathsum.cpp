//normal dp
#include <bits/stdc++.h>
int solve(int i,int j,vector<vector<int>>&grid){
    if(i==0 && j==0)  return grid[0][0];
    if(i<0  || j<0)    return 1e9;
    int up=grid[i][j]+solve(i-1,j,grid);
    int left=grid[i][j]+solve(i,j-1,grid);
    return min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    return solve(n-1,m-1,grid);
}
//1 D DP
#include <bits/stdc++.h>
int solve(int i,int j,vector<vector<int>>&grid, vector<vector<int>>&dp){
    
    if(i==0 && j==0)  return grid[0][0];
    if(i<0  || j<0)    return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=grid[i][j]+solve(i-1,j,grid,dp);
    int left=grid[i][j]+solve(i,j-1,grid,dp);
    return dp[i][j]=min(up,left);
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,grid,dp);
}
//tabulation
#include <bits/stdc++.h>

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)  dp[i][j]=grid[i][j];
            else{
            int up=grid[i][j];
            if(i>0)
              up+=dp[i-1][j];
            else
                up+=1e9;
            int left=grid[i][j];
            if(j>0) 
                left+=dp[i][j-1];
            else    
                left+=1e9;
            dp[i][j]=min(up,left);
            }
        }
    }
    return dp[n-1][m-1];
}
//tabulation space optimization
#include <bits/stdc++.h>

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
            if(i==0 && j==0)  curr[j]=grid[i][j];
            else{
            int up=grid[i][j];
            if(i>0)
                //requiring previous row's j column
              up+=prev[j];
            else
                up+=1e9;
            int left=grid[i][j];
            if(j>0) 
                //current row's j-1 column
                left+=curr[j-1];
            else    
                left+=1e9;
            curr[j]=min(up,left);
            }
        }
        prev=curr;
    }
    return prev[m-1];
}
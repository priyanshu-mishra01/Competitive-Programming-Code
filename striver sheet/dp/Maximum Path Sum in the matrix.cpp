#include <bits/stdc++.h> 
int solve(int n,int m,vector<vector<int>>&matrix){
   
    if(m<0 || m>=matrix[0].size())  return -1e8;
     if(n==0)  return matrix[0][m];   
    int straight=matrix[n][m]+solve(n-1,m,matrix);
    int leftdiagonal=matrix[n][m]+solve(n-1,m-1,matrix);
    int rightdiagonal=matrix[n][m]+solve(n-1,m+1,matrix);
    return max(straight,max(rightdiagonal,leftdiagonal));        //TC==3**N
                                                                 //SC==0(N)
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
  int n=matrix.size();
  int m=matrix[0].size();
  int maxi=-1e8;
  for(int i=0;i<m;i++){
      maxi=max(maxi,solve(n-1,i,matrix));
  }  
    return maxi;
}
//dp
#include <bits/stdc++.h> 
int solve(int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp){
   
    if(m<0 || m>=matrix[0].size())  return -1e8;
     if(n==0)  return matrix[0][m]; 
    if(dp[n][m]!=-1)    return dp[n][m];
    int straight=matrix[n][m]+solve(n-1,m,matrix,dp);
    int leftdiagonal=matrix[n][m]+solve(n-1,m-1,matrix,dp);
    int rightdiagonal=matrix[n][m]+solve(n-1,m+1,matrix,dp);
    return dp[n][m]=max(straight,max(rightdiagonal,leftdiagonal));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
  int n=matrix.size();
  int m=matrix[0].size();
  int maxi=-1e8;
  vector<vector<int>>dp(n,vector<int>(m,-1));
  for(int i=0;i<m;i++){
      maxi=max(maxi,solve(n-1,i,matrix,dp));
  }  
    return maxi;
}
//tabulation
#include <bits/stdc++.h> 
int getMaxPathSum(vector<vector<int>> &matrix)
{
  int n=matrix.size();
  int m=matrix[0].size();
  int maxi=-1e8;
  vector<vector<int>>dp(n,vector<int>(m,0));
    for(int i=0;i<m;i++)   dp[0][i]=matrix[0][i];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int st=matrix[i][j]+dp[i-1][j];
            int ld=matrix[i][j];
            if(j-1>=0) ld+=dp[i-1][j-1];
            else ld+=-1e8;
            int rd=matrix[i][j];
            if(j+1<m) rd+=dp[i-1][j+1];
            else rd+=-1e8;
            dp[i][j]=max(st,max(ld,rd));
        }
    }
  for(int i=0;i<m;i++){
      maxi=max(maxi,dp[n-1][i]);
  }  
    return maxi;
}
//TABULATION SPACE OPTIMIZATION
#include <bits/stdc++.h> 
int getMaxPathSum(vector<vector<int>> &matrix)
{
  int n=matrix.size();
  int m=matrix[0].size();
  int maxi=-1e8;
  vector<int>prev(m,0);
  vector<int>curr(m,0);
    for(int i=0;i<m;i++)   prev[i]=matrix[0][i];
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int st=matrix[i][j]+prev[j];
            int ld=matrix[i][j];
            if(j-1>=0) ld+=prev[j-1];
            else ld+=-1e8;
            int rd=matrix[i][j];
            if(j+1<m) rd+=prev[j+1];
            else rd+=-1e8;
             curr[j]=max(st,max(ld,rd));
        }
        prev=curr;
    }
  for(int i=0;i<m;i++){
      maxi=max(maxi,prev[i]);
  }  
    return maxi;
}
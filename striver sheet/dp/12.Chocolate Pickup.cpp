//noramal
#include <bits/stdc++.h> 
int solve(int i,int j1,int j2,int c,int r,vector<vector<int>>&grid){
    //base cases
    //outer bound cases
    if(j1<0 || j1>=c|| j2<0 || j2>=c)
        return -1e8;
    //destination base case
    if(i==r-1 ){
        if(j1==j2)  return grid[i][j1];
        else        return grid[i][j1]+grid[i][j2];
    }
    //EXPLORE ALL THE PATHS simultaneously
    //dj1==alice possibly to move,for ever possible move of alice bob have 3 posssible ways to move(dj2).
    int maxi=0;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++)
        {  int value=0;
            if(j1==j2) value=grid[i][j1]; 
            else  value=grid[i][j1]+grid[i][j2];
   value+=solve(i+1,j1+dj1,j2+dj2,c,r,grid);
     maxi=max(maxi,value); 
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
   return solve(0,0,c-1,c,r,grid);
}
//dp OR MOEMOIZATION
#include <bits/stdc++.h> 
int solve(int i,int j1,int j2,int c,int r,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    //base cases
    //outer bound cases
    if(j1<0 || j1>=c|| j2<0 || j2>=c)
        return -1e8;
    //destination base case
    if(i==r-1 ){
        if(j1==j2)  return grid[i][j1];
        else        return grid[i][j1]+grid[i][j2];
    }
    //EXPLORE ALL THE PATHS simultaneously
    //dj1==alice possibly to move,for ever possible move of alice bob have 3 posssible ways to move(dj2).
    if(dp[i][j1][j2]!=-1)  return dp[i][j1][j2];
    int maxi=0;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++)
        {  int value=0;
            if(j1==j2) value=grid[i][j1]; 
            else  value=grid[i][j1]+grid[i][j2];
   value+=solve(i+1,j1+dj1,j2+dj2,c,r,grid,dp);
     maxi=max(maxi,value); 
        }
    }
    return dp[i][j1][j2] =maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
   // INT DP[R][C][C];
 vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
   return solve(0,0,c-1,c,r,grid,dp);
}
//TBULATION
#include <bits/stdc++.h> 
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
   // INT DP[R][C][C];
 vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
    //BASE CASE
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
            else       dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                  int maxi=-1e8;
                 for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){  
                        int value=0;
                        if(j1==j2) value=grid[i][j1]; 
                        else  value=grid[i][j1]+grid[i][j2];
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m  ) value+=dp[i+1][j1+dj1][j2+dj2];
                        else value+=-1e8;
                       maxi=max(maxi,value); 
        }
    }
    dp[i][j1][j2] =maxi;
            
            }
        }
    }
   return dp[0][0][m-1];
}


//tabulation  space optmization
#include <bits/stdc++.h> 
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
   // INT DP[R][C][C];
 vector<vector<int>>front(m,vector<int>(m,0));
 vector<vector<int>>curr(m,vector<int>(m,0));
    //BASE CASE
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            if(j1==j2) front[j1][j2]=grid[n-1][j1];
            else  front[j1][j2]=grid[n-1][j1]+grid[n-1][j2];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                  int maxi=-1e8;
                 for(int dj1=-1;dj1<=1;dj1++){
                    for(int dj2=-1;dj2<=1;dj2++){  
                        int value=0;
                        if(j1==j2) value=grid[i][j1]; 
                        else  value=grid[i][j1]+grid[i][j2];
                        if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m  ) value+=front[j1+dj1][j2+dj2];
                        else value+=-1e8;
                       maxi=max(maxi,value); 
        }
    }
    curr[j1][j2] =maxi;
            
            }
        }
         front=curr;
    }
   return front[0][m-1];
}
int mod=(int)(1000000000+7);
int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&mat){
    if(i==0 && j==0)   return 1;
    if(i<0 || j<0)     return 0;
    if(i>=0 && j>=0 && mat[i][j]==-1)    return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=0,left=0;
    if(i>0) up=solve(i-1,j,dp,mat);
    if(j>0) left=solve(i,j-1,dp,mat);
    dp[i][j]=(up+left)%mod;
    return dp[i][j];
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
   vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,dp,mat);
}
//tabulation
int mod=(int)(1000000000+7);


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
   vector<vector<int>>dp(n,vector<int>(m,-1));
    dp[0][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==0)  continue;
            if(i>=0 && j>=0 && mat[i][j]==-1 ) dp[i][j]=0;
            else{
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=(up+left)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}
//talbulation space optimization
int mod=(int)(1000000000+7);
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
   vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int>curr(m,0);
        for(int j=0;j<m;j++){
         if(mat[i][j]==-1 ) curr[j]=0;
         else if(i==0 && j==0)  curr[j]=1;
            else{
                int up=0,left=0;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];
                curr[j]=(up+left)%mod;
            }
        }
        prev=curr;
    }
    return prev[m-1];
}
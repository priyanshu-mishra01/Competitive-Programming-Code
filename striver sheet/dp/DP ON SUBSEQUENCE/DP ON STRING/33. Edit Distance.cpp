class Solution {
public:
    int solve(int i,int j,string &w1,string &w2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0)   return i+1;
        if(dp[i][j]!=-1)  return dp[i][j];
        if(w1[i]==w2[j])  return dp[i][j]=solve(i-1,j-1,w1,w2,dp);
        else return  dp[i][j]=1+min(solve(i,j-1,w1,w2,dp),min(solve(i-1,j,w1,w2,dp),solve(i-1,j-1,w1,w2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,word1 ,word2,dp);
        
    }
};
//different base cases
class Solution {
public:
    int solve(int i,int j,string &w1,string &w2,vector<vector<int>>&dp){
        if(i==0) return j;
        if(j==0)   return i;            //base cases are different
        if(dp[i][j]!=-1)  return dp[i][j];
        if(w1[i-1]==w2[j-1])  return dp[i][j]=solve(i-1,j-1,w1,w2,dp);
        else return  dp[i][j]=1+min(solve(i,j-1,w1,w2,dp),min(solve(i-1,j,w1,w2,dp),solve(i-1,j-1,w1,w2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,word1 ,word2,dp);
        
    }
};
//tabulation
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
        if(w1[i-1]==w2[j-1]) dp[i][j]=dp[i-1][j-1];
        else   dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
        return dp[n][m];
        
    }
};
//tabulation optimization
class Solution {
public:
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=j;
       
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
        if(w1[i-1]==w2[j-1]) curr[j]=prev[j-1];
        else   curr[j]=1+min(curr[j-1],min(prev[j],prev[j-1]));
            }
            prev=curr;
        }
        return prev[m];
        
    }
};
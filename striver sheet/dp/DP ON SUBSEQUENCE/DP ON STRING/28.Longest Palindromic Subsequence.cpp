//dp or memoization
class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0 || j<0)   return 0;
        if(dp[i][j]!=-1)  return dp[i][j];
        if(s1[i]==s2[j])  return dp[i][j]= 1+solve(i-1,j-1,s1,s2,dp);
        else return dp[i][j]=max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
        
    }
    int longestPalindromeSubseq(string str1) {
        string str2(str1);
        reverse(str2.begin(), str2.end()); 
        int n=str1.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n-1,str1,str2,dp);
    }
};
//tabulation
class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0 || j<0)   return 0;
        if(dp[i][j]!=-1)  return dp[i][j];
        if(s1[i]==s2[j])  return dp[i][j]= 1+solve(i-1,j-1,s1,s2,dp);
        else return dp[i][j]=max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
        
    }
    int longestPalindromeSubseq(string str1) {
        string str2(str1);
        reverse(str2.begin(), str2.end()); 
        int n=str1.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(n-1,n-1,str1,str2,dp);
    }
};
//tabulatioon optimizatiuon
class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2(s1);
        reverse(s2.begin(), s2.end()); 
        int n=s1.size();
       vector<int>prev(n+1,0),curr(n+1,0);
        for(int i=0;i<=n;i++) prev[i]=0;
        for(int j=0;j<=n;j++)  prev[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
        if(s1[i-1]==s2[j-1])  curr[j]= 1+prev[j-1];
        else curr[j]=max(prev[j],curr[j-1]);
                
            }
            prev=curr;
        }
        return prev[n];
    }
};
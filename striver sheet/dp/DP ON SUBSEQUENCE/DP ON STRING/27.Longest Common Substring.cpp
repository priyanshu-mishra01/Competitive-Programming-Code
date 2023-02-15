//minute change from subsequence  problem, we have cahnhe onle else condition dp[i][j]=0
// we cange it becasue the substring are in consecutimve format so not depend on the previous block of the tabulation.
#include <bits/stdc++.h> 
int lcs(string &s, string &t){
	int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int j=0; j<=m; j++) dp[0][j]=0;
    for(int i=0; i<=n; i++) dp[i][0]=0;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=0;
              ans=max(ans,dp[i][j]);
        }
      
    }
   
return ans;
}
//tabulatiuon optimization
#include <bits/stdc++.h> 
int lcs(string &s, string &t){
	int n=s.size();
    int m=t.size();
   vector<int>prev(m+1,0),curr(m+1,0);
    for(int j=0; j<=m; j++) prev[j]=0;
    for(int i=0; i<=n; i++) prev[0]=0;
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(s[i-1]==t[j-1])
                curr[j]=1+prev[j-1];
            else
               curr[j]=0;
              ans=max(ans,curr[j]);
        }
        prev=curr;
      
    }
   
return ans;
}


#include <bits/stdc++.h>
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
int minInsertion(string &str)
{
    return str.size()-longestPalindromeSubseq(str);
}
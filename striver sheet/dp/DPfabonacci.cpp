#include <bits/stdc++.h>
using namespace std;
int fab(int n,vector<int>&dp){
    if(n<=1)
        return n;
    if (dp[n]!=-1)
        return dp[n];
    return dp[n]=fab(n-1,dp)+fab(n-2,dp);
}
int main(){
    int n=5;
    vector<int>dp(n+1,-1);
    cout<<fab(n,dp);
    return 0;
}
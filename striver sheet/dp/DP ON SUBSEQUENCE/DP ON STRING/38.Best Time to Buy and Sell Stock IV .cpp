#include <bits/stdc++.h> 
int maximumProfit(vector<int> &values, int n, int k)
{ 
   vector<vector<int>>prev(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
  for(int ind=n-1;ind>=0;ind--){
      for(int buy=0;buy<=1;buy++){
          for(int cap=1;cap<=k;cap++){
              if(buy==1)    
curr[buy][cap]=max(-values[ind]+prev[0][cap],0+prev[1][cap]);
else curr[buy][cap]=max(values[ind]+prev[1][cap-1],0+prev[0][cap]);

          }
      }
      prev=curr;
  }
    return prev[1][k];
    // Write your code here.
}
#include <bits/stdc++.h> 
int solve(int ind,vector<int> &nums){
    if(ind==0)    return nums[ind];
    if(ind<0)     return 0;
    int pick=nums[ind]+solve(ind-2,nums);
    int notpick=0+solve(ind-1,nums);
    
    return max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return solve(n,nums);
}

//TABULATION FORMAT
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int take=nums[i]; 
        if(i>1)  take+=dp[i-2];
        int nottake=0+dp[i-1];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
}
//tabulation optimization means space optimation

#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int p1=nums[0];
    int p2=0;
    for(int i=1;i<n;i++){
        int take=nums[i]; 
        if(i>1)  take+=p2;
        int nottake=0+p1;
        int cur=max(take,nottake);
        p2=p1;
        p1=cur;
    }
  return p1 ;
}
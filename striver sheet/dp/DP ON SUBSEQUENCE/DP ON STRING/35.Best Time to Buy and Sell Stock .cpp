#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n=prices.size();
        int profit=0;
        int mini=prices[0];
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            if(cost>0)
                profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
}
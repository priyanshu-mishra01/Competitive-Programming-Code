//THE LOGIC OF THIS QUESTION IS SAME AS THE PARTIION DIFFERENCE SO THE CODE IS SAME ,THE D OF PARTITION DIFFERENCE IS THE TARGET IN THIS QUESTION
//APPLY SAME LOGIC WE HAVE TO DIVIDE THE ARRAY IN TOW DIFFERENT SUBSETS.
 
#include <bits/stdc++.h> 
int findWays(vector<int> &arr, int tar)
{
    int n=arr.size();
   vector<int>prev(tar+1,0),curr(tar+1,0);
    if(arr[0]==0) prev[0]=2;
    else prev[0]=1;
    //arr[0]=0
    if(arr[0]!=0 && arr[0]<=tar)  prev[arr[0]]=1;
    for(int ind=1;ind<n;ind++){
        for(int s=0;s<=tar;s++){
            int nottake=prev[s];
            int take=0;
            if(arr[ind]<=s) take=prev[s-arr[ind]];
            curr[s]=(take+nottake);
        }
        prev=curr;
    }
    return prev[tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int totalsum=0;
    for(int i=0;i<n;i++)
        totalsum+=arr[i];
    if(totalsum-d<0 || (totalsum-d)%2)    return false;
    return findWays(arr,(totalsum-d)/2);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions( n,target,arr);
}

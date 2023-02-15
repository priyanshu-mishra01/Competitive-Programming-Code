class Solution {
public:

void solve(int ind ,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int tar){
    if(tar==0){
        ans.push_back(ds);
        return ;
            }
    for(int i=ind;i<arr.size();i++)
{
    if(i>ind && arr[i]==arr[i-1]){
        continue;
    }
    if(tar<arr[i]){
        break;
    }
    ds.push_back(arr[i]);
    solve(i+1,arr,ans,ds,tar-arr[i]);
    ds.pop_back();

}


}
    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        sort(arr.begin(),arr.end());
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,arr,ans,ds,tar);
        return ans;
        
    }
};
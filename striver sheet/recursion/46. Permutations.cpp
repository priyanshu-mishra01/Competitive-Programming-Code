class Solution {
public:
void solve(vector<int>&nums,vector<int>&ds,vector<int>&freq,vector<vector<int>>&ans){
    if(ds.size()==nums.size()){
        ans.push_back(ds);
        return ;
    }
    for(int i=0;i<nums.size();i++){
        if(!freq[i]){
            freq[i]=1;
            ds.push_back(nums[i]);
            solve(nums,ds,freq,ans);
            freq[i]=0;
           ds.pop_back();
       
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        vector<int>freq(nums.size(),0);
        
        solve(nums,ds,freq,ans);
        return ans;
    }
};
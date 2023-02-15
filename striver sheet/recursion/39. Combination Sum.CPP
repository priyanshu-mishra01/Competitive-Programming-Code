class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        findcombination(0,temp,candidates,target,ans);
        return ans;
    }
private:
    void findcombination(int idx,vector<int>&temp,vector<int>&candidates,int target,vector<vector<int>>&ans)
    {
        if(target<0)
            return;
        if(idx==candidates.size())
        {
            if(target==0)
                ans.push_back(temp);
            return ;
        }
        if(candidates[idx]<=target)
        {
        temp.push_back(candidates[idx]);
        findcombination(idx,temp,candidates,target-candidates[idx],ans);
        temp.pop_back();
        }
        findcombination(idx+1,temp,candidates,target,ans);
    }
};
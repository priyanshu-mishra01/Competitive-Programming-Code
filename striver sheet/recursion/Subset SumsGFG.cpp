//SUBSET SUMS

{
void solve(int ind ,int s,vector<int>&arr,vector<int>&ans,int N){
    if(ind==N){
        ans.push_back(s);
        return ;
    }
    solve(ind+1,s+arr[ind],arr,ans,N);
    solve(ind+1,s,arr,ans,N);
    
}
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        solve(0,0,arr,ans,N);
        sort(ans.begin(),ans.end());
        return ans;
    }
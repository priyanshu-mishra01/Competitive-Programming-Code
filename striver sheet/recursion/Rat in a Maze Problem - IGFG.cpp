class Solution{
    public:
    void solve(int i,int j,string move,vector<vector<int>>&m,vector<vector<int>>&vis,vector<string>&ans,int n){
        if( i==n-1 && j==n-1){
            ans.push_back(move);
            return ;
        }
        //lexicicographical order D/L/R/U DOWN,LEFT,RIGHT,UP.
        
    //DOWN
    if(i+1<n    && m[i+1][j]==1  && vis[i+1][j]==0 ){
        vis[i][j]=1;
        solve(i+1,j,move+'D',m,vis,ans,n);
        vis[i][j]=0;
        
    }
    
    //LEFT
    if(j-1>=0     && m[i][j-1]==1  && vis[i][j-1]==0 ){
         vis[i][j]=1;
        solve(i,j-1,move+'L',m,vis,ans,n);
        vis[i][j]=0;
        
    }
    //RIGHT
    if(j+1<n     && m[i][j+1]==1  && vis[i][j+1]==0 ){
         vis[i][j]=1;
        solve(i,j+1,move+'R',m,vis,ans,n);
        vis[i][j]=0;
        
    }
    //UP
    if(i-1>=0  &&     m[i-1][j]==1  && vis[i-1][j]==0  ){
         vis[i][j]=1;
        solve(i-1,j,move+'U',m,vis,ans,n);
        vis[i][j]=0;
    }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1){
            solve(0,0,"",m,vis,ans,n);
            
        }
        return ans;
    }
};
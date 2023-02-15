public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        stack<long long>st;
        vector<long long>ans;
        for(int i=n-1;i>=0;i--){//FOR NEXT GREATER ELEMENT TO LEFT CAN MAKE LOOP START FROM I=0 TO I=N-1
            if(st.empty()){
               ans.push_back(-1);
            }
            else if(!st.empty() && st.top()>arr[i]){
                ans.push_back(st.top());
            }
            else if(!st.empty() && st.top()<=arr[i]){
                while(!st.empty() && st.top()<=arr[i]){
                    st.pop();
                }
                if(st.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(st.top());
            }
            
        st.push(arr[i]);    
        }
        reverse(ans.begin(),ans.end());//AND THERE IS NO REVERSE FOR THE NEXT GREATER ELEMENT TO LEFT.
        return ans;
    }
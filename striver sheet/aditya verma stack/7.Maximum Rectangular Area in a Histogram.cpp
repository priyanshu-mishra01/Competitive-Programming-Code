 long long getMaxArea(long long arr[], int n)
    {
    
        stack<pair<long long,long long>>st1,st2;
        vector<long long>v1,v2,width(n,0),res(n,0);
        for(int i=0;i<n;i++){
            if(st1.empty())
                v1.push_back(-1);
            else if(!st1.empty() && st1.top().first<arr[i]){
                v1.push_back(st1.top().second);
            }                                                 //code for nearest smaller element to left(NSL)
            else if(!st1.empty() && st1.top().first>=arr[i]){
                while(!st1.empty() && st1.top().first>=arr[i]){
                    st1.pop();
                }
                if(st1.empty())
                    v1.push_back(-1);
                else v1.push_back(st1.top().second);
            }
            st1.push({arr[i],i});
        }
        int p=n;
        for(int i=n-1;i>=0;i--){
            if(st2.empty())
                v2.push_back(p);
            else if(!st2.empty() && st2.top().first<arr[i]){
                v2.push_back(st2.top().second);             //code for nearest smaller element to right(NSR)
            }
            else if(!st2.empty() && st2.top().first>=arr[i]){
                while(!st2.empty() && st2.top().first>=arr[i]){
                    st2.pop();
                }
                if(st2.empty())
                    v2.push_back(p);
                else v2.push_back(st2.top().second);
            }
            st2.push({arr[i],i});
        }
        reverse(v2.begin(),v2.end());// we must to reverse the arr that it get in the perfect form
        for(int i=0;i<n;i++){
            width[i]=(v2[i]-v1[i]-1);//form here we can find the width between to NSL AND NSR.
            res[i]=(width[i]*arr[i]);//resultant arr to store the area 
            
        }
        long long m= *max_element(res.begin(),res.end());
        return m;
    }
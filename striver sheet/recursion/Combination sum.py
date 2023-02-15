def solve(ind,arr,ds,ans,tar):
    if ind==len(arr):
        if tar==0:
            ans.append(ds[:])
        return 
    if(tar>=arr[ind]):
        ds.append(arr[ind])
        solve(ind,arr,ds,ans,tar-arr[ind])
        ds.pop()
    solve(ind+1,arr,ds,ans,tar)
ans=[]
ds=[]
arr=[1,2,3,4,3]
tar=4
solve(0,arr,ds,ans,tar)
print(ans)
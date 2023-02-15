def solve(ind,ds,ans,arr,tar):
    if(ind==len(arr)):
        if sum(ds)==tar:
            ans.append(ds[:])
        return
    ds.append(arr[ind])
    solve(ind+1,ds,ans,arr,tar)
    ds.pop()
    solve(ind+1,ds,ans,arr,tar)
arr=[1,2,3,4,5,3]
ds=[]
ans=[]
tar=5
solve(0,ds,ans,arr,tar)
print(ans)

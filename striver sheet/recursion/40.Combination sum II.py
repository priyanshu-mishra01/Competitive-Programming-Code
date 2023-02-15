import copy
class Solution:
    def combinationSum2(self, can: List[int], tar: int) -> List[List[int]]:
        
        def solve(ind,can,tar,ans,ds):
            if tar==0:
                ans.append(deepcopy(ds))
                return
                
            for i in range(ind,len(can)):
                if i>ind and can[i]==can[i-1]:
                    continue
                if can[i]>tar:
                    break
                ds.append(can[i])
                solve(i+1,can,tar-can[i],ans,ds)
                ds.pop()
        can.sort()
        ds=[]
        ans=[]
        solve(0,can,tar,ans,ds)
        return ans
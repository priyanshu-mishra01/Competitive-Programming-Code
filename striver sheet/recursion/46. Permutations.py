
import copy
class Solution:
    

    def permute(self, nums: List[int]) -> List[List[int]]:
        def solve(freq,ds,ans,nums):
            if(len(ds)==len(nums)):
                ans.append(deepcopy(ds))
                return
            for i in range(len(nums)):
                if not freq[i]:
                    freq[i]=1
                    ds.append(nums[i])
                    solve(freq,ds,ans,nums)
                    freq[i]=0
                    ds.pop()
        ds=[]
        ans=[]
        freq=[0]*len(nums)
        solve(freq,ds,ans,nums)
        return ans
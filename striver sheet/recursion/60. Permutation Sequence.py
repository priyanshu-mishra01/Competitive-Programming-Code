class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        fact=1
        numbers=[]
        for i in range(1,n):
            fact*=i
            numbers.append(i)
        numbers.append(n)
        st=""
        k=k-1
        while(True):
            st+=str((numbers[int(k//fact)]))
            numbers.pop(int(k//fact))
            if len(numbers)==0:
                break
            k=k%fact
            fact=fact/len(numbers)
        return st
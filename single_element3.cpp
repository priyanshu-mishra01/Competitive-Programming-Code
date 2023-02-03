/*
Given an integer array nums, in which exactly two elements appear only once and all 
the other elements appear exactly twice. Find the two elements that appear only once. 
You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
eg:-
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
*/
vector<int> singleNumber(vector<int>& nums) {
        int x=0,y=0;
        long xxory=0;
        for(int i : nums)
            xxory^=i;
        long rbms = xxory & -xxory;
        for(int i : nums)
        {
            if((i&rbms)==0)
                x^=i;
            else
                y^=i;
        }
        return {x,y};
    }
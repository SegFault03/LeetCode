'''
ACCEPTED SOLUTION
This is an implementation of Kadane's algorithm.
The main intuition is that if the cumulative sum of a subarray is <0 
(-ve), then it should not be added to the next element as it will decrease
the overall sum, and will thus not help us achieve the maximum sum. At 
that point, it is better to re-initialize the cumulative sum with the current
element (whether it be +ve/-ve) as in either case the new cumulative sum
will still be greater than if we added the current element to the prev
cumulative sum.

E.g: [7,-1,2,-11,-3,4,2]
i=0 -> set maxSum = currSum = 7
1 -> currSum >= 0 -> currSum = 7+-1 = 6
2 -> currSum >= 0 -> currSum = 6+2 = 8 -> update maxSum = 8 [Note how even if i=1 was a -ve element, it still help
ed us gain the max sum, because currSum > 0]
3 -> currSum >= 0 -> currSum = 6-11 = -5
4 -> currSum < 0 -> currSum = -3 [currSum would have only been lesser if added to -3]
5 -> currSum < 0 -> currSum = 4
6 -> currSum > 0 -> currSum = 4+2 = 6

Thus, maxSum = 8 [7,-1,2] is the Ans.
'''

def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxSum = currSum = nums[0]
        for num in nums[1:]:
            currSum = max(currSum, 0) + num
            maxSum = max(maxSum, currSum)
        return maxSum
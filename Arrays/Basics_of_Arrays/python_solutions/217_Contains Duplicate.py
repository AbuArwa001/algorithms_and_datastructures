class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        newList = list(set(nums))
        return len(newList) <  len(nums)
        
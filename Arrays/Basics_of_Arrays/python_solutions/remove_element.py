class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        id = 0
        for i in nums:
            if i != val:
                nums[id] = i
                id += 1
        return id

        
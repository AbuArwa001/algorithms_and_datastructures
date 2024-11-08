
class Solution:
    def getMaximumXor(self, nums: List[int], maximumBit: int) -> List[int]:
        answer = [0] * len(nums)
        k = (2**maximumBit) - 1
        res = 0
        for i in range(len(nums)):
            res ^= nums[i]
            answer[len(nums) - 1 - i] = k ^ res
        return answer
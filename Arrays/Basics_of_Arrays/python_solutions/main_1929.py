#!/usr/bin/env python3
"""
Given an integer array nums of length n,
you want to create an array ans of length 2n where ans[i] == nums[i]
and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

"""
getConcatenation = __import__('1929_concatenation_of_Array').Solution().getConcatenation

print(getConcatenation([1, 2, 1]))
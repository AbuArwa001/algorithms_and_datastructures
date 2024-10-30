from typing import List
class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        stn = ""
        lst = []
        l = 0
        for c in s: 
            if l == k:
                lst.append(stn)
                stn = ""
                l = 0
            l += 1
            stn = stn + c
        if stn:  # If there's any remaining part of the string
            stn += fill * (k - len(stn))  # Fill the remaining part
            lst.append(stn)


        return lst
    
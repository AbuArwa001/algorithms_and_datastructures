# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        arr = []
        temp: Optional[TreeNode] = root
        def inorder(temp: Optional[TreeNode]) -> None:
            if temp is None:
                return
            inorder(temp.left)
            arr.append(temp.val)
            inorder(temp.right)
        inorder(temp)
        return arr



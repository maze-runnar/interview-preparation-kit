""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

def checkBST(root):
    return(check_in_order(root,[-1]))
    
def check_in_order(root,prev):
    result = True
    if root.left is not None:
        result &= check_in_order(root.left,prev)
    if prev[0] >= root.data:
        return False
    prev[0] = root.data
    if root.right is not None:
        result &= check_in_order(root.right,prev)
    return result
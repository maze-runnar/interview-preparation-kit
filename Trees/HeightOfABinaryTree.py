class Node:
    def __init__(self, info): 
        self.info = info  
        self.left = None  
        self.right = None 
        self.level = None 

    def __str__(self):
        return str(self.info) 

class BinarySearchTree:
    def __init__(self): 
        self.root = None

    def create(self, val):  
        if self.root == None:
            self.root = Node(val)
        else:
            current = self.root
         
            while True:
                if val < current.info:
                    if current.left:
                        current = current.left
                    else:
                        current.left = Node(val)
                        break
                elif val > current.info:
                    if current.right:
                        current = current.right
                    else:
                        current.right = Node(val)
                        break
                else:
                    break

# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
class Node:
      def __init__(self,info): 
          self.info = info  
          self.left = None  
          self.right = None 
           

       // this is a node of the tree , which contains info as data, left , right
'''
from collections import deque
def height(root):
    queue=deque()
    queue.append(root)
    n=[]
    n.append([root.info])
    n2=[1]
    while(queue):
        n1=[]
        for i in range(len(n2)):
            current=queue.popleft()
            if(current.left!=None):
                queue.append(current.left)
                n1.append(current.left.info)
            if(current.right!=None):
                queue.append(current.right)
                n1.append(current.right.info)
        n2=n1
        if(len(n2)!=0):
            n.append(n2)
    return len(n)-1
class MyQueue(object):
    def __init__(self):
        self.mouth = []
        self.butt = []
    
    def peek(self):
        self.digest()
        return self.butt[-1]
        
    def pop(self):
        self.digest()
        return self.butt.pop()
        
    def put(self, value):
        self.mouth.append(value)
        
    def digest(self):
        if len(self.butt) == 0:
            while len(self.mouth) > 0:
                self.butt.append(self.mouth.pop())
        

queue = MyQueue()
t = int(input())
for line in range(t):
    values = map(int, input().split())
    values = list(values)
    if values[0] == 1:
        queue.put(values[1])        
    elif values[0] == 2:
        queue.pop()
    else:
        print(queue.peek())


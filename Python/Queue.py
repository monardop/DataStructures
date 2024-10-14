from Nodes import OnePointerNode
from random import randint

class Queue(): 
    def __init__(self) -> None:
        self.head: OnePointerNode = None
        self.tail: OnePointerNode = None

    def new_element(self, data)-> int:
        new_node: OnePointerNode = OnePointerNode(data)
        new_node.next  = None
        if self.head == None:
            self.head = self.tail = new_node
            return 1
        self.tail.next = new_node
        self.tail = new_node
        return 1
    
    def pop_element(self): 
        return_element = self.head.data
        self.head = self.head.next
        return return_element

    def is_empty(self)->bool:
        return self.head == None
    
nueva_fila = Queue()
for _ in range(10):
    nueva_fila.new_element(randint(0,100))

while not nueva_fila.is_empty():
    print(nueva_fila.pop_element())

print(nueva_fila.is_empty())

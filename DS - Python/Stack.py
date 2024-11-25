from Nodes import OnePointerNode as Node
from random import randint


class Stack():
    def __init__(self) -> None:
        self.head = None

    def append_element(self, data) -> int:
        new_node: Node = Node(data)
        new_node.next = self.head
        self.head = new_node
        return 1

    def pop_element(self):
        return_elem = self.head
        self.head = self.head.next
        return return_elem.data

    def is_empty(self) -> bool:
        return self.head == None

    def clear_stack(self) -> None:
        while not self.is_empty():
            self.pop_element()


nueva_pila = Stack()
print(f"Lista vacia = {nueva_pila.is_empty()}")
nueva_pila.append_element(10)
print(f"Lista vacia = {nueva_pila.is_empty()}")
nueva_pila.append_element(9)
nueva_pila.append_element(8)
nueva_pila.append_element(7)
nueva_pila.append_element(6)
nueva_pila.append_element(5)

nueva_pila.clear_stack()
print(f"Lista vacia = {nueva_pila.is_empty()}")

for _ in range(10):
    nueva_pila.append_element(randint(0, 100))

while not nueva_pila.is_empty():
    print(f"Elemento: {nueva_pila.pop_element()}")

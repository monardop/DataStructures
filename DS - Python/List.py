from Nodes import OnePointerNode
from random import randint


class SimpleLinkedList:
    def __init__(self) -> None:
        self.header: OnePointerNode = None

    def push_node(self, data):
        new_node = OnePointerNode(data)
        if self.header == None:
            self.header = new_node
            return
        new_node.next = self.header
        self.header = new_node

    def is_in_list(self, data) -> bool:
        pointer = self.header

        while pointer != None:
            if data == pointer.data:
                return True
            pointer = pointer.next

        return False

    def print_list(self):
        pointer = self.header
        while pointer is not None:
            if pointer.next is None:
                print(pointer.data)
                return
            print(pointer.data, end=" ")
            pointer = pointer.next


lista = SimpleLinkedList()

for _ in range(10):
    numero = randint(0, 100)
    lista.push_node(numero)

lista.print_list()
lista.print_list()
print(lista.is_in_list(numero))

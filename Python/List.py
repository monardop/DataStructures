from Nodes import OnePointerNode

class SimpleLinkedList:
    def __init__(self) -> None:
        self.header: OnePointerNode = None

    def push_node(self, data):
        new_node = OnePointerNode(data)

        if self.header is None:
            self.header = new_node
            return
        else:
            new_node.next = self.header
            self.header = new_node
            return

    def print_list(self, header: OnePointerNode):
        while header is not None:
            if header.next is None:
                print(header.data)
                return
            print(header.data, end=" ")
            header = header.next


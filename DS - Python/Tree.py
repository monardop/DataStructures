from Nodes import TwoPointerNode as Node

class Tree(): 
    def __init__(self) -> None:
        self.root = None
    
    def add_node(self, data, cmp_function) -> None:
            self.root = self.__insert(self.root, data, cmp_function)
    
    def __insert(self, node: Node, data, cmp):
        if node is None:
            return Node(data)
        
        if cmp(node.data, data):
            node.left = self.__insert(node.left, data, cmp)
        else:
            node.right = self.__insert(node.right, data, cmp)
        
        return node
    
    

    def inorder(self, node: Node) -> None: 
        if node is not None: 
            self.inorder(node.left)
            print(node.data, end=" ")
            self.inorder(node.right)


def cmp_numbers(a, b) -> bool:
    return a > b
def cmp_str(a, b) -> bool:
    return a > b


lista = ["Casa", "Barco", "Pato", "Xilofon", "Pasta", "Rico", "Asco", "Zapato"]
arbol = Tree()
for palabra in lista:
    arbol.add_node(palabra, cmp_str)

arbol.inorder(arbol.root)



class __Nodo:
    def __init__(self,next, value: int = 0):
        self.value = value
        self.next = next

class Lista:
    def __init__(self):
        self.__head: Nodo | None = None

    def random_list(self, length: int):
        from random import randint
        if length > 0:
            for _ in range(length):
                self.__head = Nodo(self.__head, randint(0, 10000))

    def add_nodo(self, val):
        new_nodo = Nodo(None,val)
        if self.__head is None:
            self.__head = new_nodo
            return
        current = self.__head
        while current.next is not None:
            current = current.next
        current.next = new_nodo

    def delete_nodo(self, val):
        if self.__head is None:
            print("La lista está vacía")
            return
        if self.__head.value == val:
            self.__head = self.__head.next
            return
        current = self.__head
        while current.next is not None:
            if current.next.value == val:
                current.next = current.next.next
                return
            current = current.next
        print(f"No se ha encontrado un nodo con el valor {val}")

    def search_nodo(self, value):
        current = self.__head
        i = 0
        while current is not None:
            if current.value == value:
                return i
            else:
                current = current.next
                i += 1
        return -1

    def search_index(self, index):
        current = self.__head
        for i in range(index):
            if current is None:
                return None
            current = current.next
        return current

    def __str__(self):
        if self.__head is None:
            return "[]"
        result = "["
        current = self.__head
        while current is not None:
            result += str(current.value)
            if current.next is not None:
                result += ", "
            current = current.next
        result += "]"
        return result

lista: Lista = Lista()
lista.random_list(5)
print(lista)
numero: int = int(input("Ingresa un numero a eliminar: "))
lista.delete_nodo(numero)
print(f"Si se elimina el numero {numero}, se imprime la lista {lista}")
index_to_search = 3
found_node = lista.search_index(index_to_search)
if found_node:
    print(f"Si se solicita el indice {index_to_search}, se retorna el nodo con valor {found_node.value}")
else:
    print(f"No se encontró un nodo en el índice {index_to_search}")

valor = 0
print(valor)
valor = "0"
print(valor)
valor = False
print(valor)
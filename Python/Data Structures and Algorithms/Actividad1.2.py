class Nodo:
    def __init__(self,value):
        self.__value = value
        self.__next: Nodo
    
    @property
    def value (self):
        return self.__value

    @value.setter
    def value (self,value:int):
        self.__value = value

    @property
    def next (self):
        return self.__next

    @next.setter
    def next (self,newNodo: Nodo):
        self.__next = newNodo

class Lista:
    def __init__(self,head:Nodo):
        self.__head = head
    
    def random_list(self,length:int):
        from random import randint
        current = self.__head
        for i in range(length):
            current.value = randint(0,10000)
            current = current.next
    
    def add_nodo(self,val):
        current = self.__head
        while(current != None):
            current = current.next
        current = Nodo(val)

    def delete_nodo(self,val):
        if self.__head.value == val:
            self.__head = self.__head.next
            return
        current = self.__head
        while(current.next != None):
            if current.next.value == val:
                current.next = current.next.next
                return
        print(f"No se ha encontrado un nodo con el valor {val}")
    
    def search_nodo(self,value):
        current = self.__head
        i=0
        while(current != None):
            if current.value == value:
                return i
            else:
                current = current.next;i+=1 #Iteracion
        return -1

    def search_index(self,index):
        for i in range(index)




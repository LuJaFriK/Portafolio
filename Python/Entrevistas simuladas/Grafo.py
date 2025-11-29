class Grafo_dirigido:

    class Nodo:
        def __init__(self, name:str):
            self.name = name
            self._aristas = []

        def add_conexion(self, nodo):
            if nodo not in self._aristas:
                self._aristas.append(nodo)
        
        def remove_conexion(self, nodo):
            if nodo in self._aristas:
                self._aristas.remove(nodo)

        def __str__(self):
            c = [n.name for n in self._aristas]
            return f"{self.name} ---> {c}"

    #Fin clase Nodo

    def __init__(self):
        self._nodos:dict = {}
    
    def get(self, name:str, optional = None):
        return self._nodos.get(name,optional)
    
    def add(self, name:str):
        if name not in self._nodos:
            self._nodos[name] = self.Nodo(name)

    def conect(self,origin:str,destination:str):
        if origin in self._nodos and destination in self._nodos:
            self._nodos[origin].add_conexion(self._nodos[destination])

    def disconect(self,origin:str,destination:str):
        if origin in self._nodos and destination in self._nodos:
            self._nodos[origin].remove_conexion(self._nodos[destination])
            
    def __str__(self):
        return "\n".join(str(n) for n in self._nodos.values())

class Grafo_no_dirigido(Grafo_dirigido):
    
    def conect(self,origin:str,destination:str):
        if origin in self._nodos and destination in self._nodos:
            self._nodos[origin].add_conexion(self._nodos[destination])
            self._nodos[destination].add_conexion(self._nodos[origin])

    def disconect(self,origin:str,destination:str):
        if origin in self._nodos and destination in self._nodos:
            self._nodos[origin].remove_conexion(self._nodos[destination])
            self._nodos[destination].remove_conexion(self._nodos[origin])
    

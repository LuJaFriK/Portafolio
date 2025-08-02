from Alimento import Alimento

class Cafe(Alimento):
    def __init__(self, nombre: str, costo: float, comentario: str, existencia: bool):
        super().__init__(nombre, costo, comentario, existencia)
        self.cafeina = True
        self.hielo = False
        self.milklist = ["No","Entera","Deslactosada","Almendras"]
        self.sizelist = ["Ch","Med","Gr"]
        self.leche = self.milklist[0]
        self.size = self.sizelist[0]

    def printMilkList(self) -> str:
        return "\n".join([f"{i}. {leche}" for i, leche in enumerate(self.milklist)])
    def print_size_list(self) -> str:
        return "\n".join([f"{i}. {size}" for i, size in enumerate(self.sizelist)])

    def set_milk(self, index: int) -> None:
        self.leche = self.milklist[index]
    
    def set_size(self, index: int) -> None:
        self.size = self.sizelist[index]
    
    def get_costo(self) -> float:
        nuevo_costo: float = super().get_costo()
        if self.leche == "Almendras":
            nuevo_costo += 10
        if self.size.lower() == "med":
            nuevo_costo *= 1.10
        elif self.size.lower() == "gr":
            nuevo_costo *= 1.20
        return nuevo_costo
    
    def __str__(self) -> str:
        return (super().__str__()+ "\nCafeina:" +("Si" if self.cafeina else "No")+ "\nHielo:" +("Si" if self.hielo else "No"))
    

class Uzivatel:
    def __init__(self, nome):
        self.nome = nome

class Admin(Uzivatel):
    def __init__(self, jmeno, prava):
        super().__init__(jmeno)
        self.prava = prava

    # @staticmethod -> volání jako statické medoty, self je volání pro konkretni osobu
    def smaz_databazi(self):
        print(f"Varovani")

u = Uzivatel("Test")
a = Admin("root", "test")
a.smaz_databazi()

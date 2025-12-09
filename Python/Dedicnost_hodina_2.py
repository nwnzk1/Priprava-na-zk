# ABC

from abc import ABC, abstractmethod

class Platba(ABC):

    @abstractmethod
    def proved_platbu(self, castka):
        pass


class PlatbaKartou(Platba):
    def __init__(self, cislo_karty):
        self.cislo_karty = cislo_karty

    def proved_platbu(self, castka):
        print(f"Provadim platbu kartou {self.cislo_karty}, castka {castka}")

class PlatbaPrevodem(Platba):
    def __init__(self, cislo_uctu):
        self.cislo_uctu = cislo_uctu

    def proved_platbu(self, castka):
        print(f"Provadim platbu pomoci uctu {self.cislo_uctu}, castka {castka}")

karta = PlatbaKartou("1239120042")
ucet = PlatbaPrevodem("3354123098/0800")

platby = [
    (karta, 120323),
    (ucet, 1000000000000000),
    (ucet, 198231023)
]

for zpusob_platby, castka in platby:
    zpusob_platby.proved_platbu(castka)

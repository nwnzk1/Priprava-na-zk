#Úloha 3

from typing import List, Dict

def zaindexuj(seznam:list[int]) -> bool:
    pozice:dict[int, int] = {}           # slovnik dict[klic, pozice], dict = hash tabulka - ukládáná hodnot/cisel

    # enumerate() slouzi k pruchodu seznamem a vyhodí nám dvě hodnoty - index(pozici) a hodnotu(prvek) na dané pozici
    # i = index, cislo = hodnota

    for i, cislo in enumerate(seznam):
        # checkneme jestli jsme cislo uz nekde "videli", pokud ano = duplicitní nález
        if cislo in pozice:
            # pozice posledního výskytu našeho čísla = pozice našeho momentálního čísla
            stara_pozice = pozice[cislo]
            # vypočítáme si vzdálenost -> aktuální pozice i - stará pozice
            vzdalenost = i - stara_pozice

            # pokud je vzdálenost menší rovno 3, return True
            if vzdalenost <= 3:
                return True
        # aktulizujeme si "poslední výskyt" duplicitného čísla
        pozice[cislo] = i
    # pokud není duplicitni nebo je vzdálenost větší než 3:
    return False

seznam_cisel_1:list[int] = [1, 2, 3, 1, 4]
seznam_cisel_2:list[int] = [1, 2, 3, 4, 1]

print(f"Seznam 1: {zaindexuj(seznam_cisel_1)}")
print(f"Seznam 2: {zaindexuj(seznam_cisel_2)}")




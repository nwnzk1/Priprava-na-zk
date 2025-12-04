#Úkol 3 - druhý největší prvek

seznam_cisel = [1, 3, 8, 9, 2, 10, 12, 13, 240, 221, 923]


# vrací nám největší prvek
for i in seznam_cisel:
    if i in seznam_cisel:
        nejvetsi = max(seznam_cisel)
        break  #zastaví se po prvním pruchodu, bez break by nám to vypsalo všechny čísla

print(nejvetsi)


# vrací nám druhý největší prvek (bez pouziti .sort())
max_prvek = float('-inf')
druhy_max_prvek = float('-inf')

for i in seznam_cisel:
    if i > max_prvek:
        druhy_max_prvek = max_prvek
        max_prvek = i

    elif i > druhy_max_prvek and i != max_prvek:
        druhy_max_prvek = i

print(druhy_max_prvek)


# vrací nám druhý nejvetsi prvek (pouziti .sort())
cislo = list(seznam_cisel)
cislo.sort()             # funkce .sort() nam seradi seznam od nejmensi po nejvetsi cislo
druhe_nejvetsi_cislo = cislo[-2]         # -2 je index pro cislo, ktere je druhe od konce
nejvetsi_cislo = cislo[-1]              # -1 je index pro posledni cislo na seznamu, asi chapes jak to funguje

print(druhe_nejvetsi_cislo)
print(nejvetsi_cislo)





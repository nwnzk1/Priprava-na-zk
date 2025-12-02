#Uloha 1:
def vypis_statistiku(seznam):
    soucet = sum(seznam)
    nejvetsi = max(seznam)
    nejmensi = min(seznam)
    prumer = soucet / len(seznam)

    pocet_sudych = 0
    pocet_lichych = 0
    for cislo in seznam:
        if cislo % 2 == 0:
            pocet_sudych += 1
        elif cislo % 1 == 0:
            pocet_lichych += 1
    print(f"Soucet: {soucet}, Prumer: {prumer}, Nejvetsi: {nejvetsi}, Nejmensi: {nejmensi}"
          f", Pocet lichych: {pocet_lichych}"
          f", Pocet sudych: {pocet_sudych}")

seznam_cisel = []
while True:
    vstup = (input("Zadavej cisla, dokud nenapises STOP: "))

    if vstup == "STOP":
        break
    try:
        cisla = int(vstup)
        seznam_cisel.append(cisla)
    except ValueError:
        print("Neni cislo, neni STOP, znovu")

print()
vypis_statistiku(seznam_cisel)

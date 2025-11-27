from os.path import join, realpath, dirname          #knihovny

#OTEVRENI SOUBORU
cesta = join(dirname(realpath(__file__)),"data.txt")
print(cesta)

#PART 1
celkem = 0

with open(cesta, mode = "r", encoding = "utf-8") as f:
    for c, radek in enumerate(f):
        cisla = [znak for znak in radek if znak.isdigit()]
        celkem+=int(cisla[0]+cisla[-1])
print(celkem)

#PART 2
celkem2 = 0

#"Sandwich trick" pro překrývající se čisla - před číslo a za číslo dej slovo -> zachováme písmenka pro sousední čísla 
nahrady = { "one": "one1one", "two": "two2two", "three": "three3three", "four": "four4four", "five": "five5five",
            "six": "six6six", "seven": "seven7seven", "eight": "eight8eight", "nine": "nine9nine" }

with open(cesta, mode = "r", encoding = "utf-8") as f:
    for c, radek2 in enumerate(f):
        for slovo, nahrada in nahrady.items():
            radek2 = radek2.replace(slovo, nahrada)

        cisla2 = [znak2 for znak2 in radek2 if znak2.isdigit()]
        hodnota = int(cisla2[0] + cisla2[-1])
        celkem2 += hodnota
print(celkem2)

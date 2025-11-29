from os.path import join, realpath, dirname

# TRIDA :
# __innit__ je nas konstruktor v pythonu
# __funkce__ = Double Underscore = python si to vola sam na pozadi
# self je neco jako 'this' v cpp, proste to tam musi byt, aby "python" vedel, komu ma priradit data,
# predtav si, ze to je neco jako "JA"
# __str__ je zde pro vypis dat

# Trida se musi definovat drive nez ji pouzijeme
class Hrac:
    def __init__(self, jmeno, level, zdravi):
        self.jmeno = jmeno
        self.level = int(level)
        self.zdravi = int(zdravi)

    def __str__(self):
        return (f"Hrac {self.jmeno} | Lvl: {self.level} | HP: {self.zdravi}")

cesta = join(realpath(dirname(__file__)), "zaklad_trid.txt")
seznam_hracu = []       # pro hotove objekty

with open(cesta, mode = "r", encoding="utf-8") as f:
    for radek in f:
        # .strip() odstraní neviditelný znak konce řádku (\n) a mezery okolo:
        cisty_radek = radek.strip()
        # preskocime prádný řádek:
        if not cisty_radek:
            continue
        # rozsekame radky podle carky (stringstream v cpp):
        data = cisty_radek.split(",")
        # vytvorime objekty (jmeno, 1 = lvl, 2 = hp):
        novy_hrac = Hrac(data[0], data[1], data[2])
        # ulozeni objektu do seznamu:
        seznam_hracu.append(novy_hrac)

print(f"Uspesne nacteno {len(seznam_hracu)} hracu.")  # len vraci pocet objektu v seznamu, v cpp je to .size()

for h in seznam_hracu:
    print(h)      # vola se funkce __str__ uvnitr tridy


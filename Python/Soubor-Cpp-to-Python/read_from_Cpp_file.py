from os.path import join, realpath, dirname

#najdeme soubor v naší "python" složce
cesta = join(realpath(dirname(__file__)), "cpptopython.txt")
print(cesta)

#otevreme soubor, precteme soubor "r" a poté ho uložíme do proměnné f
with open(cesta, mode = "r", encoding="utf-8") as f:
    # přecteme celý soubor pomocí .read() [vrati se to jako string] a následně ho pritneme do konzole
    print(f.read())

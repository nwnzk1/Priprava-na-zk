from os.path import join, realpath, dirname

cesta = join(realpath(dirname(__file__)), "system.log")
cesta_2 = join(realpath(dirname(__file__)), "errors_only.txt")

error_seznam = []
slovo = "ERROR"
with open(cesta, mode = "r", encoding="utf-8") as f:
    for radek in f:
        if slovo in radek:
            error_seznam.append(radek)

with open(cesta_2, mode = "w", encoding="utf-8") as f:
    for radek in error_seznam:
        f.write(radek)

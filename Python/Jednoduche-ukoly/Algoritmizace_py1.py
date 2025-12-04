# Úloha 1 - Filtr sudých čísel

cela_cisla = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 222, 2323013, 20392042]
kladne_cisla = []

for i in cela_cisla:
    if i % 2 == 0:
        kladne_cisla.append(i)
print(kladne_cisla)

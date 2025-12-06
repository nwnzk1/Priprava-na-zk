# Úloha 1 - Filtr kladných sudých čísel a součet

cele_cisla:list[int] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
kladne_sude_cisla:list[int] = []

for cislo in cele_cisla:
    if cislo %2 == 0 and cislo > 0:
        kladne_sude_cisla.append(cislo)
print(kladne_sude_cisla)
print(f"Soucet cisel je {sum(kladne_sude_cisla)}")

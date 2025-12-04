# Úloha 5 - odstraneni duplicit ze seznamu pri zachovani poradi

seznam_cisel = [5, 2, 3, 8, 5, 9, 8, 11, 2324, 2]

kontrola_duplicity = set()
vysledny_seznam= []

for i in seznam_cisel:
    if i not in kontrola_duplicity: # kontrolujeme, zda se prvek i nachazi v kontrolni mnozine, pokud ne, proběhne:
        vysledny_seznam.append(i)  # pridame si vsechna cisla do vysledneho seznamu
        kontrola_duplicity.add(i)  # pridame prvek do kontroly a pri dalsim nalezu ho preskocime

print(seznam_cisel)
print(vysledny_seznam)



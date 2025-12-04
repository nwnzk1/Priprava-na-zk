# Úloha 2 - počet samohlásek

retezec:str = ("Mam rAd susEnky")
samohlasky = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
pocitadlo = 0

for i in retezec:
    if i in samohlasky:
        print(i)
        pocitadlo += 1

print(pocitadlo)







#Ukol 2
def spocitej_znaky(text):
    # 1. Prázdný slovník pro výsledky
    vyskyt = {}

    # 2. Převedeme celý text na malá písmena
    text_maly = text.lower()

    # 3. Procházíme znak po znaku
    for znak in text_maly:
        # Podmínka: Ignorujeme mezery
        if znak == " ":
            continue  # Přeskočí zbytek cyklu a jde na další znak

        # 4. Logika počítání
        if znak in vyskyt:
            # Pokud už znak ve slovníku je, přičteme 1
            vyskyt[znak] = vyskyt[znak] + 1
        else:
            # Pokud tam není (vidíme ho poprvé), založíme ho s hodnotou 1
            vyskyt[znak] = 1

    # 5. Funkce vrátí hotový slovník
    return vyskyt

# Otestování funkce
vstupni_text = "Ahoj Svete"
vysledek = spocitej_znaky(vstupni_text)
print(vysledek)
#Úloha 4

from typing import List, Dict
import string

def frekvence_prvnich_pismen(retezec:str):
    unikatni_slovo:list[str] = []
    kontrola_duplicity = set()
    slovnik: dict[str, int] = {}

    # string.punctuation = tabulka se znaky
    # .translate() = aplikuj to na vytvořený retezec
    # str.maketrans("tento znak", "nahrad tímto znakem", "odstran tyto znaky")
    cisty_retezec = retezec.lower().translate(str.maketrans('', '', string.punctuation))
    slova = cisty_retezec.split()

    for slovo in slova:
        if slovo not in kontrola_duplicity:
            unikatni_slovo.append(slovo)
            kontrola_duplicity.add(slovo)

    for slovo in unikatni_slovo:
        prvni_pismeno = slovo[0]

        if prvni_pismeno in slovnik:
            slovnik[prvni_pismeno] += 1
        else:
            slovnik[prvni_pismeno] = 1

    return slovnik

veta:str = "Pes jí maso, pes je rychlý."

print(f"Pocet prvnich pismen: {frekvence_prvnich_pismen(veta)}")






#Úloha 2 - Anagramová skupina

from typing import List, Dict

seznam_slov:list[str] = ["kARa", "ranO", "arKa", "kAro"]
seznam_slov_serazeno:dict[str, List[str]] = {}       # vytvoreni slovniku pomoci Dict + typing

for slovo in seznam_slov:
    male_slovo = slovo.lower()            # prevedeme si slova v seznamu na male pismena
    znaky = list(male_slovo)             # vytvorime si jednotlive pismena [a, b, c, d, ...]
    znaky.sort()                        # .sort() pro uspořádání podle abecedy
    klic = "".join(znaky)              # .join() pro spojení ['a', 'b', 'c'] do jednoho retezce ['abc']


    # Tady projizdime slovnik seznam_slov_serazeno, pokud už se klíč (např 'abc') už jednou nachází v tomto seznamu,
    # přidá další slovo se stejným klíčem do svého seznamu 'abc' : [slovo 1, slovo 2], pokud ne (else) vytvoří se nový
    # seznam např. 'cde' : [slovo3] atd.
    if klic in seznam_slov_serazeno:
        seznam_slov_serazeno[klic].append(slovo)
    else:
        seznam_slov_serazeno[klic] = [slovo]

print(seznam_slov_serazeno)





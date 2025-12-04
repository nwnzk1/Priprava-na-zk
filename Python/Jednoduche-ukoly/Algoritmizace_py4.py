# Úloha 4 - anagramy

retezec_1 = "karA"
retezec_2 = "Rana"
retezec_1 = retezec_1.lower()       # prevedeme velke pismena na male
retezec_2 = retezec_2.lower()

seznam_1 = list(retezec_1)         # vytvorime si list ['k', 'a', 'r', 'a']
seznam_2 = list(retezec_2)

seznam_1.sort()            # serazeni listu ['a', 'a', 'k', 'r']
seznam_2.sort()

if seznam_1 == seznam_2:           # porovnani jestli se znaky v listech schodují, pokud ano:
    print("JSOU STEJNE")
else:                          # pokud ne:
    print("NEJSOU STEJNE")



#Vypsání stromecku do konzole

vyska_stromu:int = int(input("Zadej vysku stromu: "))
vyska_kmene:int = int(input("Zadej vysku kmene: "))
sirka_kmene:int = int(input("Zadej vysku kmene: "))

for i in range(vyska_stromu):
    print(" "*(vyska_stromu-i)+"*"*(i*2+1))

for _ in range(vyska_kmene):
    print(" "*(vyska_stromu-vyska_kmene//2)+"#"*sirka_kmene)













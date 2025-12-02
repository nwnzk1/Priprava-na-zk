#Ukol 3

studenti = []
def pridej_studenta(jmeno, znamky):
    novy_student = {
        "jmeno": jmeno,
        "znamky": znamky
    }
    studenti.append(novy_student)

pridej_studenta("Marek", [1, 3, 5, 2])
pridej_studenta("Adam", [1, 1, 2, 4])
pridej_studenta("Marcel", [2, 2, 1, 1])

def nejlepsi_student(seznam):
    prumer = 5.0
    jmeno_n = ""

    for student in seznam:
        aktualni_prumer = sum(student["znamky"]) / len(student["znamky"])

        if aktualni_prumer < prumer:
            prumer = aktualni_prumer
            jmeno_n = student["jmeno"]

    print(f"Nejlepsi student je {jmeno_n} s prumerem: {prumer}")

nejlepsi_student(studenti)







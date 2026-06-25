import csv
 
class Graduado:
    def __init__(self, apynom, promedio):
        self.apynom = apynom
        self.promedio = promedio

def solution():
    neg = pos = fav = muy_fav = total = 0
    with open("./Ejercicios/2.2.6/graduados.csv", "r", newline='', encoding='utf-8') as file:
        reader = csv.DictReader(file)
        for grad in reader:
            total += 1 
            graduado = Graduado(grad['nombre_completo'], grad['promedio_general'])
            p = float(graduado.promedio)
            if p < 7:
                neg += 1
                print(graduado.apynom, " ", p, " ", "NO")
            elif p < 8:
                pos += 1
                print(graduado.apynom, " ", p, " ", "SI")
            elif p < 9:
                fav += 1
                print(graduado.apynom, " ", p, " ", "F")
            elif p >= 9:
                muy_fav += 1
                print(graduado.apynom, " ", p, " ", "MF")


    total = neg + pos + fav + muy_fav
    print("--")
    print("En total se encontraron")
    print("Graduados NEGATIVOS: ", neg)
    print("Graduados POSITIVOS: ", pos)
    print("Graduados FAVORABLES: ", fav)
    print("Graduados MUY FAVORABLES: ", muy_fav)
    print("En promedio...")
    print("El", round((neg / total) * 100), "% fueron negativos")
    print("El", round((pos / total) * 100), "% fueron positivos")
    print("El", round((fav / total) * 100), "% fueron favorables")
    print("El", round((muy_fav / total) * 100), "% fueron muy favorables")
    return

solution()

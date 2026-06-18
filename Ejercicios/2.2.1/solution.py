# CONSIGNA:
# Se dispone de una secuencia con los datos de los alumnos de la facultad:
# 
# Apellido y Nombre
# Carrera (ISI - IEM - IQ)
# Nº de Legajo
# Fecha de Nacimiento
# Fecha de Ingreso
# D.N.I.
# Sexo (M o F)
# Fecha de último examen aprobado
# Nota
# 
# Se desea un listado de los mismos, con el siguiente formato:
# 
# Nro_Legajo 
# Apellido_Nombre
# Documento
# Carrera

class Estudiante:
    def __init__(self, carrera, nombre, legajo, fecha_nac, fecha_ing, dni, sexo):
        self.carrera = carrera
        self.nombre = nombre
        self.legajo = legajo
        self.fecha_nac = fecha_nac
        self.fecha_ing = fecha_ing
        self.dni = dni
        self.sexo = sexo

    def agregar_notas(self, fecha_ult_exam_apr, nota):
        self.fecha_ult_exam_apr = fecha_ult_exam_apr
        self.nota = nota


def __main__():
    print("Hello!")
    return 1

__main__()

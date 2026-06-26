
# Del archivo general de alumnos de la U.T.N. - Facultad Regional Resistencia, ordenado por carrera,
# se desea emitir la cantidad de alumnos correspondientes a cada carrera y el total general.

import csv

from dataclasses import dataclass


@dataclass
class Student:
    id: int
    name: str
    surname: str
    degree: str

def solution():
    saved_degree = ""
    total_count = 0;
    degree_count = 0;

    def Degree_Cut():
        nonlocal total_count;
        nonlocal degree_count;
        nonlocal saved_degree;
        nonlocal student;
        print(f"En {saved_degree} hay {degree_count} alumnos.")
        saved_degree = student.degree;
        total_count = total_count + degree_count;
        degree_count = 0
        return

    with open('./Ejercicios/2.2.10/alumnos.csv', mode='r', newline='') as file:
        reader = csv.DictReader(file);
        saved_degree = next(reader)["Carrera"];
        degree_count += 1
        for row in reader:
            student = Student(int(row["Legajo"]), row["Nombre"], row["Apellido"], row["Carrera"]);
            degree_count += 1
            if saved_degree != student.degree:
                Degree_Cut()
        Degree_Cut()

    print(f"La cantidad de alumnos en la UTN FRRE es de: {total_count}.")
    return

solution()

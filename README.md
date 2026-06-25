# Algoritmos y Estructuras de Datos

Repositorio con mis soluciones a los ejercicios y problemas de la materia **Algoritmos y Estructuras de Datos** (cursada 2026).

## Objetivo

Practicar resolución de problemas algorítmicos, aplicar las estructuras de datos vistas en clase y mantener un registro de progreso a lo largo de la cursada.

## Estructura del proyecto
```
.
├── README.md
├── bin/
├── run.sh
└── Ejercicios/
    └── ID_Problema/
        └── consigna.txt
        └── mock_data.csv
        └── solution.pseudo
        └── solution.py
        └── solution.c
```
## Cómo ejecutar

Desde la raíz del proyecto:

```bash
./run.sh <problema> <lenguaje>
```

| Parámetro | Descripción |
|---|---|
| `<problema>` | Nombre de la carpeta del problema |
| `<lenguaje>` | Extensión del archivo de solución (`py`, `c`, `pseudo`) |

**Ejemplo:**
```bash
./run.sh 2.2.6 py
```
o

```bash
./run.sh 2.2.6 c
```

## Tecnologías

- **Lenguajes:** Pseudocódigo, Python, C
- **Compilador / Intérprete:** `gcc`, `python3`
- **Control de versiones:** Git

## Aviso

Las soluciones fueron desarrolladas con fines educativos y de práctica personal. Pueden existir múltiples formas válidas de resolver cada problema.

## Autor

**Jesus Saez** · Algoritmos y Estructuras de Datos · 2026

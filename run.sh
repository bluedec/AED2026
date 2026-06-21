#!/usr/bin/env bash

# 1. Check if the user provided an argument
if [ -z "$1" ]; then
    echo "Error: No program name provided."
    echo "Usage: $0 <problem_name> <solution_language>"
    exit 1
fi

if [ -z "$2" ]; then
    echo "Error: No language provided."
    echo "Usage: $0 <problem_name> <solution_language> ('c' or 'py')"
    echo "Example: $0 2.2.6 c"
    echo "Example: $0 2.2.6 py"
    exit 1
fi

if [ "$2" != "c" ] && [ "$2" != "py" ]; then
    echo "The file type is neither c nor py."
    echo "Usage: $0 <problem_name> <solution_language> ('c' or 'py')"
    exit 1
fi

# 2. Store the argument in a descriptive variable
PROBLEM_NAME="$1"
FILE_EXTENSION="$2"
FILE="./Ejercicios/$PROBLEM_NAME/solution.$FILE_EXTENSION"


# 3. Check if the program exists and is executable
if [ -f "$FILE" ]; then
    echo "Running problem '$PROBLEM_NAME' in $FILE_EXTENSION..."
    echo "--------------------------"
    if [ $FILE_EXTENSION == "c" ]; then
      gcc "$FILE" -o "./bin/$PROBLEM_NAME.out"
      exec "./bin/$PROBLEM_NAME.out"
    fi 

    if [ $FILE_EXTENSION == "py" ]; then
      python "$FILE" 
    fi 
else
    echo "Ese problema no se encuentra o la solucion no esta implementada en ese lenguaje."
    exit 1
fi

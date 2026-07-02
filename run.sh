#!/usr/bin/env bash

SCRIPT_DIR="$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")"

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
FILE="$SCRIPT_DIR/Ejercicios/$PROBLEM_NAME/solution.$FILE_EXTENSION"

# 3. Check if the program exists and is executable
if [ -f "$FILE" ]; then
    echo "⌠ Bienvenido  "
    echo "⌡ Running problem '$PROBLEM_NAME' in $FILE_EXTENSION..."
    echo "--------------------------"
    if [ $FILE_EXTENSION == "c" ]; then
      gcc "$FILE" -o "$SCRIPT_DIR/bin/$PROBLEM_NAME.out"
      if [ -f "$SCRIPT_DIR/bin/$PROBLEM_NAME.out" ]; then
        exec "$SCRIPT_DIR/bin/$PROBLEM_NAME.out" "$SCRIPT_DIR" 
      else
        echo "Failed creating the binary."
      fi
    fi 
    if [ $FILE_EXTENSION == "py" ]; then
      python "$FILE" "$SCRIPT_DIR" 
    fi 
else
    echo "Ese problema no se encuentra o la solucion no esta implementada en ese lenguaje."
    exit 1
fi

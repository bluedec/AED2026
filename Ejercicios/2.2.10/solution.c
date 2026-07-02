
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <libgen.h>

void DegreeCut(char *curr_degree, char *saved_degree, int *students, int *total_students, int degree_length) {
  printf("En %s hay %d alumnos.\n", saved_degree, *students);
  *total_students += *students;
  *students = 0;
  strncpy(saved_degree, curr_degree, degree_length);
  saved_degree[degree_length] = '\0';
}

int findDegreeLength(char *degree) {
  int degree_length = 0;
  char c = *degree;
  while (c != ' ' && c != ',' && c != '\n') {
    degree_length += 1;
    c = degree[degree_length];
  }
  return degree_length;
}
/**
 * @brief Finds the offset for the third column  
 *
 * Finds three commas, and gives the next element's offset relative to the start.
 *
 * @param line what is to be traversed.
 * @return the offset or -1.
 */
int DegreeAtOffset(char *line) {
  int commas_seen = 0;
  int offset = 0;
  char c = line[0];
  while (commas_seen < 3 && c != '\0') {
    c = line[offset];
    if (c == ',') {
      commas_seen += 1;
    } 
    offset += 1;
    while (line[offset] == ' ') {
      offset += 1;
    }
    if (commas_seen == 3) {
      return offset;
    }
  }
  return -1;
}


int main(int argc, char *argv[]) {
  char line[100] = "";
  int total_students = 0;
  int students = 0;
  char saved_degree[10];
  int offset = 0;
  char *curr_degree;
  int degree_length;
  if (argv[1] == NULL) {
    printf("No absolute path was provided by the calling script.");
    return 1;
  }
  char *path = strcat(argv[1], "/Ejercicios/2.2.10/alumnos.csv");

  char buf[PATH_MAX];
  char *res = realpath(path, buf);

  if (res) {
    printf("Source is at: %s\n", res);
  } else {
    perror("Error resolving path.\n");
    return 1;
  }

  FILE *fptr = fopen(res, "r");

  if (fptr == NULL) {
    printf("No csv file found. Aborting. \n");
    return 1;
  }

  // Skip the first line (Column headers)
  if (fgets(line, sizeof(line), fptr) != NULL){}

  // Get the first degree
  if (fgets(line, sizeof(line), fptr) != NULL) {
    int offset = DegreeAtOffset(line);
    if (offset != 1) {
      degree_length = findDegreeLength(&line[offset]);
      curr_degree = &line[offset];
      curr_degree[degree_length] = '\0';
      strncpy(saved_degree, curr_degree, degree_length);
      saved_degree[degree_length] = '\0';
    }
    students += 1;
  }

  while (fgets(line, sizeof(line), fptr) != NULL) {
    int offset = DegreeAtOffset(line);
    if (offset != 1) {
      degree_length = findDegreeLength(&line[offset]);
      curr_degree = &line[offset];
      curr_degree[degree_length] = '\0';
    }
    if (strcmp(curr_degree, saved_degree) != 0) {
      DegreeCut(curr_degree, saved_degree, &students, &total_students, degree_length);
    }
    students += 1;
  }
  DegreeCut(curr_degree, saved_degree, &students, &total_students, degree_length);

  printf("En la UTN hay un total de %d alumnos.", total_students);

  return 0;
}

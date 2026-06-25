#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *trimright(char *str) {
  if (str == NULL) return str;

  char *end = str + strlen(str) - 1;
  while (end > str && isspace((unsigned char)*end)) {
    end--;
  }
  *(end + 1) = '\0';

  return str;
}

typedef struct {
  char fullname[100];
  float avg;
} Graduado;

char *RecommendationStatus(Graduado *grad) {
  char *a = "";
  if (grad->avg < 7.0){
    return a = "No";
  }
  if (grad->avg < 8.0){
    return a = "Si";
  }
  if (grad->avg < 9.0){
    return a = "F";
  }
  if (grad->avg >= 9.0){
    return a = "MF";
  }
  return a;
}

int main() {
  FILE *fptr = fopen("./Ejercicios/2.2.6/graduados.csv", "r");
  if (fptr == NULL) {
    printf("Could not find the file. Terminating the program.\n");
    return 1;
  }
  printf("File opened succesfully.\n");

  int capacity = 10;
  int count = 0;

  float avg = 0.0;
  char avgStr[3];

  Graduado *listOfGrads = malloc(capacity * sizeof(Graduado));

  char line[1024];
  while (fgets(line, sizeof(line), fptr)) {
    count += 1;
    if (count == capacity) {
      capacity *= 2;
      listOfGrads = realloc(listOfGrads, capacity * sizeof(Graduado));
    }

    line[strcspn(line, "\r\n")] = 0;

    if (!strstr(line, ",")) {
      continue;
    }

    Graduado gd;

    int i = 0;
    while (line[i] != ',') {
      gd.fullname[i] = line[i];
      i++;
    }
    gd.fullname[i] = '\0';
    i++;
    int f = 0;
    while (line[i] != '\0') {
      avgStr[f] = line[i];
      f++;
      i++;
    }
    gd.avg = strtof(avgStr, NULL);
    printf("%s %.1f %s\n", gd.fullname, gd.avg, RecommendationStatus(&gd));
  }


  return 0;
}

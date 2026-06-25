#include <ctype.h>
#include <math.h>
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

char *RecommendationStatus(Graduado *gd) {
  char *a = "";
  if (gd->avg < 7.0){
    return a = "No";
  }
  if (gd->avg < 8.0){
    return a = "Si";
  }
  if (gd->avg < 9.0){
    return a = "F";
  }
  if (gd->avg >= 9.0){
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

  int gn, gs, gf, gm;
  gn = gs = gf = gm = 0;

  float avg = 0.0;
  char avgStr[3];


  Graduado *listOfGrads = malloc(capacity * sizeof(Graduado));
  Graduado gd;

  char line[1024];
  if (fgets(line, sizeof(line), fptr) != NULL) {
    // First line skipped
  }

  while (fgets(line, sizeof(line), fptr) != NULL) {
    count += 1;
    if (count == capacity) {
      capacity *= 2;
      listOfGrads = realloc(listOfGrads, capacity * sizeof(Graduado));
    }

    line[strcspn(line, "\r\n")] = 0;

    if (!strstr(line, ",")) {
      continue;
    }


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
    char *reco = "";
    if (gd.avg < 7.0){
      reco = "No";
      gn++;
    } else if (gd.avg < 8.0){
      reco = "Si";
      gs++;
    } else if (gd.avg < 9.0){
      reco = "F";
      gf++;
    } else if (gd.avg >= 9.0){
      reco = "MF";
      gm++;
    }
    printf("%s %.1f %s\n", gd.fullname, gd.avg, reco);
  }
  printf("Graduados...\n");
  printf("  No Recomendados: %d\n", gn);
  printf("  Recomendados:    %d\n", gs);
  printf("  Favorables:      %d\n", gf);
  printf("  Muy Favorables:  %d\n", gm);

  int total = (gn + gs + gf + gm);

  printf("En promedio...\n");
  printf("  El %d %% fueron negativos\n", (gn * 100) / total);
  printf("  El %d %% fueron negativos\n", (gs * 100) / total);
  printf("  El %d %% fueron negativos\n", (gf * 100) / total);
  printf("  El %d %% fueron negativos\n", (gm * 100) / total);

  return 0;
}

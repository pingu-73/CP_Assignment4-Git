#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
  char word[MAX_LEN];
  FILE *fp;

  fp = fopen("test.txt", "r");
  if (fp == NULL) {
    printf("Could not open file\n");
    return 1;
  }

  while (fscanf(fp, "%s", word) != EOF) {
    word[0] = toupper(word[0]);
    int last = strlen(word) - 1;
    word[last] = toupper(word[last]);
    printf("%s ", word);
  }

  fclose(fp);
}

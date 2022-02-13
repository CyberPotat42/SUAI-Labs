#include <stdio.h>
#include <stdlib.h>
#include "list.c"

typedef struct file {
  char *str;
  int size;
} file;

// определение размера файла
int file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
	int fsize = ftell(file);
	fseek(file, 0, SEEK_SET);
	return fsize;
}

// чтение файла в строку
file* read_file(char *path) {
  FILE *f = fopen(path, "r");
  if (f == NULL) perror("Error opening file");

  int fsize = file_size(f);
  char *str = (char*) malloc((fsize + 1) * sizeof(char));
  for (int i = 0; i < fsize; i++)
    str[i] = fgetc(f);
  str[fsize] = 0;
  fclose(f);

  file *temp_file = (file*) malloc(sizeof(file));
  temp_file -> str = str;
  temp_file -> size = fsize;
  return temp_file;
}

void parse_file(file *file, list *list) {
  char *str = file -> str;
  int temp = 0, has_number = 0;
  
  for (int i = 0; str[i] != 0; i++) {
    if ('0' <= str[i] && str[i] <= '9') {
      temp = temp * 10 + (str[i] - 48);
      has_number = 1;
    } else if (str[i] == ' ') {
      if (has_number) {
        push_back(list, temp);
        has_number = 0;
      }
      temp = 0;
    } else continue;
  }
}
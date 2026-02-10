#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  DIR *d;
  struct dirent *dir;
  char **file_list = NULL;
  int count = 0;

  d = opendir(".");

  if (d == NULL) {
    printf("Error: The File couldnt opened!\n");
    return 1;
  }
  while ((dir = readdir(d)) != NULL) {
    count++;
    file_list = realloc(file_list, count * sizeof(char *));
    file_list[count - 1] = malloc(strlen(dir->d_name) + 1);
    strcpy(file_list[count - 1], dir->d_name);
  }
  closedir(d);
  printf("----------- File List -----------\n");

  for (int i = 0; i < count; i++) {
    printf("%s\n", file_list[i]);
  }

  for (int i = 0; i < count; i++) {
    free(file_list[i]);
  }
  free(file_list);
  return 0;
}

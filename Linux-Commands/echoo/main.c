#include <unistd.h>

int Length(char *str);

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    int length = Length(argv[i]);
    write(1, argv[i], length);
    write(1, " ", 1);
  }
  write(1, "\n", 1);
  return 0;
}

int Length(char *str) {
  int i = 0;
  for (i = 0; str[i] != '\0'; i++) {
  }
  return i;
}

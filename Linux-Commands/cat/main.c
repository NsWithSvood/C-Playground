#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char Bucket[4096];
  int fd;
  int n;

  if (argc < 2) {
    write(2, "Error: Couldnt get file name!\n", 30);
    return 1;
  }

  fd = open(argv[1], O_RDONLY);

  if (fd < 0) {
    write(2, "Error: Cannot open file.\n", 25);
    return 1;
  }

  while ((n = read(fd, Bucket, 4096)) > 0) {
    write(1, Bucket, n);
  }

  close(fd);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
  char Restart;
  do {
    long long int Number, BiggestNumber, Temp;
    int steps = 0;
    FILE *file;

    printf("Please enter a positive number\n");
    scanf("%lld", &Number);

    file = fopen("dataofcollatz.csv", "w");
    fprintf(file, "Step,Value\n");

    BiggestNumber = Number;
    Temp = Number;

    fprintf(file, "%d,%lld\n", steps, Number);

    while (Number > 0) {
      if (Number == 1) {
        break;
      }
      if (Number % 2 == 0) {
        Number /= 2;
      } else {
        Number = (Number * 3) + 1;
      }
      steps++;
      fprintf(file, "%d,%lld\n", steps, Number);

      if (Number > BiggestNumber) {
        BiggestNumber = Number;
      }
    }
    fclose(file);

    system("gnuplot -p -e \"set datafile separator ','; plot "
           "'dataofcollatz.csv' using 1:2 with lines title 'Collatz Yolu'\"");

    printf("The number %lld took %d steps to reach 1.\n Its peak is %lld.\n",
           Temp, steps, BiggestNumber);
    printf("All data is saved in 'dataofcollatz.csv!\n");

    printf("Do you want to do one more time? y/n\n");
    scanf(" %c", &Restart);

  } while (Restart == 'y');
  return 0;
}

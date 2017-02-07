#include <stdio.h>

int isPrime(int number) {
  if (number <= 1)
    return 0;
  else if (number <= 3)
    return 1;
  else if (number%2 == 0 || number%3 == 0)
    return 0;
  int i = 5;
  while (i*i <= number) {
    if(number%i == 0 || number%(i+2) == 0)
      return 0;
    i += 6;
  }
  return 1;
}

int main() {
  int cases, ccounter = 0, beg, end;
  scanf("%d", &cases);
  while(ccounter != cases) {
    scanf("%d %d", &beg, &end);
    for(int i = beg ; i <= end ; i++) {
      if(isPrime(i) && i != 1)
        printf("%d\n", i);
    }
    printf("\n");
    ccounter++;
  }
  return 0;
}

/* #include <stdio.h> */

/* int main() { */
/*   while(1) { */
/*     int x; */
/*     scanf("%d", &x); */
/*     if(x == 42) */
/*       break; */
/*     printf("%d\n", x); */
/*   } */

/*   return 0; */
/* } */


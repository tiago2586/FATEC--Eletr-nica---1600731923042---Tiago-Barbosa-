/*Desenvolva um programa para calcular a resistência equivalente para um circuito com duas resistências em paralelo.*/

#include <stdio.h>

int main (void) {
  float r1, r2, req;
  printf ("Informe os valores de R1 e R2 ");
  scanf ("%f %f", &r1, &r2);
  req = (float) (r1*r2) / (r1+r2);
  printf ("O valor da resistência equivalente é = %.1f\n", req);
  return 0;
}
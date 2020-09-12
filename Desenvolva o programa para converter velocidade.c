/*Desenvolva o programa para converter um velocidade em m/s em km/h*/

#include <stdio.h>

int main (void) {
  float vm, km;
  
  printf ("Qual a velocidade? ");
  scanf ("%f", &vm);
  km = vm * 3.6;
  printf ("O valor é = %.1f km/h", km);
  return 0;

}
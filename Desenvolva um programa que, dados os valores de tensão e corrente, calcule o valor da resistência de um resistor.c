/*Desenvolva um programa que, dados os valores de tensão e corrente, calcule o valor da resistência de um resistor*/

#include <stdio.h>

int main (void) {
  float t, c, r;

  printf ("Informe o valor da tensão e corrente respectivamente? ");
  scanf ("%f %f", &t, &c);
  r = (float) t / c;
  printf ("O valor do resistor é = %.1f\n", r);
  return 0;
}
#include <stdio.h>

int main (void){

  float p, m;

  printf ("Valor em polegadas? ");
  scanf ("%f", &p);
  m = p * 25.4;
  printf ("Milímetros = %.1f mm\n", m);
  return 0;
}

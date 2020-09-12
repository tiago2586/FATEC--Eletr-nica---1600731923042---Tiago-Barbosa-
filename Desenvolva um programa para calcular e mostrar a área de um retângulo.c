/*Desenvolva um programa para calcular e mostrar a área de um retângulo*/

#include <stdio.h>

int main (void)
 {
  float l, a, t;
  
  printf ("Largura? ");
  scanf ("%f", &l);
  printf ("Altura? ");
  scanf ("%f", &a);
  t = l * a;
  printf ("tamanho do retângulo é = %.1f M", t);
  return 0;
}
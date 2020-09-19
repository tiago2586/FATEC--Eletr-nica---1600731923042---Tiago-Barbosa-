/*Desenvolva um projeto que leia as medidas dos lados de um triângulo e mostre se ele é Equilátero,
Isósceles ou Escaleno. Sendo que: 
a) Triângulo Equilátero: possui os 3 lados iguais.
b) Triângulo Isóscele: possui 2 lados iguais.
c) Triângulo Escaleno: possui 3 lados diferentes.*/

#include <stdio.h>
int main (void) {
  int A, B, C;

  printf ("Insira as medidas dos lados \n" );
  scanf ("%d %d %d", &A, &B, &C);

  if (A == B && B == C)
   {
     printf ("Esse triângulo é equilátero, possuí os três lados iguais \n");
   }
  
  else if (A == B || A == C || B == C )
   {
      printf ("Esse triángulo é Isósceles, possuí dois lados iguais \n");
   }
  
  else if ( A != B != C) 
  { 
    printf ("Esse triangulo é Escaleno, possuí três lados diferentes");
  }

  return 0;
}
 
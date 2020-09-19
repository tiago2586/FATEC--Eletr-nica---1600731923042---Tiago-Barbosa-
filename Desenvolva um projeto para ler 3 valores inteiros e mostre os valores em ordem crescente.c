/*Desenvolva um projeto para ler 3 valores inteiros (considere que não serão lidos valores iguais) e
mostre os valores em ordem crescente.*/

#include <stdio.h>

int main (void){
  int A, B, C;

  printf ("Insira três números \n");
  scanf ("%d %d %d", &A, &B, &C);

  if (A <= B && B <= C) 
  {
  printf("A ordem é %.d %.d %.d \n", A, B, C);
  }

  else if (A <= C && C <= B)
  { 
  printf ("A ordem é %.d %.d %.d \n", A, C, B);
  }

    else if (B <= A && A <= C)
  { 
  printf ("A ordem é %.d %.d %.d \n", B, A, C);
  }

    else if (B <= C && C <= A)
  { 
  printf ("A ordem é %.d %.d %.d \n", B, C, A);
  }

    else if (C <= A && A <= B)
  { 
  printf ("A ordem é %.d %.d %.d \n", C, A, B);
  }

    else if (C <= B && B <= A)
  { 
  printf ("A ordem é %.d %.d %.d \n", C, B, A);
  }
  return 0;

}
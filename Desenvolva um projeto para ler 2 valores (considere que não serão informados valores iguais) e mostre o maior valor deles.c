/*Desenvolva um projeto para ler 2 valores (considere que não serão informados valores iguais) e mostre o maior valor deles.*/

#include <stdio.h>

int main (void){
  int A, B;
  printf ("Insira dois números \n");
  scanf ("%d %d", &A, &B);
  if (A > B ) printf ("O digíto mais alto é = %.d\n", A);
  else printf ("O digíto mais alto é = %.d\n", B);
  return 0;

}
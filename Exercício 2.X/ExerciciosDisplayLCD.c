/*******************************************************************************
 FileName:     Exerc�cios de Display LCD - FATEC SANTO ANDR�
 Dependencies: Veja a se��o de includes
 Processor:    PIC18F4550
 Compiler:     MPLAB X v3.65 + XC8 1.40
 Company:      FATEC Santo Andre
 Author:       TIAGO BARBOSA MENDON�A DA SILVA 
 Date:         25/02/2021
 Software License Agreement: Somente para fins did�ticos
 *******************************************************************************
 File Description: Respondendo as tr�s quest�es da aula de Display LCD.
 a)Crie um programa que imprima o seu nome na primeira linha do display e RA 
 normal na segunda linha do display.
 b) Crie um programa que simule um cronometro de segundos. Quando apertamos o 
 bot�o B1 a contagem come�a e quando apertamos o B2 a contagem para. O valor do 
 tempo deve aparecer no display.
 c) Crie um programa que simule um cron�metro, da mesma forma que no item (b)
 .Por�m, na primeira linha do display apresente o valor n�mero do tempo e na 
 segunda linha apresente um gr�fico tipo bargraph que mostra a evolu��o do tempo
 a cada 10 segundos.
 
 Change History:
 1.0   27/02/2021  Vers�o inicial
 
*******************************************************************************/

// Includes do Compilador

#include <xc.h>
#include <stdio.h>
#include <p18f4550.h>

// Includes do Projeto
// Observe que usamos aspas 
//#include "config_4550.h"        //Quando usar o PICSIM LAB
#include "Config.h"           //Quando usar a placa FATEC
#include "displayLCD.h"

//Prot�tipos das Fun��es

void delay_ms(unsigned int tempodeAtraso);
void testa_botao(void);

//=============================================================================

// Define os apelidos das vari�veis do PIC

#define ledRb2  PORTBbits.RB0
#define ledRb3  PORTBbits.RB1
#define ledRb4  PORTBbits.RB2
#define ledRb5  PORTBbits.RB3
#define ledRb6  PORTBbits.RB4
#define ledRb7  PORTBbits.RB5
#define ledRb8  PORTBbits.RB6
#define ledRb9  PORTBbits.RB7   
#define botaoB1 PORTEbits.RE0
#define botaoB2 PORTEbits.RE1
#define botaoB3 PORTEbits.RE2

void main(void) 
{

    ADCON1 = 0x0F; // Define somente as entradas digitais

    TRISB  = 0x00;  // Configura porta B como sa�da
    TRISE  = 0xFF;  // Configura porta E como entrada
 
    
    const unsigned char Texto_0[] = "CRONOMETRO ";
    const unsigned char Texto_1[] = "RA: 731923042 ";
    
    ConfiguraLCD();
    delay_ms(10);
    PosicaoCursorLCD(1, 1);
    EscreveFraseRamLCD(Texto_0);
    PosicaoCursorLCD(2, 1);
    EscreveFraseRamLCD(Texto_1);
    
}







// Esta fun��o � usada para colocar os bytes do PORTB em n�vel baixo quando o
// o bot�o B3 � pressionado.

void testa_botao (void){
                if(botaoB3 == 0)
        {
                    PORTB = 0x00;
            
            
            delay_ms (1000);
                
            while(!botaoB3)
            {
            }
            PORTB = 0XFF;
        }
}

// Esta fun��o � usada para gerar um delay program�vel, cuja base de tempo � de
// 1 ms. Assim, se voc� colocar delay_ms(500), ele esperar� um tempo de 500 ms 
// para seguir o programa.

void delay_ms(unsigned int tempodeAtraso) // Gera delay para o novo compilador
{
    while (--tempodeAtraso) 
    {
        __delay_ms(1);
    }
}


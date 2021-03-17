/*******************************************************************************
 FileName:     SEQUENCIAL DE LEDS - FATEC SANTO ANDR�
 Dependencies: Veja a se��o de includes
 Processor:    PIC18F4550
 Compiler:     MPLAB X v3.65 + XC8 1.40
 Company:      FATEC Santo Andre
 Author:       TIAGO BARBOSA MENDON�A DA SILVA 
 Date:         25/02/2021
 Software License Agreement: Somente para fins did�ticos
 *******************************************************************************
 File Description: Quando pressionamos o bot�o B2 os leds acendem da direita 
 para esquerda e, ap�s o �ltimo led da esquerda, volta a acender o primeiro 
 da direita.
 
 Quando pressionamos o bot�o B3 todos os leds acendem o c�digo bin�rio do seu 
 N2X10+N1, e quando soltamos, os leds continuam no estado que estavam antes do 
 pressionar o bot�o B3.
 N2X10+N1 = 75 > 0100 1011
 
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
    
    while(1)
    {   
       
        PORTB = 0xFF;
       
        if(botaoB2 == 0)
        {
            char vetorLeds = 0x01;
            while (vetorLeds > 0)
            {
               PORTB = ~vetorLeds; 
               vetorLeds = vetorLeds << 1;
               delay_ms(1000);
               testa_botao();
            }

        }
            
    }
}









// Esta fun��o � usada para gerar um delay program�vel, cuja base de tempo � de
// 1 ms. Assim, se voc� colocar delay_ms(500), ele esperar� um tempo de 500 ms 
// para seguir o programa.

void testa_botao (void)
{
    if(botaoB3 == 0)
        {
         PORTB = 0x4B;
         delay_ms (1000);
         while(!botaoB3)
            {
            }
            PORTB = 0XFF;
        }
}

void delay_ms(unsigned int tempodeAtraso) // Gera delay para o novo compilador
{
    while (--tempodeAtraso) 
    {
        __delay_ms(1);
    }
}


/*******************************************************************************
 FileName:     Display Aula 10-03-2021- FATEC SANTO ANDRÉ
 Dependencies: Veja a seção de includes
 Processor:    PIC18F4550
 Compiler:     MPLAB X v3.65 + XC8 1.40
 Company:      FATEC Santo Andre
 Author:       Prof. Edson Kitani
 Date:         10/03/2021
 Software License Agreement: Somente para fins didáticos
 *******************************************************************************
 File Description: Programa para Simular um Cronômetro
 * O botão B1 dispara o cronômetro e o botão B2 para a contagem
 * 
 Change History:
 1.0   10/03/2021  Versão inicial
 
***************************************************************************************/
// Diretivas do Compilador

// Includes do Compilador C e do PIC

#include      <xc.h>
#include      <stdio.h>
#include      <p18f4550.h>

// Includes do Projeto
// Observe que usamos aspas 
//#include "config_4550.h"        //Quando usar o PICSIM LAB
#include "Config.h"           //Quando usar a placa FATEC
#include "displayLCD.h"

//==============================================================================
// Define os apelidos das variáveis do PIC

#define botaoB0           PORTEbits.RE0
#define botaoB1           PORTEbits.RE1
#define botaoB2           PORTEbits.RE2

//Protótipos das Funções

void delay_ms(unsigned int tempodeAtraso);

//================================================================================
//                                                      COMEÇA O PROGRAMA PRINCIPAL 
//================================================================================

void main(void) 
{

const unsigned char Texto_0[] = "FATEC S.A. 2021 ";
const unsigned char Texto_1[] = "  CRONOMETRO    ";
const unsigned char Texto_2[] = "TEMPO = 0      S";
const unsigned char Texto_3[] = "                ";

unsigned int    cronometro = 0;

    ADCON1 = 0x0F; // Define somente as entradas digitais
    TRISB  = 0x00;     // Configura porta B como saída
    TRISE  = 0xFF;      //
  
    
// Configura LCD e tela de saudação
  
    ConfiguraLCD();
    delay_ms(5);
    PosicaoCursorLCD(1,1);
    EscreveFraseRamLCD(Texto_0);
    PosicaoCursorLCD(2,1);
    EscreveFraseRamLCD(Texto_1);
    DesligaCursor();
    delay_ms(3000);
   
    /* ==========================================================================================
      Início do laço infinito
    =========================================================================================*/
    
    while(1)            // Laço infinito
    {
        PosicaoCursorLCD(1,1);
        EscreveFraseRamLCD(Texto_2);
        PosicaoCursorLCD(2,1);
        EscreveFraseRamLCD(Texto_3);
        
        cronometro = 0;
        
        while(!botaoB1 )
        {
      
            while(botaoB2)
            {
                delay_ms(1000);
                cronometro = cronometro + 1;
                PosicaoCursorLCD(1,9);
                EscreveInteiroLCD(cronometro);
                
             }
         }
            
    }
}









// Esta função é usada para gerar um delay programável, cuja base de tempo é de
// 1 ms. Assim, se você colocar delay_ms(500), ele esperará um tempo de 500 ms 
// para seguir o programa.

void delay_ms(unsigned int tempodeAtraso) // Gera delay para o novo compilador
{
    while (--tempodeAtraso) 
    {
        __delay_ms(1);
    }
}
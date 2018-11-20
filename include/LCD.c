// sub rotinas para trabalhar com o lcd com interface de dados de 4 bits

#include "LCD.h"
#include "bitop.h"
#include <string.h>


//c é o dado e cd indica se é instrução ou caractere (0 ou 1) 

void cmd_LCD(unsigned char c, char cd) {
    if(cd == 0) {               // instrução
        clr_bit(CONTR_LCD, RS);
    } else {                    // caractere
        set_bit(CONTR_LCD, RS);
    }

    // primeiro nibble de dados

    #if (nibble_dados)      //compila o código para os pinos de dados do LCD nos 4 MSB do PORT
        DADOS_LCD = (DADOS_LCD & 0x0F) | (0xF0 & c);
    #else
        DADOS_LCD = (DADOS_LCD & 0xF0) | (c>>4);
    #endif

    pulso_enable();
    
    //segundo nibble de dados
    
    #if (nibble_dados)      //compila o código para os pinos de dados do LCD nos 4 MSB do PORT
        DADOS_LCD = (DADOS_LCD & 0x0F) | (0xF0 & (c<<4));
    #else                   //compila o código para os pinos de dados do LCD nos 4 LSB do PORT
        DADOS_LCD = (DADOS_LCD & 0xF0) | (0x0F & c);
    #endif
        
    pulso_enable();

    if((cd==0) && (c<4))    //se for instrução de retorno ou limpeza espera LCD estar pronto
        _delay_ms(2);
}

void inic_LCD_4bits(){     
    //sequência ditada pelo fabricando do circuito integrado HD44780
    //o LCD será só escrito. Então, R/W é sempre zero. 
    
    clr_bit(CONTR_LCD, RS);
    clr_bit(CONTR_LCD, E);

    _delay_ms(20);

    #if (nibble_dados)
        DADOS_LCD = (DADOS_LCD & 0x0F) | 0x20;
    #else
        DADOS_LCD = (DADOS_LCD & 0xF0) | 0x02;
    #endif

    pulso_enable();
    cmd_LCD(0x28,0);    //habilita as duas linhas e envia os 2 nibbles, (0x2 e 0x8)

    cmd_LCD(0x08,0);    // desliga display
    cmd_LCD(0x01,0);    // limpa display
    cmd_LCD(0x0C,0);    // mensagem aparente cursor inativo não piscando
    cmd_LCD(0x80,0);    // inicializa cursor na primeira posição
}

//------------------------------------------------------------------------------------
//Sub-rotina de escrita no LCD - dados armazenados na RAM
//------------------------------------------------------------------------------------

void escreve_LCD(char *c)
{
    for (; *c!=0;c++) {
        cmd_LCD(*c,1);
    }
}

//------------------------------------------------------------------------------------
//Sub-rotina de escrita no LCD - dados armazenados na FLASH
//------------------------------------------------------------------------------------

void escreve_LCD_Flash(const char *c)
{
    for (;pgm_read_byte(&(*c))!=0;c++){
        cmd_LCD(pgm_read_byte(&(*c)),1); 
    } 
}

// função para converter int para string, itoa() do <string.h>
void itos(int n, char s[]) {
    int i, sign, j;
    char c;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {                         /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    
    // reverte a "palavra" escrita invertida
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
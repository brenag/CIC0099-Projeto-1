/*
Aluno: Emanuel Couto Brenag
Matrícula: 190057131
Disciplina: Organização e Arquitetura de Computadores
Turma: C
IDE: Visual Studio Code
Sistema Operacional: Windows 10
Compilador: gcc
*/

#include <stdio.h>
#include <stdint.h>

#include "funcoes.h"

int main()
{
    int i;
    for(i=0; i<MEM_SIZE; i++)
    {   
        mem[i] = 0;  
    }
    teste_prof();
    teste_aluno();
    return 0;
}

int32_t lw(uint32_t address, int32_t kte)
{ 
    int32_t lw_address = address + kte;
    int32_t indice;
    indice = lw_address/4;
    if (address % 4 != 0 || lw_address % 4 != 0)  // testa se o endereço e o endereço+kte é divisível por 4
    {
        printf("O endereco escolhido nao e valido, pois nao e multiplo de 4! \n");
        return 0; //se não for, retorna 0
    }

    else if (indice >= MEM_SIZE || indice < 0) //verifica se existe um índice na memória para esse endereço
    {
        printf("o endereco escolhido esta alem da memoria! \n");
        return 0;
    }
    else
    {
        return mem[indice]; //retorna a palavra no endereço de memória selecionado
    }
}

int32_t lbu(uint32_t address, int32_t kte)
{   
    int32_t lbu_address = address + kte;
    int32_t indice = lbu_address/4;
    if (kte > 3 || kte < 0) //teste se kte está entre 0 e 3
    {
        printf("O indice deve ser um numero de 0 a 3!\n");
        return 0;
    }

    else if (address % 4 != 0) //testa se o endereço fornecido é um número múltiplo de 4
    {
        printf("O endereco escolhido nao e valido, pois nao e multiplo de 4! \n");
        return 0; 
    }

    else if (indice >= MEM_SIZE || indice < 0 ) //verifica se existe um índice na memória para esse endereço
    {
        printf("O endereco escolhido esta alem da memoria! \n");
        return 0;
    }

    else
    {
        uint8_t value = *((char *)mem + (address + kte)); //converte o vetor de palavras em char (1byte), pega o char e reconverte para inteiro sem sinal de 1 byte.
        return (int32_t) value; //faz o typecast no inteiro de 8 para 32 bits para extender o sinal 0.
    }
    
}


int32_t lb(uint32_t address, int32_t kte)
{   
    int32_t lb_address = address + kte;
    int32_t indice = lb_address/4;

    if (kte > 3 || kte < 0)
    {
        printf("O indice deve ser um numero de 0 a 3!\n");
        return 0;
    }

    else if (address % 4 != 0)
    {
        printf("O endereco escolhido nao e valido, pois nao e multiplo de 4! \n");
        return 0; //se não for, retorna 0
    }

    else if (indice >= MEM_SIZE || indice < 0)
    {
        printf("O endereco escolhido esta alem da memoria! \n");
        return 0;
    }

    else
    {
        int8_t value = *((char *)mem + (address + kte)); //converte o vetor de palavras em char (1byte), pega o char do byte selecionado da word selecionada e reconverte para inteiro sem sinal de 1 byte.
        return (int32_t) value; //faz o type cast de 8 pra 32 bits, extendendo o sinal do bit mais significativo
    }
}

void sw(uint32_t address, int32_t kte, int32_t dado)
{
    int32_t sw_address = address + kte;
    int32_t indice;
    indice = sw_address/4;

    if (address %4 != 0 || sw_address % 4 != 0)//verifica se o endereço é um múltiplo de 4
    {
        printf("O endereco escolhido nao e valido, pois nao e multiplo de 4! \n");
        return;
    }
    else if (indice >= MEM_SIZE || indice < 0) //verifica se existe um índice na memória para esse endereço
    {
        printf("O endereco escolhido esta alem da memoria! \n");
        return;
    }
    
    else
    {
        mem[indice] = dado; //armazena a palavra no endereço selecionado
    }

}

void sb(uint32_t address, int32_t kte, int8_t dado)
{
    int32_t sb_address = address + kte;
    int32_t indice = sb_address/4;
    
    if (kte > 3 || kte < 0) //verifica se kte está entre 0 e 3
    {
        printf("O indice deve ser um numero de 0 a 3!\n");
        return;
    }

    else if (address % 4 != 0) //verifica se o endereço fornecido é múltiplo de 4
    {
        printf("O endereco escolhido nao e valido, pois nao e multiplo de 4! \n"); 
        return; //se não for, retorna 0
    }
    
    else if (indice >= MEM_SIZE || indice < 0) // verifica se o endereço fornecido está dentro da memória
    {
        printf("O endereco escolhido esta alem da memoria! \n");
        return;
    }
    else
    {
        int8_t *sb_address = (int8_t*) ((char *)mem + (address + kte)); //converte o vetor de palavras em char e passa o endereço do byte selecionado para um ponteiro, reconvertendo para vetor de inteiros de 1 byte.
        *sb_address = dado; //salva o dado do byte escolhido no endereço selecionado (que agora é o endereço do ponteiro)
    }
}


void teste_prof() //Testes sugeridos pelo professor
{   
    //Iniciar a Memória
    sb(0, 0, 0x04);
    sb(0, 1, 0x03);
    sb(0, 2, 0x02);
    sb(0, 3, 0x01);
    sb(4, 0, 0xFF);
    sb(4, 1, 0xFE);
    sb(4, 2, 0xFD);
    sb(4, 3, 0xFC);
    sw(12, 0, 0xFF);
    sw(16, 0, 0xFFFF);
    sw(20, 0, 0xFFFFFFFF);
    sw(24, 0, 0x80000000);
    
    //printa a memória
    printf("Testes da memoria\n");
    for (int i = 0; i < 7; i++)
    {
        printf("mem[%i] = %08x\n", i, mem[i]);    
    }
    printf("Testes de Load Byte\n");
    for (int j = 0; j < 4; j++)
    {
        printf("%x\n",lb(4,j));    
    }
    printf("Testes de Load Byte Unsigned\n");
    for (int k = 0; k < 4; k++)
    {
        printf("%08x\n",lbu(4,k));    
    }
    printf("Testes de Load Word\n");
    for (int l = 12; l < 21; l = l+4)
    {
        printf("%08x\n",lw(l,0));    
    }    
}

void teste_aluno() //Testes extra que foram desenvolvidos pelo aluno para testar o funcionamento do código
{
    printf("Teste de  LSM e MSB no modelo Little Endian\n"); //verifica se o byte carregado está na posição certa de acordo com o padrão Little Endian do RISC-V


    sw(0, 0, 0x000000FF);
    printf("\nResultado esperado: ffffffff\n Resultado obtido: %08x\n", lb(0, 0));
    printf("\nResultado esperado: 00000000\n Resultado obtido: %08x\n", lb(0, 3));

    sw(0, 0, 0x12345678);
    printf("\nResultado esperado: 00000078\n Resultado obtido: %08x\n", lb(0, 0));
    printf("\nResultado esperado: 00000012\n Resultado obtido: %08x\n", lb(0, 3));

    printf("\nTeste de extensao do sinal (comparando lbu com lb)\n");
    sw(0, 0, 0x001230f0);
    printf("\nResultado esperado: 000000f0\n Resultado obtido: %08x\n", lbu(0, 0));
    printf("\nResultado esperado: fffffff0\n Resultado obtido: %08x\n", lb(0, 0));

    sw(0, 0, 0x00123012);
    printf("\nResultado esperado: 00000012\n Resultado obtido: %08x\n", lbu(0, 0));
    printf("\nResultado esperado: 00000012\n Resultado obtido: %08x\n", lb(0, 0));

    printf("\nTeste induzindo o erro com enderecos impares, alem do limite de armazenamento ou negativos\n");


    printf("\nTestes com lw:\n");
    lw(16384, 0);// endereço além da memória
    lw(0, 16384);// endereço além da memória
    lw(0, 3);// endereço não múltiplo de 4
    lw(5, 0);// endereço não múltiplo de 4
    lw(-24, 0); //endereço negativo
    lw(-44, 0); //endereço negativo

    printf("\nTestes com lbu:\n");
    lbu(0, 5);// kte maior que 3
    lbu(0, -3);// kte negativo
    lbu(16384, 3);// endereço além da memória
    lbu(24000, 0);// endereço além da memória
    lbu(-28, 0); //endereço negativo
    lbu(-40, 0); //endereço negativo

    printf("\nTestes com lb:\n");
    lb(0, 5);// kte maior que 3
    lb(0, -3);// kte negativo
    lb(16384, 3);// endereço além da memória
    lb(24000, 0);// endereço além da memória
    lb(-28, 0); //endereço negativo
    lb(-40, 0); //endereço negativo

    printf("\nTeste com sw:\n");
    sw(16384, 0, 0xFF);// endereço além da memória
    sw(0, 16384, 0xFF);// endereço além da memória
    sw(0, 3, 0xFF);// endereço não múltiplo de 4
    sw(5, 0, 0xFF);// endereço não múltiplo de 4
    sw(-24, 0, 0xFF); //endereço negativo
    sw(-44, 0, 0xFF); //endereço negativo

    printf("\nTeste de Armazenamento e Leitura de Numeros Negativos\n");


    sw(12, 0, -2567);
    printf("\nResultado esperado = fffff5f9 \n Resultado obtido = %x\n", lw(12, 0));
    printf("\nResultado esperado = fffffff9 \n Resultado obtido = %x\n", lb(12, 0));
    printf("\nResultado esperado = 000000f9 \n Resultado obtido = %08x\n", lbu(12, 0));

    sw(0, 0, -664016);
    printf("\nResultado esperado = fff5de30 \n Resultado obtido = %x\n", lw(0, 0));
    printf("\nResultado esperado = 00000030 \n Resultado obtido = %08x\n", lb(0, 0));
    printf("\nResultado esperado = 00000030 \n Resultado obtido = %08x\n", lbu(0, 0));
}

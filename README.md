# CIC0099 - Projeto-1
O projeto consiste em uma simulação das instruções de acesso à memória do RISC-V RV32I em linguagem C para a disciplina de Organização e Arquitetura de Computadores da Universidade de Brasília.

Descrição do Projeto 
=================
<!--ts-->
   * [Funções](#Funções)
      * [Load Word](#pre-requisitos): Calcula o endereço da palavra somando os parâmetros address + kte, checa se o endereço é múltiplo de 4 e retorna o inteiro alinhado (word de 4 bytes) que foi lido na memória;
      * [Load Byte](#local-files):  Faz um type cast no endereço da memória do byte escolhido e retorna-o, estendendo o sinal para 32 bits;
      * [Load Byte Unsigned](#remote-files): Assim como o load byte, lê o byte e retorna-o como número positivo, ou seja, zerando todos os bits superiores.
      * [Store Word](#multiple-files): Escreve um inteiro alinhado (word de 4 bytes) em um endereço múltiplo de 4, calculando-o de maneira similar à load word;
      * [Store Byte](#combo): Escreve um byte na memória diretamente na posição escolhida.
<!--te-->

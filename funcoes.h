#ifndef __funcoes_H__
#define __funcoes_H__

//inicia a memoria do RISCV
#define MEM_SIZE 4096
int32_t mem[MEM_SIZE];

//funções de acesso à memória
int32_t lw(uint32_t address, int32_t kte);
int32_t lb(uint32_t address, int32_t kte);
int32_t lbu(uint32_t address, int32_t kte);
void sw(uint32_t address, int32_t kte, int32_t dado);
void sb(uint32_t address, int32_t kte, int8_t dado);

//funções de teste criadas sugeridas pelo aluno e pelo professor
void teste_prof();
void teste_aluno();

#endif
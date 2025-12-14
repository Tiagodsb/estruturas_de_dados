# Arrays e Listas em C

Este módulo cobre os conceitos básicos de arrays e listas ligadas,
com implementações em linguagem C focadas no entendimento do funcionamento interno
das estruturas de dados.

## Objetivos
- Entender como arrays funcionam na memória
- Trabalhar com alocação estática e dinâmica
- Implementar listas ligadas do zero
- Praticar manipulação de ponteiros

## Conteúdo estudado

### 1. Arrays
- Declaração e inicialização
- Acesso por índice
- Percurso e manipulação
- Limitações de tamanho

Arquivos:
- `array_basico.c`

### 2. Listas Ligadas
- Estrutura de nó (`struct`)
- Ponteiros e encadeamento
- Inserção no início
- Remoção de elementos
- Percurso da lista

Arquivos:
- `lista_ligada.c`

## Decisões de implementação
- As listas foram implementadas sem uso de bibliotecas externas
- A alocação de memória é feita manualmente com `malloc` e `free`
- O código prioriza clareza em vez de otimizações prematuras

## Como compilar e executar

Exemplo usando `gcc`:

```bash
gcc array_basico.c -o array_basico
./array_basico

gcc lista_ligada.c -o lista_ligada
./lista_ligada
#ifndef PRODUTO_H
#define PRODUTO_H
#define TAM 4

typedef struct
{
  int id;
  char nome[60];
  float preco;
  int quantidade;
} Produto;

int addProduto(Produto **estoque, int *quantidade, int *capacidade);

#endif

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

int adicionarProduto(Produto **estoque, int *quantidade, int *capacidade);
Produto *buscarProduto(Produto **estoque, int *quantidade, int id, int num);
int removerProduto(Produto **estoque, int *quantidade, int id);
#endif

#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int adicionarProduto(Produto **estoque, int *quantidade, int *capacidade)
{
  Produto *temp;

  if (*capacidade == 0)
  {
    *capacidade = 2;
    *estoque = malloc(*capacidade * sizeof(Produto));

    if (*estoque == NULL)
    {
      printf("Erro ao alocar memoria ------------> adicionarProduto\n");
      return 1;
    }
  }
  else if (*quantidade == *capacidade)
  {
    *capacidade += 2;
    temp = realloc(*estoque, *capacidade * sizeof(Produto));

    if (temp == NULL)
    {
      printf("Erro ao realocar memoria ------------> adicionarProduto\n");
      *capacidade -= 2;
      return 1;
    }

    *estoque = temp;
  }

  Produto *produto = &(*estoque)[*quantidade];

  if (*quantidade == 0)
  {
    produto->id = 1;
  }
  else
  {
    produto->id = (*estoque)[*quantidade - 1].id + 1;
  }

  printf("\n===== CADASTRO DE PRODUTO =====\n");
  printf("ID: %d\n", produto->id);
  printf("Nome: ");
  scanf(" %59[^\n]", produto->nome);
  printf("Preco: R$");
  scanf("%f", &produto->preco);
  printf("Quantidade: ");
  scanf("%d", &produto->quantidade);

  (*quantidade)++;

  return 0;
}

Produto *buscarProduto(Produto **estoque, int *quantidade, int id, int num)
{
  Produto *produto = &(*estoque)[num];

  if (num >= *quantidade)
  {
    return NULL;
  }

  if (produto->id == id)
  {
    printf("\n=====PRODUTO ENCONTRADO =====\n");
    printf("índice: %d\n", num);
    printf("ID: %d\n", produto->id);
    printf("Nome: %s\n", produto->nome);
    printf("Preco: R$ %.2f\n", produto->preco);
    printf("Quantidade: %d", produto->quantidade);
    printf("\n==============================\n");

    return &(*estoque)[num];
  }

  return buscarProduto(estoque, quantidade, id, num + 1);
}

int removerProduto(Produto **estoque, int *quantidade, int id)
{
  int posicao = 0;

  Produto *produto = buscarProduto(estoque, quantidade, id, 0);

  if (produto == NULL)
  {
    printf("\nProduto não encontrado.\n");
    return 1;
  }

  posicao = produto - *estoque;

  for (int i = posicao; i < *quantidade - 1; i++)
  {
    (*estoque)[i] = (*estoque)[i + 1];
  }

  (*quantidade)--;

  return 0;
}

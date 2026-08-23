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
      printf("Erro ao alocar memoria ------------> AddProdutos\n");
      return 1;
    }
  }
  else if (*quantidade == *capacidade)
  {
    *capacidade += 2;
    temp = realloc(*estoque, *capacidade * sizeof(Produto));

    if (temp == NULL)
    {
      printf("Erro ao realocar memoria ------------> AddProdutos\n");
      *capacidade -= 2;
      return 1;
    }

    *estoque = temp;
  }

  (*estoque)[*quantidade].id = *quantidade + 1;

  printf("\n===== CADASTRO DE PRODUTO =====\n");
  printf("ID: %d\n", (*estoque)[*quantidade].id);
  printf("Nome: ");
  scanf(" %59[^\n]", (*estoque)[*quantidade].nome);
  printf("Preco: R$");
  scanf("%f", &(*estoque)[*quantidade].preco);
  printf("Quantidade: ");
  scanf("%d", &(*estoque)[*quantidade].quantidade);

  (*quantidade)++;

  return 1;
}

Produto *buscarProduto(Produto **estoque, int *quantidade, int id, int num)
{
  if (num >= *quantidade)
  {
    return NULL;
  }

  if ((*estoque)[num].id == id)
  {
    printf("\n=====PRODUTO ENCONTRADO =====\n");
    printf("índice: %d\n", num);
    printf("ID: %d\n", (*estoque)[num].id);
    printf("Nome: %s\n", (*estoque)[num].nome);
    printf("Preco: R$ %2.f\n", (*estoque)[num].preco);
    printf("Quantidade: %d", (*estoque)[num].quantidade);
    printf("\n==============================\n");

    return &(*estoque)[num];
  }

  return buscarProduto(estoque, quantidade, id, num + 1);
}

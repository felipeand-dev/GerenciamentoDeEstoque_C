#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int addProduto(Produto **estoque, int *quantidade, int *capacidade)
{
  Produto *temp;

  if (*capacidade == 0)
  {
    *capacidade = 2;
    *estoque = malloc(*capacidade * sizeof(Produto));

    if (*estoque == NULL)
    {
      printf("Erro ao alocar memoria\n");
      return 0;
    }
  }
  else if (*quantidade == *capacidade)
  {
    *capacidade += 2;
    temp = realloc(*estoque, *capacidade * sizeof(Produto));

    if (temp == NULL)
    {
      printf("Erro ao realocar memoria\n");
      *capacidade -= 2;
      return 0;
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

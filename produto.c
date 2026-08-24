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

void listarProdutos(const Produto *estoque, int quantidade, int indice)
{
  if (indice >= quantidade)
  {
    return;
  }

  printf("\nProduto %d\n", indice + 1);
  printf("ID: %d\n", estoque[indice].id);
  printf("Nome: %s\n", estoque[indice].nome);
  printf("Preco: R$ %.2f\n", estoque[indice].preco);
  printf("Quantidade: %d\n", estoque[indice].quantidade);

  listarProdutos(estoque, quantidade, indice + 1);
}

float calcularValorEstoque(const Produto *estoque, int quantidade, int indice)
{
  if (indice >= quantidade)
  {
    return 0.0f;
  }

  return estoque[indice].preco * estoque[indice].quantidade +
         calcularValorEstoque(estoque, quantidade, indice + 1);
}

void ordenarProdutosPorPreco(Produto *estoque, int quantidade)
{
  for (int i = 0; i < quantidade - 1; i++)
  {
    for (int j = 0; j < quantidade - i - 1; j++)
    {
      if (estoque[j].preco > estoque[j + 1].preco)
      {
        Produto temp = estoque[j];
        estoque[j] = estoque[j + 1];
        estoque[j + 1] = temp;
      }
    }
  }
}

Produto *buscarProduto(Produto **estoque, int *quantidade, int id, int num)
{
  if (num >= *quantidade)
  {
    return NULL;
  }

  Produto *produto = &(*estoque)[num];

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

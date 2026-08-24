#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main()
{
  Produto *estoque = NULL;

  int capacidade = 0;
  int quantidade = 0;
  int select = 0;

  system("clear");

  do
  {
    printf("\n");
    printf("╔══════════════════════════════════════════════════╗\n");
    printf("║               MERCADO - PREÇO BAIXO              ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║                       MENU                       ║\n");
    printf("╠══════════════════════════════════════════════════╣\n");
    printf("║  [1] 📦  Cadastrar novo produto                  ║\n");
    printf("║  [2] ❌  Remover produto por ID                  ║\n");
    printf("║  [3] 📋  Listar todos os produtos                ║\n");
    printf("║  [4] 🔍  Buscar produto por ID                   ║\n");
    printf("║  [5] 📊  Ordenar produtos por preço              ║\n");
    printf("║  [6] 💰  Calcular valor total do estoque         ║\n");
    printf("║  [7] 🚪  Encerrar programa                       ║\n");
    printf("╚══════════════════════════════════════════════════╝\n");
    printf("\n");

    printf("  Digite uma opcao: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
    {
      int num = 0;

      system("clear");
      do
      {
        if (adicionarProduto(&estoque, &quantidade, &capacidade))
        {
          printf("Falha na alocacao. Encerrando cadastro\n");
          break;
        }

        printf("\nDeseja add mais produtos?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        printf("Opcao: ");
        scanf("%d", &num);

        if (num == 0)
        {
          system("clear");
        }

      } while (num == 1);
      break;
    }

    case 2:
    {
      int id = 0;
      int num2 = 0;

      system("clear");

      do
      {
        printf("\n");
        printf("========================================\n");
        printf("          REMOVER PRODUTO\n");
        printf("========================================\n");

        printf("\nDigite o ID do produto que deseja remover: ");
        scanf("%d", &id);

        if (removerProduto(&estoque, &quantidade, id))
        {
          printf("\nFalha ao remover produto.\n");
        }
        else
        {
          printf("\nProduto removido com sucesso!\n");
        }

        printf("\nDeseja remover mais produtos?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        printf("Opcao: ");
        scanf("%d", &num2);

        if (num2 == 0)
        {
          system("clear");
        }

      } while (num2 == 1);
      break;
    }
case 3:
{
    printf("\n========================================\n");
    printf("          LISTA DE PRODUTOS\n");
    printf("========================================\n");

    if (quantidade == 0)
    {
        printf("\nNenhum produto cadastrado.\n");
    }
    else
    {
        listarProdutos(estoque, quantidade, 0);
    }

    printf("\n========================================\n");

    break;
}

    case 4:
    {
      int id = 0;
      int num4 = 0;

      system("clear");

      do
      {
        printf("\n");
        printf("========================================\n");
        printf("           BUSCAR PRODUTO\n");
        printf("========================================\n");

        printf("\nDigite o ID do produto que deseja buscar: ");
        scanf("%d", &id);

        Produto *produto = buscarProduto(&estoque, &quantidade, id, 0);

        if (produto == NULL)
        {
          printf("\nProduto nao encontrado.\n");
        }

        printf("\nDeseja buscar mais produtos?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        printf("Opcao: ");
        scanf("%d", &num4);

        if (num4 == 0)
        {
          system("clear");
        }

      } while (num4 == 1);

      break;
    }
    case 5:
      break;

    case 6:
{
    float total;

    printf("\n========================================\n");
    printf("       VALOR TOTAL DO ESTOQUE\n");
    printf("========================================\n");

    total = calcularValorEstoque(estoque, quantidade, 0);

    printf("\nValor total do estoque: R$ %.2f\n", total);

    printf("\n========================================\n");

    break;
}

    case 7:
      printf("Encerrando programa...\n");
      break;

    default:
      printf("Opcao invalida\n");
    }
  } while (select != 7);

  free(estoque);

  return 0;
}

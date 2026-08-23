#include <stdio.h>
#include <stdlib.h>
#include "produto.h"

int main()
{
  Produto *estoque = NULL;

  int capacidade = 0;
  int quantidade = 0;
  int select = 0;

  printf("\n");
  printf("========================================\n");
  printf("          MERCADO - PRECO BAIXO         \n");
  printf("========================================\n");
  printf("\n");
  printf("                MENU\n");
  printf("----------------------------------------\n");
  printf("  [1] Cadastrar produto\n");
  printf("  [2] Remover produto por ID\n");
  printf("  [3] Listar todos os produtos\n");
  printf("  [4] Buscar produto por ID\n");
  printf("  [5] Ordenar produtos por preco\n");
  printf("  [6] Calcular valor total do estoque\n");
  printf("  [7] Encerrar programa\n");
  printf("----------------------------------------\n");
  printf("\n");

  do
  {
    printf("  Digite uma opcao: ");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
      int num = 0;
      do
      {
        if (!addProduto(&estoque, &quantidade, &capacidade))
        {
          printf("Falha na alocacao. Encerrando cadastro\n");
          break;
        }

        printf("\nDeseja add mais produtos?\n");
        printf("1 - Sim\n");
        printf("0 - Nao\n");
        printf("Opcao: ");
        scanf("%d", &num);
      } while (num == 1);
      break;

    case 2:
      break;

    case 3:
      break;

    case 4:
      break;

    case 5:
      break;

    case 6:
      break;

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

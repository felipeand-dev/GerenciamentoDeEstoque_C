# 📦 Mercado — Sistema de Gerenciamento de Estoque

Sistema de **Gerenciamento de Estoque de Produtos**, desenvolvido em linguagem C para o trabalho da disciplina de **Estrutura de Dados**.

O projeto foi desenvolvido com foco na aplicação integrada de:

* `structs`
* Alocação dinâmica de memória (`malloc`, `realloc` e `free`)
* Funções recursivas
* Ponteiros
* Modularização em arquivos `.h` e `.c`

## 👥 Integrantes

* **Felipe Andrade dos Santos Carvalho**
* **João Fernandes Neto**
* **João Luiz Matos Ferreira**

## 🎯 Objetivo

O projeto simula o controle de estoque de uma loja, permitindo cadastrar, buscar, remover, listar e organizar produtos, além de calcular o valor total armazenado em estoque.

Cada produto é representado por uma `struct` contendo:

* **ID** — identificador único do produto
* **Nome** — nome do produto
* **Preço** — preço unitário
* **Quantidade** — quantidade disponível em estoque

Os produtos são armazenados em um **vetor alocado dinamicamente**, cuja capacidade é aumentada com `realloc()` conforme necessário.

## 🧠 Conceitos utilizados

### Struct

A estrutura `Produto` organiza as informações de cada produto:

```c
typedef struct
{
    int id;
    char nome[60];
    float preco;
    int quantidade;
} Produto;
```

### 💾 Alocação dinâmica

O vetor de produtos é criado dinamicamente utilizando `malloc()` e aumentado quando sua capacidade é atingida utilizando `realloc()`.

Ao finalizar o programa, a memória utilizada pelo estoque é liberada com `free()`.

### 🔄 Recursão

O projeto utiliza funções recursivas para operações exigidas pelo trabalho, incluindo:

* Listagem dos produtos
* Busca de produto por ID
* Cálculo do valor total do estoque

As funções recursivas possuem um **caso base** e um **caso recursivo**, conforme solicitado no enunciado.

## 📋 Funcionalidades

O sistema possui um menu com as seguintes operações:

```text
[1] 📦 Cadastrar novo produto
[2] ❌ Remover produto por ID
[3] 📋 Listar todos os produtos
[4] 🔍 Buscar produto por ID
[5] 📊 Ordenar produtos por preço
[6] 💰 Calcular valor total do estoque
[7] 🚪 Encerrar programa
```

### 1. Cadastrar produto

Permite inserir novos produtos no estoque.

O vetor é criado ou redimensionado automaticamente conforme a quantidade de produtos cadastrados.

### 2. Remover produto por ID

Localiza um produto através do seu ID e remove-o do vetor, reorganizando os elementos restantes.

### 3. Listar produtos

Exibe todos os produtos cadastrados no estoque utilizando uma função recursiva para percorrer o vetor.

### 4. Buscar produto por ID

Realiza uma busca recursiva pelo ID do produto e exibe suas informações quando encontrado.

### 5. Ordenar produtos por preço

Organiza os produtos de acordo com o preço utilizando um algoritmo de ordenação.

### 6. Calcular valor total do estoque

Calcula o valor total considerando:

```text
preço × quantidade
```

de cada produto.

A soma é realizada através de uma função recursiva.

### 7. Encerrar programa

Finaliza a execução e libera a memória alocada dinamicamente.

## 📁 Estrutura do projeto

```text
Trabalho_ETRTRA/
│
├── main.c
├── produto.c
├── produto.h
└── README.md
```

### `main.c`

Responsável pelo menu principal e pela interação com o usuário.

### `produto.h`

Contém a definição da `struct Produto` e os protótipos das funções utilizadas pelo sistema.

### `produto.c`

Contém a implementação das funções de gerenciamento dos produtos, incluindo as funções recursivas e operações envolvendo alocação dinâmica.

## ⚙️ Compilação

Para compilar o projeto utilizando o GCC:

```bash
gcc -Wall -Wextra -g main.c produto.c -o mercado
```

Após a compilação, execute:

```bash
./mercado
```

### 🔎 Compilação recomendada

A opção `-Wall -Wextra` habilita avisos adicionais do compilador, ajudando a identificar possíveis problemas no código.

A opção `-g` adiciona informações de depuração ao executável, facilitando o uso de ferramentas como o GDB.

## ▶️ Como utilizar

Após executar o programa, será apresentado o menu principal:

```text
╔══════════════════════════════════════════════════╗
║               MERCADO - PREÇO BAIXO              ║
╠══════════════════════════════════════════════════╣
║                       MENU                       ║
╠══════════════════════════════════════════════════╣
║  [1] 📦  Cadastrar novo produto                  ║
║  [2] ❌  Remover produto por ID                  ║
║  [3] 📋  Listar todos os produtos                ║
║  [4] 🔍  Buscar produto por ID                   ║
║  [5] 📊  Ordenar produtos por preço              ║
║  [6] 💰  Calcular valor total do estoque         ║
║  [7] 🚪  Encerrar programa                       ║
╚══════════════════════════════════════════════════╝
```

Digite o número correspondente à operação desejada e siga as instruções exibidas pelo programa.

## 🛠️ Tecnologias

* **Linguagem:** C
* **Compilador:** GCC
* **Controle de versão:** Git
* **Repositório:** GitHub

## 📚 Trabalho acadêmico

Projeto desenvolvido para a disciplina de **Estrutura de Dados**, com foco em:

* Estruturas (`struct`)
* Ponteiros
* Alocação dinâmica
* `malloc()`
* `realloc()`
* `free()`
* Recursão
* Modularização de código

O trabalho também exige que o código seja entregue compilando sem erros ou warnings e sem vazamentos de memória.

## 👨‍💻 Desenvolvimento

Projeto acadêmico desenvolvido em equipe como parte das atividades da disciplina de Estrutura de Dados.

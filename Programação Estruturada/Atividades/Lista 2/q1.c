#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // Pra usar o sleep em sistemas unix
#define N 10

int busca_sequencial(int v[], int n, int x) {
  int pos = -1;

  for (int i = 0; i < n; i++) {
    if (v[i] == x) {
      pos = i;
      break;
    }
  }

  return pos;
}

int busca_binaria(int v[], int n, int x) {
  // Busca binária precisa ser em um vetor ordenado
  int pos = -1;
  int inicio = 0;
  int fim = n - 1;

  while (inicio <= fim) {
    int meio = (inicio + fim) / 2;

    if (v[meio] == x) {
      pos = meio;
      break;
    } else {
      if (v[meio] < x) {
        inicio = meio + 1;
      } else {
        fim = meio - 1;
      }
    }
  }

  return pos;
}

void selection_sort(int v[], int n) {
  int i, j, menor, temp;

  for (int i = 0; i < n-1; i++) {
    menor = i;
    for (j = i+1; j < n; j++) {
      if (v[j] < v[menor]) {
        menor = j;
      }
    }

    temp = v[i];
    v[i] = v[menor];
    v[menor] = temp;
  }
}

void bubble_sort(int v[], int n) {
  int i, j, menor, temp;

  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (v[j] > v[j+1]) {
        temp = v[j];
        v[j] = v[j+1];
        v[j+1] = temp;
      }
    }
  }
}

void printa_menu(int opcao_menu) {
  char menu_inicial[] = "\n#############################################\n\n" \
                 "Selecione um vetor de teste:\n" \
                 "[1] = {64, 9, 21, 53, 78, 12, 40, 93, 36, 80}\n" \
                 "[2] = {10, 50, 75, 2, 88, 33, 61, 95, 17, 48}\n" \
                 "[3] = {85, 31, 99, 14, 57, 42, 70, 6, 23, 91}\n" \
                 "[4] = {5, 69, 18, 97, 30, 82, 45, 1, 72, 55}\n" \
                 "[5] = Criar um vetor...\n" \
                 "\n[0] = Sair\n" \
                 "\n#############################################\n\n> ";

  char menu_criar_vetor[] = "Digite os valores para v:\n> ";

  char menu_algoritmo[] = "\n######################################\n\n" \
                 "Escolha o algoritmo que deseja testar:\n" \
                 "[1] = Busca sequencial\n" \
                 "[2] = Busca binária\n" \
                 "[3] = Selection sort\n" \
                 "[4] = Bubble sort\n" \
                 "\n[0] = Voltar ao menu anterior\n" \
                 "\n######################################\n\n> ";

  if (opcao_menu == 0) {
    printf("%s", menu_inicial);
  }
  if (opcao_menu == 1) {
    printf("%s", menu_criar_vetor);
  }
  if (opcao_menu == 2) {
    printf("%s", menu_algoritmo);
  }
}

void limpar_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
    // Consome os caracteres até o fim da linha/arquivo
  }
}

int main() {
  // Loop principal
  while (1) {
    int volta_loop = 0;
    int v[N];
    int opcao = -1;
    printa_menu(0);

    // Limpando buffer caso scanf não tenha sucesso
    if (scanf("%d", &opcao) != 1) {
      limpar_buffer();
      opcao = -1; // Setando para uma opção inválida
    }

    // Criamos o vetor v[10], mas só vai ser possível adicionar
    // elementos retroativamente através de loop ou do memcpy()
    // (mais rápido e idiomático)
    switch (opcao) {
      case 0:
        printf("Obrigado!\n");
        exit(0);
      case 1:
        memcpy(v, (int[]){64, 9, 21, 53, 78, 12, 40, 93, 36, 80}, sizeof(v));
        break;
      case 2:
        memcpy(v, (int[]){10, 50, 75, 2, 88, 33, 61, 95, 17, 48}, sizeof(v));
        break;
      case 3:
        memcpy(v, (int[]){85, 31, 99, 14, 57, 42, 70, 6, 23, 91}, sizeof(v));
        break;
      case 4:
        memcpy(v, (int[]){5, 69, 18, 97, 30, 82, 45, 1, 72, 55}, sizeof(v));
        break;
      case 5:
        // Recebendo valores do usuário
        printf("\nDigite 10 valores para v[]:\n");
        for (int i = 0; i < N; i++) {
          scanf("%d", &v[i]);
        }
        // Printando o que foi lido
        printf("\nv[] = ");
        for (int i = 0; i < N; i++) {
          printf("%d ", v[i]);
        }
        printf("\n");
        break;
      default:
        printf("ERRO! Opção inválida\n");
        volta_loop = 1;
        break;
    }

    // Se input for inválido, voltar ao loop inicial
    if (volta_loop == 1) {
      continue;
    }

    // Variáveis necessárias para operações
    int x;
    int pos;
    // Variável de controle do while (1)
    int terminar_loop = 0;

    while (1) {
      printa_menu(2);

      // Limpando buffer caso scanf não tenha sucesso
      if (scanf("%d", &opcao) != 1) {
        limpar_buffer();
        opcao = -1;
      }

      switch (opcao) {
        case 0:
          terminar_loop = 1;
          break;
        case 1:
          printf("\nDigite o valor que deseja buscar: \n");
          scanf("%d", &x);
          pos = busca_sequencial(v, N, x);
          if (pos == -1) {
            printf("\nValor não encontrado\n");
          } else {
            printf("\nO valor '%d' foi encontrado na posição %d\n", x, pos);
          }
          sleep(3);
          break;
        case 2:
          printf("\nDigite o valor que deseja buscar: \n");
          scanf("%d", &x);
          pos = busca_binaria(v, N, x);
          if (pos == -1) {
            printf("\nValor não encontrado\n");
          } else {
            printf("\nO valor '%d' foi encontrado na posição %d\n", x, pos);
          }
          sleep(3);
          break;
        case 3:
          selection_sort(v, N);
          printf("\nVetor ordenado (selection sort):\n");
          for (int i = 0; i < N; i++) {
            printf("%d ", v[i]);
          }
          printf("\n");
          sleep(3);
          break;
        case 4:
          bubble_sort(v, N);
          printf("\nVetor ordenado (bubble sort):\n");
          for (int i = 0; i < N; i++) {
            printf("%d ", v[i]);
          }
          printf("\n");
          sleep(3);
          break;
        default:
          printf("ERRO! Opção inválida\n");
          sleep(1);
          break;
      }
      if (terminar_loop == 1) {
        break;
      }
    }
  }

  return 0;
}

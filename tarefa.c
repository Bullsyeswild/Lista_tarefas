#include <stdlib.h>
#include <stdio.h>
#include "term.h"
#include "tarefa.h"

ListaTarefa lista;

void inicializarLista(){
  lista.primeiro = NULL;
  lista.ultimo = NULL;
  lista.size = 0;
}

void salvarLista() {
  FILE *arquivo;
  arquivo = fopen("lista_tarefa.txt", "a+");

  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para gravação.\n");
    return;
  }

  NoTarefa *no = lista.primeiro;
  fprintf(arquivo, "%-5s %-15s %-5s\n\n", "ID", "NOME", "STATUS -> 0 - Fazer, 1 - Andamento, 2 - Finalizada ");
  while (no != NULL) {
    fprintf(arquivo, "%-5d %-18s %-5d\n", no->tarefa.id, no->tarefa.titulo, no->tarefa.status);
    no = no->proximo;
  }
  fclose(arquivo);
}

void carregarLista() {
  FILE *arquivo;
  arquivo = fopen("lista_tarefa.txt", "w+");

  if (arquivo == NULL) {
    printf("Arquivo de lista de tarefas não encontrado. Criando novo arquivo.\n");
    return;
  }

  while (!feof(arquivo)) {
    Tarefa tarefa;
    if (fscanf(arquivo, "%d %[^;] %d\n", &tarefa.id, tarefa.titulo, &tarefa.status) == 3) {
      NoTarefa *novoNo = (NoTarefa *)malloc(sizeof(NoTarefa));
      if (novoNo != NULL) {
        novoNo->tarefa = tarefa;
        novoNo->proximo = NULL;
        novoNo->anterior = NULL;

        if (lista.primeiro == NULL) {
          lista.primeiro = novoNo;
          lista.ultimo = novoNo;
        } else {
          lista.ultimo->proximo = novoNo;
          novoNo->anterior = lista.ultimo;
          lista.ultimo = novoNo;
        }

        lista.size++;
      }
    }
  }
  fclose(arquivo);
}

void criarNovaTarefa() {
  Tarefa tarefa;
  tarefa.id = lista.size + 1;
  tarefa.status = A_FAZER;
  printf("Digite o título da tarefa: ");
  scanf(" %[^\n]", tarefa.titulo);

  NoTarefa *novoNo = (NoTarefa *)malloc(sizeof(NoTarefa));
  if (novoNo == NULL) {
    printf("Erro ao alocar memória para a tarefa.\n");
    return;
  }
  novoNo->tarefa = tarefa;
  novoNo->proximo = NULL;
  novoNo->anterior = NULL;

  if (lista.primeiro == NULL) {
    lista.primeiro = novoNo;
    lista.ultimo = novoNo;
  } else {
    lista.ultimo->proximo = novoNo;
    novoNo->anterior = lista.ultimo;
    lista.ultimo = novoNo;
  }
  lista.size++;
}

void editarTarefa(unsigned int id) {
  NoTarefa *no = lista.primeiro;
  while (no != NULL && no->tarefa.id != id) {
    no = no->proximo;
  }
  
  if (no == NULL) {
    printf("Tarefa não encontrada.\n");
    return;
  }
  // Limpa o buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF);

  printf("O que deseja alterar?\n");
  printf("1 - Título\n");
  printf("2 - Status\n");
  printf("Q - Sair\n");
  printf("Opção: ");

  char opt;
  opt = getchar();

  switch (opt) {
    case '1':
      printf("Digite o novo título da tarefa: ");
      scanf(" %[^\n]", no->tarefa.titulo);
      break;
    case '2':
      printf("Digite o novo status da tarefa (0 - Fazer, 1 - Em Andamento, 2 - Concluída): ");
      scanf("%d", &no->tarefa.status);
      break;
    case 'q':
    case 'Q':
      return;
    default:
      printf("Opção inválida.\n");
      break;
  }
}

void deletarTarefa(unsigned int id) {
  NoTarefa *no = lista.primeiro;
  while (no != NULL && no->tarefa.id != id) {
    no = no->proximo;
  }

  if (no == NULL) {
    printf("Tarefa não encontrada.\n");
    return;
  }

  if (no == lista.primeiro) {
    lista.primeiro = no->proximo;
  } else {
    no->anterior->proximo = no->proximo;
  }

  free(no);
  printf("Tarefa deletada.\n");
}

void listar_tarefas() {
  NoTarefa *no = lista.primeiro;
  while (no != NULL) {
    printf("%d - %s - %d\n", no->tarefa.id, no->tarefa.titulo, no->tarefa.status);
    no = no->proximo;
  }
  printf("\n"); 
}

void menu_gerenciar_tarefa(){
  char ch;
  int valor;
  
  carregarLista();
  
    while (1) {
    printf("%s%s", TC_BG_WHT, TC_BLK);
    term_cls(); term_move_xy(1, 1);
    printf("1 - Criar nova tarefa\n");
    printf("2 - Editar tarefas\n");
    printf("3 - Deletar tarefas\n");
    printf("4 - Listar tarefas\n");
    printf("S - Salvar lista\n");
    printf("Q - Sair\n");
    printf("Opção: ");
    ch = getchar();

    if (ch == 'q' || ch == 'Q')
      break;

    switch (ch) {
      case '1':
        criarNovaTarefa();
        break;
      case '2':
        listar_tarefas();
        printf("Digite o ID da tarefa: ");
        scanf("%d", &valor);
        editarTarefa(valor);
        break;
      case '3':
        listar_tarefas();
        printf("Digite o ID da tarefa: ");
        scanf("%d", &valor);
        deletarTarefa(valor);
        break;
      case '4':
        listar_tarefas();
        printf("Digite 'Q' para sair: ");
        getchar();
        break;
      case 'S':
      case 's':
        salvarLista();
        printf("Lista de tarefas salva no arquivo.\n");
        break;
      default:
        printf("Opção inválida.\n");
        break;
    }
    // Limpa o buffer
    while ((ch = getchar()) != '\n' && ch != EOF);
  }
  // Liberar memória
  NoTarefa *no = lista.primeiro;
  while (no != NULL) {
    NoTarefa *temp = no;
    no = no->proximo;
    free(temp);
    }
}
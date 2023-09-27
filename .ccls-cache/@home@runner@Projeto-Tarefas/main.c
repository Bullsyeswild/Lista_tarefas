#include <stdio.h>
#include "tarefa.c"
#include "term.h"
#include "tarefa.h"

void exibir_creditos() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  printf("%s%s", TC_BG_NRM, TC_RED); 
  term_cls();
  term_move_xy(1, 1);
  printf("CRÉDITOS\n");
  printf("Felipe P. Dutra - IDP - 2321017\n");
  printf("24/09/2023  21:27\n\n");
  printf("Digite 'Q' para sair: ");
  getchar();
}

void menu_tarefas() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  menu_gerenciar_tarefa();
}

void menu_principal() {
  char ch;
  while(1) {
    printf("%s%s", TC_BG_WHT, TC_BLK);
    term_cls(); term_move_xy(1, 1);
    printf("1 - Gerenciar Tarefas\n");
    printf("2 - Creditos\n");
    printf("Q - Sair\n");
    printf("Opção: ");
    ch = getchar();
    if(ch == 'q' || ch == 'Q')
      break;

    switch(ch) {
      case '1':
        menu_tarefas();
        break;
      case '2':
        exibir_creditos();
        break;
      default: 
        printf("Opcao invalida");
        return menu_principal();
    }
  } 
}

int main(){
  
  tc_canon_on();
  menu_principal();
  
	return 0;

}//main*/

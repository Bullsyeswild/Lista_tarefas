#include <stdio.h>
#include "term.h"
#include "card.h"
#include "draw.h"

int console_cols, console_rows;

void on_console_window_change() {
  tc_get_cols_rows(&console_cols, &console_rows);
}

void print_main_menu() {
  term_move_xy(5,8);
  printf("1 - Novo jogo\n");
  printf("2 - Pontuação\n");
  printf("3 - Creditos\n");
  printf("0 - Sair\n");
  printf("Opção: ");
}

int main(){
  /*
  tc_get_cols_rows(&console_cols, &console_rows);
  term_move_xy(5,5);
	tc_echo_off(); // esconde o que digita
  printf("Insira uma senha: ");
  scanf("%*s%*c");
  tc_echo_on();
  term_move_xy(5,7);
  printf("Insira qualquer coisa: ");
  
  scanf("%*s%*c");


  
  tc_canon_off();

  
  getchar();
  
*/
  t_card card = {7, PAUS, TC_BLK, 0};

  //tc_canon_on();
  
  term_cls();
  draw_card(8, 10, card);

  //cg_drawline(1,1, console_cols/2, console_rows/2);
  term_move_xy(15, 15);
  printf("imprimir uma linha!");
  term_cls();
  cg_drawline(17, 15, 8, 7);
  getchar();
	return 0;

}//main*/


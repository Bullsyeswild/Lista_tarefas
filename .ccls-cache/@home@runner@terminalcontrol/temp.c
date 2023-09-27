#include <stdio.h>
#include "tc.h"

void process_key(uint64_t c, void *data);

int main(){

	tc_echo_off();
	//ti *t = tc_init_input( &process_key, NULL);

	while(1){
    //tc_enter_alt_screen();
    uint64_t key = getchar();
    process_key(key, NULL);
	}

	return 0;

}//main*/

void process_key(uint64_t c, void *data){

	//ASCII
	if(c == 'x'){
		tc_echo_on();
		tc_canon_on();
		exit(0);
	}
	if(c >= ' ' && c <= '~'){
		printf("key ASCII %s%c%s\n", TC_RED, (char) c, TC_NRM);
		return;
	}

	switch(c){
	case TC_KEY_F1:
	case TC_KEY_F1_TTY:
		printf("pressed %sFunction Key 1%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F2:
	case TC_KEY_F2_TTY:
		printf("pressed %sFunction Key 2%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F3:
	case TC_KEY_F3_TTY:
		printf("pressed %sFunction Key 3%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F4:
	case TC_KEY_F4_TTY:
		printf("pressed %sFunction Key 4%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F5:
	case TC_KEY_F5_TTY:
		printf("pressed %sFunction Key 5%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F6:
		printf("pressed %sFunction Key 6%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F7:
		printf("pressed %sFunction Key 7%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F8:
		printf("pressed %sFunction Key 8%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F9:
		printf("pressed %sFunction Key 9%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F10:
		printf("pressed %sFunction Key 10%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F11:
		printf("pressed %sFunction Key 11%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_F12:
		printf("pressed %sFunction Key 12%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_ESCAPE:
		printf("pressed %sescape%s\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_ARROW_UP:
		printf("pressed %sup arrow%skey\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_ARROW_DOWN:
		printf("pressed %sdown arrow%skey\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_ARROW_LEFT:
		printf("pressed %sleft arrow%skey\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_ARROW_RIGHT:
		printf("pressed %sright arrow%skey\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_TAB:
		printf("pressed %sTAB%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_RETURN:
		printf("pressed %sReturn%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_INSERT:
		printf("pressed %sInsert%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_HOME:
		printf("pressed %sHome%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_PAGE_UP:
		printf("pressed %sPage Up%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_DELETE:
		printf("pressed %sDelete%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_END:
		printf("pressed %sEnd%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_PAGE_DOWN:
		printf("pressed %sPage Down%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_EURO:
		printf("pressed %s€%s key\n", TC_RED, TC_NRM);
		break;
	case TC_KEY_GBP:
		printf("pressed %s£%s\n", TC_RED, TC_NRM);
		break;
	default:
		printf("key pressed %s0x%lx%s\n", TC_RED, c, TC_NRM);
		break;

	}

	return;

}//process_key*/

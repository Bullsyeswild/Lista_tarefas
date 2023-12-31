#ifndef CARD_H
#define CARD_H

#define COPAS   "\u2665" //"♥" // RED
#define OUROS   "\u2666" //"♦" // RED
#define PAUS    "\u2663" //"♣" // BLK
#define ESPADAS "\u2660" //"♠" // BLK
#define HIDDEN  "▓"            // BLU
#define HIDDEN_2 "░"
#define HIDDEN_3 "▒"

typedef struct {
  int value;
  char *naipe;
  char *color;
  int is_hidden;
} t_card;


#endif
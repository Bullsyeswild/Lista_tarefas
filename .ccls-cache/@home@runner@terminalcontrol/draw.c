/*
  Copyright: IESB CG
  Author: Daniel da Silva Souza - 0912130071
  Date: 15/08/10 23:43
*/

#include <math.h> //round() usado para arredondar retas com coeficiente angular e o círculo.
#include "term.h"

void troca(int *a, int *b)
{
/*
troca valores para percorrer o tamanho da taxa de variação entre o maior e o menor
para a função cg_drawline. Permitindo assim chamar a função com pontos distintos
P(x1,y1) e Q(x2,y2) sem distinção de ordem entre qual é o maior e o menor valor entre eles.
*/
    int aux = *a;
    *a = *b;
    *b = aux;
}

void cg_drawline(int x1, int y1, int x2, int y2)
{
/*
Equação geral da reta: ax + by + c = 0
para P(x1,y1) e Q(x2,y2):
coef a = y1-y2
coef b = x2-x1
coef c = x1y2-x2y1

se a = 0 -> eq da reta fica: by + c = 0 ou y = -c/b
e temos uma reta paralela ao eixo Ox

se b = 0 -> eq da reta fica: ax + c = 0 ou x = -c/a
e temos uma reta paralela ao eixo Oy

se b != 0 -> temos y = -[(a/b)*x] -c/b = mx + q
onde -a/b = (y2-y1)/(x2-x1) = m -> coeficiente angular
     -c/b = [(x2y1)-(x1y2)]/x2-x1 = q -> coeficiente linear     
         ::\> y = mx+q
*/
     float a = y1-y2,
           b = x2-x1,
           c = (x1*y2)-(x2*y1),
           x = 0,
           y = 0;
     
     //m = Coef Angular q = Coef Linear
     float m = -(a/b),
           q = -(c/b);
         
     if (b != 0)
     {
         //y = (m*x)+q;
         if (x1 > x2)troca(&x1,&x2);
         for(x=x1;x<x2;x+=0.01)
         {
              y = round((m*x)+q);
              glVertex2i((int)x,(int)y);
         }
     }
     else
     {
         if (a == 0)
         {
             //y = -c/b ou by+c = 0;
             y = -c/b;
             if (x1 > x2)troca(&x1,&x2);
             for(x=x1;x<x2;x+=1.0)
             {
                 glVertex2i((int)x,(int)y);
             }
         }
         
         if (b == 0)
         {
             //x = -c/a ou ax + c = 0;
             x= -c/a;
             if (y1 > y2)troca(&y1,&y2);
             for(y=y1;y<y2;y+=1.0)
             {
                 glVertex2i((int)x,(int)y);
             }
         }
     }
}
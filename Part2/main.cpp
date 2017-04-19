#include <stdio.h>
#include <stdlib.h>
#include <libconfig.hh>

/* ïðîñòàÿ ïðîãðàììà èãðû â êðåñòèêè-íîëèêè */
#define SPACE ' '
char matrix[3][3] = { /* ìàòðèöà äëÿ êðåñòèêîâ-íîëèêîâ */
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE}
} ;
void get_computer_move(void), get_player_move(void);
void disp_matrix(void);
char check (void);
int x,y;
int main()
{
char done;
printf("This is the game of Tic-Tac-Toe.\n");
printf("You will be playing against the computer.\n");
done = SPACE;
do {
disp_matrix(); /* âûâîä èãðîâîé äîñêè */
get_player_move(); /* õîäèò èãðîê */
done = check(); /* ïðîâåðêà íà ïîáåäó */
if (done!=SPACE) break; /* ïîáåäèòåëü */
get_computer_move(); /* õîäèò êîìïüþòåð */
done=check(); /* ïðîâåðêà íà ïîáåäó */
} while(done==SPACE);
if(done=='X') printf("You won!\n");
else printf("I won!!!!\n");
disp_matrix(); // îòîáðàæåíèå ðåçóëüòèðóþùåãî ïîëîæåíèÿ 
system("pause");
return 0;
}

/* ââîä õîäà èãðîêà */
void get_player_move(void)
{
//int x, ó;
printf("Enter coordinates for your X.\n");
printf("Row? ");
scanf ("%d", &x);
printf("Column? ");
scanf("%d", &y);
x--; y--;
if (x<0 || y<0 || x>2 || y>2 || matrix[x] [y] !=SPACE)
{
printf("Invalid move, try again.\n");
get_player_move();
}
else matrix[x][y]='X';
}

/* õîä êîìïüþòåðà */
void get_computer_move(void)
{
register int t;
char *p;
p = (char *) matrix;
for (t=0; *p!=SPACE && t<9; ++t) p++;
if(t==9)
{
printf("draw\n");
exit(0); /* game over */
}
else *p = 'O';
}

/* îòîáðàæåíèå èãðîâîé äîñêè */
void disp_matrix(void)
{
int t;
for(t=0; t<3; t++)
{
printf(" %c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);
if(t!=2) printf("\n-|-|-\n");
}
printf("\n");
}

/* ïðîâåðêà íà ïîáåäó */
char check(void)
{
int t;
char *p;
for(t=0; t<3; t++) { /* ïðîâåðêà ñòðîê */
p = &matrix[t] [0];
if (*p==* (p+1) && * (p+1)==*(p+2)) return *p;
}
for(t=0; t<3; t++) { /* ïðîâåðêà ñòîëáöîâ */
p = &matrix[0][t];
if(*p==*(p+3) && *(p+3)==*(p+6)) return *p;
}

/* ïðîâåðêà äèàãîíàëåé */
if(matrix[0] [0]==matrix [1] [1] && matrix[1] [1]==matrix [2] [2] )
return matrix[0][0];
if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2] [0])
return matrix[0][2];
return SPACE;


}

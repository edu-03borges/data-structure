#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char matrix[3][3]; /* matriz at the game */

char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main()
{
    char done;
    puts("\n|----------------------------------------------|");
    puts("\n|           This is tic-tac-toe                |");
    puts("\n|  You will be playing against the computer    |");
    puts("\n|----------------------------------------------|");
    puts("\n");
    
    done = ' ';
    init_matrix();

    do {
        disp_matrix();
        get_player_move();
        done = check();
        if(done!=' ') break; /* Winner! */
        get_computer_move();
        done = check(); /* check for winner */
    } while(done== ' ');

    if(done=='X') printf("You Gain!\n");
    else printf("I Gain! ! ! ! \n");

    disp_matrix();
}

void init_matrix(void)
{
    int i, j;

    for(i=0; i<3; i++)
        for(j=0;j<3;j++) matrix[i][j] = ' ';
}

void get_player_move(void)
{
    int x, y;
    
    printf("Enter coordinates for the X: ");
    scanf ("%d%d", &x, &y);

    x--; y--;

    if(matrix[x][y]!=' ') {
        printf("Invalid position, try again. \n");
        get_player_move();
    }
    else matrix[x][y] = 'X';
}

void get_computer_move(void)
{
    int i, j;

    for(i=0; i<3; i++) {
        for(j=0; j<3; j++)
            if(matrix[i][j]==' ') break;
        if(matrix[i][j]==' ') break;
    }
    
    if(i*j==9) {
        printf("empate\n");
        exit(0) ;
    }
    else
        matrix[i][j] = 'O';
}

void disp_matrix(void)
{
    int i;

    for(i=0;i<3;i++)
    {
        printf(" %c  |  %c  |  %c \n", 
            matrix[i][0], matrix[i][1], matrix[i][2]);
        if(i!=2) printf("----|-----|----\n");
    }
    printf("\n");
}

char check(void)
{
    int i;

    /* check the lines */
    for(i=0; i<3; i++) 
        if(matrix[i][0]==matrix[i][1] &&
            matrix[i][0]==matrix[i][2]) return matrix[i][0];
    
    /* check the columns */
    for(i=0; i<3; i++) 
        if(matrix[0][i]==matrix[1][i] &&
            matrix[0][i]==matrix[2][i]) return matrix[0][i];
    
    /* test the diagonals */
    if(matrix[0][0]==matrix[1][1] &&
        matrix[1][1]==matrix[2][2])
            return matrix[0][0];
    if(matrix[0][2]==matrix[1][1] &&
        matrix[1][1]==matrix[2][0])
            return matrix[0][2];

    return ' ';
}
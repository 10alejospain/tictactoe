#include <stdio.h>
#include <stdbool.h>

//--Global variables--
    
//Tablero
char X = 'X';
char O = 'O';
char spc = ' ';
char emp = '-';

char board[3][5] ={
    {'1','|','2','|','3'} ,
    {'4','|','5','|','6'} ,
    {'7','|','8','|','9'} };
//Turn and gamplay
int turn = 0;
char player;

//--Declarated functions--
void show_board(int i,int j,char table[i][j]);
void option_picker(char opt,char player);
void show_info();
bool win_check(int i,int j, char table[i][j]);
void show_info_h(int turn);

int main(int argc, char const *argv[])
{
    //Inicio
    show_info();                            

    do//main game loop
    {
        char inpt;
        show_board(3,5,board);
        if ((turn%2) == 0 || turn == 0) {
            player = X;
        }else{
            player = O;
        }
        
        printf("\nPlayer %c select your movement >> ",player);
        scanf(" %c",&inpt);
        option_picker(inpt,player);
        printf("End of turn ------> %d\n",turn+1);
        printf("\n");

        turn++;
    } while (turn <= 8 && win_check(3,5,board) == true);
    
    //Win statement
    if (win_check(3,5,board) == true) {
        printf("\n --THE GAME IS FINISHED-- \n\n NO WINNERS DETECTED!");
    }
    else{
        printf("\n --THE GAME IS FINISHED-- \n\n THE %c PLAYER IS THE WINNER! \n",player);
    }
    
    
}

//Functions code
void show_board(int i,int j,char table[i][j]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("%c",table[i][j]);
        }
        printf("\n");
    }
}
void option_picker(char opt,char player){
    switch (opt)
    {
        case '1':
            board[0][0] = player;
            break;
        case '2':
            board[0][2] = player;
            break;
       case '3':
            board[0][4] = player;
            break;
        case '4':
            board[1][0] = player;
            break;
        case '5':
            board[1][2] = player;
            break;
        case '6':
            board[1][4] = player;
            break;
        case '7':
            board[2][0] = player;
            break;
        case '8':
            board[2][2] = player;
            break;
        case '9':
            board[2][4] = player;
            break;
        case 'h':
            show_info_h(turn);
            break;
    
        default:
            break;
    }
}
void show_info(){
    printf("\n---------------------------------------------------\n");
    printf(" _   _      _             _              \n");
    printf("| | (_)    | |           | |             \n");
    printf("| |_ _  ___| |_ __ _  ___| |_ ___   ___  \n");
    printf("| __| |/ __| __/ _` |/ __| __/ _ \\ / _ \\ \n");
    printf("| |_| | (__| || (_| | (__| || (_) |  __/ \n");
    printf(" \\__|_|\\___|\\__\\__,_|\\___|\\__\\___/ \\___| \n");
    printf("\n---------------------------------------------------\n");
    printf("               RULES AND COMMANDS\n\n");
    printf("-Two players X & O must play this game\n");
    printf("-Select the place where you want to place your token\n");
    printf("-Type \"h\" to read the info again\n");
    printf("\n---------------------------------------------------\n");
}
void show_info_h(int turn){
    printf("\n---------------------------------------------------\n");
    printf("               RULES AND COMMANDS\n\n");
    printf("-Two players X & O must play this game\n");
    printf("-Select the place where you want to place your token\n");
    printf("-Type \"h\" to read the info again\n");
    printf("\n---------------------------------------------------\n");
    turn--;
}
bool win_check(int i,int j, char table[i][j]){
    //column 1
    if (table[0][0] == 'O' || table[0][0] == 'X') {
        if (table[1][0] == 'O' || table[1][0] == 'X') {
            if (table[2][0] == 'O' || table[2][0] == 'X') {
                return false;
            }
        }
    }
    //Column 2
    else if (table[0][2] == 'O' || table[0][2] == 'X') {
        if (table[1][2] == 'O' || table[1][2] == 'X') {
            if (table[2][2] == 'O' || table[2][2] == 'X') {
                return false;
            } 
        }
        
    }
    //Column 3
    else if (table[0][4] == 'O' || table[0][4] == 'X') {
        if (table[1][4] == 'O' || table[1][4] == 'X') {
            if (table[2][4] == 'O' || table[2][4] == 'X') {
                return false;
            }
        }
    }
    //row 1
    else if (table[0][0] == 'O' || table[0][0] == 'X'){
        if (table[0][2] == 'O' || table[0][2] == 'X'){
            if (table[0][4] == 'O' || table[0][4] == 'X') {
                return false;
            }       
        }
    }
    //row 2
    else if (table[1][0] == 'O' || table[1][0] == 'X'){
        if (table[1][2] == 'O' || table[1][2] == 'X'){
            if (table[1][4] == 'O' || table[1][4] == 'X') {
                return false;
            }      
        }
    }
    //row 3
    else if (table[2][0] == 'O' || table[2][0] == 'X'){
        if (table[2][2] == 'O' || table[2][2] == 'X'){
            if (table[2][4] == 'O' || table[2][4] == 'X') {
                return false;
            }     
        }
    }
    //Diagonal 1
    else if (table[0][0] == 'O' || table[0][0] == 'X'){
        if (table[1][2] == 'O' || table[1][2] == 'X'){
            if (table[2][4] == 'O' || table[2][4] == 'X') {
                return false;
            }     
        }
    }
    //Diagonal 2
     else if (table[0][4] == 'O' || table[0][4] == 'X'){
        if (table[1][2] == 'O' || table[1][2] == 'X'){
            if (table[2][0] == 'O' || table[2][0] == 'X') {
                return false;
            }     
        }
    }
    else{
        return true;
    }    
}
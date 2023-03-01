#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>


#define true 1
#define false 0

#define value(character) (character == 'X') ? 1 : ((character == 'O') ? -1 : 0)
#define index(num) [(int) (num)/3][num%3]

#define and &&
#define or ||
#define not !

int ord(int);   //return the Ascii code of the character given as an argument
int chr(char);  //returns the Ascii character at the ascii code given as an argument
int checkWin(char arr[3][3]);   //Checks if any player has won in the position
int is_vacant(int pos[2], char arr[3][3]);  //Checks if the given pos(position) is vacant on board
void draw(char arr[3][3]);  //Draws the board
void optionChosen(int, int);
void gotoxy(int, int);
void main()
{
    int option = 0, event = true;
    char arr[3][3] = {
        "123",
        "456",
        "789"
    };
    char keyPressed = '_';
    // draw(arr);
    Main_menu:
        while(true){
            if (event == true){
                event = false;
                system("cls");
                printf("\t\t\t\t\033[1;32mTic Tac Toe\n\n");
                printf("\t\t\t\t");
                optionChosen(option, 0);
                printf("\033[0;34m Play\n");
                printf("\t\t\t\t");
                optionChosen(option, 1);
                printf("\033[0;34m About\n");
                printf("\t\t\t\t");
                optionChosen(option, 2);
                printf("\033[0;34m Quit\n");
            }
            
            if (kbhit()){
                keyPressed = getch();
                if (keyPressed == 'w' or keyPressed == 'W'){
                    if (option <= 0){
                        option = 2;
                    }else{
                        option--;
                    }
                    event = true;
                }
                if (keyPressed == 's' or keyPressed == 'S'){
                    if (option >= 2){
                        option = 0;
                    }else{
                        option++;
                    }
                    event = true;
                }
                if (keyPressed == ' '){
                    event = true;
                    if (option == 0){
                        option = 0;
                        goto play;
                    }
                    if (option == 1){
                        option = 0;
                        goto about;
                    }
                    if (option == 2){
                        exit(true);
                    }
                }
            }
        }
    play:
        while (true){
            if (event == true){
                event = false;
                system("cls");
                printf("\033[0;32m\t\tChoose the Game Mode you want to play in:-\n\n");
                printf("\t\t\t");
                optionChosen(option, 0);
                printf("\033[0;34m Play Human \033[0;31mV/S\033[0;34m Human\n");
                printf("\t\t\t");
                optionChosen(option, 1);
                printf("\033[0;34m Play Human \033[0;31mV/S\033[0;34m AI\n");
                printf("\t\t\t");
                optionChosen(option, 2);
                printf("\033[0;34m Back\n");
            }
            if (kbhit()){
                keyPressed = getch();
                if (keyPressed == 'w' or keyPressed == 'W'){
                    event = true;
                    if (option <= 0){
                        option = 2;
                    }else{
                        option--;
                    }
                }
                if (keyPressed == 's' or keyPressed == 'S'){
                    event = true;
                    if (option >= 2){
                        option = 0;
                    }else{
                        option++;
                    }
                }
                if (keyPressed == ' '){
                    event = true;
                    if (option == 0){
                        option = 0;
                        // goto vsHuman;
                    }
                    if (option == 1){
                        option = 0;
                        // goto vsAI;
                    }
                    if (option == 2){
                        option = 0;
                        goto Main_menu;
                    }
                }
            }
        }
    about:
        system("cls");
        printf("\t\t\033[1;37m Made by\033[3;35m Legendary3995\n\t\t\033[0;30m\033[1;37m For more information visit:-\n\t\t\033[3;30m\033[4;34mhttps://github.com/Legendary3995/Tic-Tac-Toe-in-C\n\n");
        printf("\t\t\033[0;31m\033[2;31m Press any key to go Back to main menu");
        getch();
        goto Main_menu;
        
}

int ord(int character){return character;}
int chr(char code){return code;}

void draw(char arr[3][3]){
    printf("\033[0;37m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    \033[1;34m%c\033[0;37m    %c%c    \033[1;34m%c\033[0;37m    %c%c    \033[1;34m%c\033[0;37m    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    \033[1;34m%c\033[0;37m    %c%c    \033[1;34m%c\033[0;37m    %c%c    \033[1;34m%c\033[0;37m    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    \033[1;34m%c\033[0;37m    %c%c    \033[1;34m%c\033[0;37m    %c%c    \033[1;34m%c\033[0;37m    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), arr[0][0], chr(219), chr(219), arr[0][1], chr(219), chr(219), arr[0][2], chr(219), chr(219),
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), arr[1][0], chr(219), chr(219), arr[1][1], chr(219), chr(219), arr[1][2], chr(219), chr(219),
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), arr[2][0], chr(219), chr(219), arr[2][1], chr(219), chr(219), arr[2][2], chr(219), chr(219),
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), 
        chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219), chr(219)
    );
}

void gotoxy(int x, int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void optionChosen(int givenOption, int realOption){
    if (givenOption == realOption){
        printf("\033[1;31m%c", chr(175));
    }else{
        printf(" ");
    }
}


int is_vacant(int pos[2], char arr[3][3]){
    if ((arr[pos[0]][pos[1]] != 'X') or (arr[pos[0]][pos[1]] != 'O')){
        return true;
    }
    else{
        return false;
    }
}

int checkWin(char arr[3][3]){
    int sums[8] = {
        value(arr[0][0]) + value(arr[0][1]) + value(arr[0][2]),
        value(arr[1][0]) + value(arr[1][1]) + value(arr[1][2]),
        value(arr[2][0]) + value(arr[2][1]) + value(arr[2][2]),
        value(arr[0][0]) + value(arr[1][0]) + value(arr[2][0]),
        value(arr[0][1]) + value(arr[1][1]) + value(arr[2][1]),
        value(arr[0][2]) + value(arr[1][2]) + value(arr[2][2]),
        value(arr[0][0]) + value(arr[1][1]) + value(arr[2][2]),
        value(arr[2][0]) + value(arr[1][1]) + value(arr[0][2])
    };

    for (int i = 0; i < 8; i++){
        if (sums[i] == 3){
            return 4; //Player with 'X' wins
        }
        if (sums[i] == -3){
            return -4; // Player with 'O' wins
        }
    }
    int vacantBlocks = 0;
    for (int i = 0; i < 9; i++){
        if (is_vacant(arr index(i), arr) == true){
            vacantBlocks ++;
        }
    }
    if (vacantBlocks == 0){
        return 1; //Draw
    }
    return 0; //Game still going on
}

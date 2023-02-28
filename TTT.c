#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#define true 1
#define false 0

#define value(character) (character == 'X') ? 1 : ((character == 'O') ? -1 : 0)
#define index(num) [(int) (num)/3][num%3]

#define and &&
#define or ||

int ord(int);   //return the Ascii code of the character given as an argument
int chr(char);  //returns the Ascii character at the ascii code given as an argument
int checkWin(char arr[3][3]);   //Checks if any player has won in the position
int is_vacant(int pos[2], char arr[3][3]);  //Checks if the given pos(position) is vacant on board
void draw(char arr[3][3]);  //Draws the board
int main()
{
    char arr[3][3] = {
        "123",
        "456",
        "789"
    };
    system("cls");
    draw(arr);
    getch();
    return 0;
}
int ord(int character){return character;}
int chr(char code){return code;}

void draw(char arr[3][3]){
    printf("\033[0;37m%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    \033[1;36m%c\033[0;37m    %c%c    \033[1;36m%c\033[0;37m    %c%c    \033[1;36m%c\033[0;37m    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    \033[1;36m%c\033[0;37m    %c%c    \033[1;36m%c\033[0;37m    %c%c    \033[1;36m%c\033[0;37m    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    \033[1;36m%c\033[0;37m    %c%c    \033[1;36m%c\033[0;37m    %c%c    \033[1;36m%c\033[0;37m    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
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

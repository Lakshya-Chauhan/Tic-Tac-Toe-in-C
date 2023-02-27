#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#define true 1
#define false 0

#define value(character) (character == 'X') ? 1 : ((character == 'O') ? -1 : 0)

#define and &&
#define or ||

int ord(int);
int chr(char);
int checkWin(char arr[3][3]);
int is_legal(int pos[2], char arr[3][3]);
void draw(char arr[3][3]);
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
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    %c    %c%c    %c    %c%c    %c    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    %c    %c%c    %c    %c%c    %c    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c    %c    %c%c    %c    %c%c    %c    %c%c\n%c%c         %c%c         %c%c         %c%c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
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


int is_legal(int pos[2], char arr[3][3]){
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
            return 1; //Player with 'X' wins
        }
        if (sums[i] == -3){
            return -1; // Player with 'O' wins
        }
    }
}
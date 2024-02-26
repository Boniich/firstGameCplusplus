#include <iostream>
#include <Windows.h>

void setCoor(const int x, const int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hcon, dwPos);
}

void printWorld() {
    for (int i = 2; i < 190; i++) {
        setCoor(i, 32); printf("%c", 219);
        setCoor(i, 31); printf("%c", 219);
    }

    for (int i = 0; i < 33; i++) {
        setCoor(1, i); printf("%c", 219);
        setCoor(2, i); printf("%c", 219);

        setCoor(189, i); printf("%c", 219);
        setCoor(190, i); printf("%c", 219);
    }

}


int main()
{
    printWorld();
    bool gameOver = false;

    while (!gameOver) {
        setCoor(5, 15); printf("*");

        Sleep(30);
    }

    return 0;
}


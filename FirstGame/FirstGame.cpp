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
    for (int i = 2; i < 78; i++) {
        setCoor(i, 32); printf("%c", 219);
        setCoor(i, 31); printf("%c", 219);
    }

    for (int i = 0; i < 33; i++) {
        setCoor(1, i); printf("%c", 219);
        setCoor(2, i); printf("%c", 219);
    }

}


int main()
{
    printWorld();
}


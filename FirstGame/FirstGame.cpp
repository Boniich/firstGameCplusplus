#include <iostream>
#include <Windows.h>
#include <conio.h>

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

class Character
{
    int _x, _y;
    int _hearts;
    int _lifes;
public:
    Character(int x, int y, int hearts, int lifes) : _x(x), _y(y), _hearts(hearts), _lifes(lifes) {};
    void print();
    void deleteCharacter();
    void move();
};

void Character::print() {
    //head
    setCoor(_x, _y); printf("%c", 219);
    setCoor(_x+1, _y); printf("%c", 219);
    //neck
    setCoor(_x-1, _y+1); printf("%c", 219);
    setCoor(_x, _y + 1); printf("%c", 219);
    setCoor(_x + 1, _y + 1); printf("%c", 219);
    setCoor(_x + 2, _y + 1); printf("%c", 219);
    //body
    setCoor(_x, _y + 2); printf("%c", 219);
    setCoor(_x + 1, _y + 2); printf("%c", 219);
    setCoor(_x, _y + 3); printf("%c", 219);
    setCoor(_x + 1, _y + 3); printf("%c", 219);
    setCoor(_x, _y + 4); printf("%c", 219);
    setCoor(_x + 1, _y + 4); printf("%c", 219);

    //arms 
    // left arm
    setCoor(_x - 2, _y + 2); printf("%c", 219);
    setCoor(_x - 2, _y + 3); printf("%c", 219);

    // right arm
    setCoor(_x + 3, _y + 2); printf("%c", 219);
    setCoor(_x + 3, _y + 3); printf("%c", 219);

    //feet
    // left foot
    setCoor(_x-1 , _y + 5); printf("%c", 219);

    // right foot
    setCoor(_x + 2, _y + 5); printf("%c", 219);




}

void Character::deleteCharacter()
{
    //head
    setCoor(_x, _y);         printf("           ");
    setCoor(_x + 1, _y);     printf("           ");
    //neck
    setCoor(_x - 1, _y + 1); printf("           ");
    setCoor(_x, _y + 1);     printf("           ");
    setCoor(_x + 1, _y + 1); printf("           ");
    setCoor(_x + 2, _y + 1); printf("           ");
    //body
    setCoor(_x, _y + 2);     printf("           ");
    setCoor(_x + 1, _y + 2); printf("           ");
    setCoor(_x, _y + 3);     printf("           ");
    setCoor(_x + 1, _y + 3); printf("           ");
    setCoor(_x, _y + 4);     printf("           ");
    setCoor(_x + 1, _y + 4); printf("           ");

    //arms 
    // left arm
    setCoor(_x - 2, _y + 2); printf("           ");
    setCoor(_x - 2, _y + 3); printf("           ");

    // right arm
    setCoor(_x + 3, _y + 2); printf("           ");
    setCoor(_x + 3, _y + 3); printf("           ");

    //feet
    // left foot
    setCoor(_x - 1, _y + 5); printf("           ");

    // right foot
    setCoor(_x + 2, _y + 5); printf("           ");
}

void Character::move()
{
    if (_kbhit()) {
        char key = _getch();
        //borrar
        deleteCharacter();
        if (key == 'a') _x--;
        if (key == 'd') _x++;
        print();
    }
}


int main()
{
    printWorld();
    bool gameOver = false;
    Character character(15, 20, 3, 3);

    character.print();
    while (!gameOver) {

        character.move();
        Sleep(30);
    }

    return 0;
}


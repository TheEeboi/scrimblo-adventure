#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

bool salir = false;
bool classmenu = false;

int x = 17;
int y = 11;
char mov;
string place;
string clase = "None";
//------------------------------------------------------------------------------------------- Stats
int HP = 100;
int MaxHP = 100;
int MP = 50;
int ATK = 15;
int MATK = 15;
int DEF = 15;
int MDEF = 10;
int coins = 0;
//------------------------------------------------------------------------------------------- Equipment
string weapon = "None";
//------------------------------------------------------------------------------------------- Item spawns
bool apple = true;
bool stick = true;
bool sword = true;
bool book = true;
bool hammer = true;
//------------------------------------------------------------------------------------------- Enemy spawns
bool testenemy = true;
bool testkill = true;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (size == 0)
    {
        size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void Stats() {//---------------------------------------------------------- Stat display
    gotoxy(50, 3);
    cout << "Scrimblo Bimblo";
    gotoxy(50, 4);
    cout << "Class : " << clase;
    gotoxy(50, 6);
    cout << "HP: " << HP << "/" << MaxHP;
    gotoxy(50, 7);
    cout << "MP: " << MP;
    gotoxy(50, 9);
    cout << "ATK:  " << ATK;
    gotoxy(50, 10);
    cout << "MATK: " << MATK;
    gotoxy(50, 11);
    cout << "DEF:  " << DEF;
    gotoxy(50, 12);
    cout << "MDEF: " << MDEF;
    gotoxy(50, 14);
    cout << "Coins: " << coins;
    gotoxy(72, 4);
    cout << "Equipped: " << weapon;
    gotoxy(50, 15);
    cout << "Braincells : 0";
    gotoxy(2, 23);
    cout << "Currently at: " << place;
}
void Map() {//------------------------------------------------------------ Map borders (40, 20)
    for (int i = 0; i < 42; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (j == 0 || j == 21) {
                gotoxy(i, j);
                printf("#");
            }
            if (i == 0 || i == 41) {
                gotoxy(i, j);
                printf("#");
            }
        }
    }
}
void Move() {
    gotoxy(x, y); //Scrimblo position
    printf("X");

    if (_kbhit()) {

        mov = _getch();
        gotoxy(x, y);
        printf("%c", ' ');
        
        if ((x < 40) && (mov == 'd')) { //--------------------------------- Movement (40, 20)
            x += 1;
        }
        else if ((x > 1) && (mov == 'a')) {
            x -= 1;
        }
        else if ((y < 20) && (mov == 's')) {
            y += 1;
        }
        else if ((y > 1) && (mov == 'w')) {
            y -= 1;
        }
    }
}
void Delete() {
    for (int i = 0; i <= 150; i++) {
        gotoxy(i, 25);
        printf(" ");
    }
}

void main()
{
    setcursor(0, 10);
    //CLASS SELECTION ROOM------------------------------------------------------------------------------------------------
    do {
        Map();
        place = "Class selection menu"; //----------------------------------------- Info display
        Stats();
        Move();

        gotoxy(2, 27);
        cout << "Choose your class, stand in the i for info about it";

        gotoxy(23, 12); //Class symbols
        printf("A");

        gotoxy(23, 14);
        printf("W");

        gotoxy(23, 10);
        printf("P");

        gotoxy(23, 8);
        printf("K");
        //-------------------------------------------------------------------------------------- Class pickup
        if (x == 23 && y == 8) {
            gotoxy(2, 25);
            HP = 120;
            MaxHP = 120;
            ATK = 30;
            MATK = 5;
            DEF = 20;
            clase = "Knight";
            classmenu = true;
        }

        if (x == 23 && y == 14) {
            gotoxy(2, 25);
            MP = 200;
            ATK = 5;
            MATK = 30;
            DEF = 10;
            MDEF = 15;
            clase = "Wizard";
            classmenu = true;
        }

        if (x == 23 && y == 10) {
            gotoxy(2, 25);
            HP = 200;
            MaxHP = 200;
            MP = 150;
            ATK = 10;
            MATK = 20;
            DEF = 30;
            MDEF = 20;
            clase = "Paladin";
            classmenu = true;

        }

        if (x == 23 && y == 12) {
            gotoxy(2, 25);
            HP = 110;
            MaxHP = 110;
            ATK = 20;
            MATK = 20;
            DEF = 20;
            MDEF = 20;
            clase = "Adventurer";
            classmenu = true;
        }
        //--------------------------------------------------------------------------------- Class info
        gotoxy(21, 8);
        printf("i");
        if (x == 21 && y == 8) {
            gotoxy(2, 25);
            cout << "Knight: High ATK and DEF, but no magic skills. Can only use use Swords and Hammers                               ";
        }

        gotoxy(21, 10);
        printf("i");
        if (x == 21 && y == 10) {
            gotoxy(2, 25);
            cout << "Paladin: High HP and DEF/MDEF besides balanced ATK/MATk, expert at not dying. Can only use Hammers and Spellbooks";
        }

        gotoxy(21, 12);
        printf("i");
        if (x == 21 && y == 12) {
            gotoxy(2, 25);
            cout << "Adventurer: Balanced all-around stats, jack of all trades and master of none. Can only use Swords and Staffs";
        }

        gotoxy(21, 14);
        printf("i");
        if (x == 21 && y == 14) {
            gotoxy(2, 25);
            cout << "Wizard: High MATK and MDEF, but low HP and DEF. Can only use Staffs and Spellbooks                                    ";
        }

        if ((x == 20 || x == 22) && (y <= 15 && y >= 7)) {
            Delete();
        }
        if (x == 21 && (y == 7 || y == 9 || y == 11 || y == 13 || y == 15)) {
            Delete();
        }

    } while (!classmenu);
    system("cls");

    //TEST ROOM------------------------------------------------------------------------------------------------------------------
    x = 17;
    y = 11;

    do {
        Map();
        place = "Test room";//--------- Info display
        Stats();
        Move();

        if (stick == true) { //-------------------------------------------------------Items
            gotoxy(23, 14);
            printf("|");
        }
        if ((x == 23) && (y == 14) && (stick == true)) {
            if (clase == "Wizard" || clase == "Adventurer") {
                gotoxy(2, 25);
                cout << "You got: Test stick!                                                     ";
                MATK += 10;
                stick = false;
                weapon = "Test Stick";
            }
            else {
                gotoxy(2, 25);
                cout << "A test stick! Too bad you can't use staffs                                         ";
            }
        }

        if (sword == true) {
            gotoxy(23, 12);
            printf("/");
        }
        if ((x == 23) && (y == 12) && (sword == true)) {
            if (clase == "Knight" || clase == "Adventurer") {
                gotoxy(2, 25);
                cout << "You got: Test sword!                                            ";
                ATK += 10;
                sword = false;
                weapon = "Test Sword";
            }
            else {
                gotoxy(2, 25);
                cout << "A test sword! Too bad you can't use swords                                            ";
            }
        }

        if (book == true) {
            gotoxy(23, 10);
            printf("=");
        }
        if ((x == 23) && (y == 10) && (book == true)) {
            if (clase == "Wizard" || clase == "Paladin") {
                gotoxy(2, 25);
                cout << "You got: Test book!                                                 ";
                MATK += 5;
                MDEF += 10;
                book = false;
                weapon = "Test Book";
            }
            else {
                gotoxy(2, 25);
                cout << "A test book! Too bad you can't use spellbooks                                              ";
            }
        }

        if (hammer == true) {
            gotoxy(23, 8);
            printf("T");
        }
        if ((x == 23) && (y == 8) && (hammer == true)) {
            if (clase == "Knight" || clase == "Paladin") {
                gotoxy(2, 25);
                cout << "You got: Test hammer!                                                       ";
                ATK += 5;
                DEF += 10;
                hammer = false;
                weapon = "Test Hammer";
            }
            else {
                gotoxy(2, 25);
                cout << "A test hammer! Too bad you can't use hammers                                    ";
            }
        }

        if (apple == true) {
            gotoxy(20, 5);
            printf("o");
        }
        if (x == 20 && y == 5 && apple == true) {
            if (HP < MaxHP) {
                gotoxy(2, 25);
                cout << "A nice, healthy apple (Healed 10 HP!)                                            ";
                HP += 10;
                apple = false;
            }
            else {
                gotoxy(2, 25);
                cout << "An apple, heals 10 HP, but you're full right now                                       ";
            }
        }
        //------------------------------------------------------------------------------------------ Enemies
        if (testenemy == true) {
            gotoxy(20, 7);
            printf("Z");
        }
        if (x == 20 && y == 7 && testenemy == true && HP > 0) {
            gotoxy(2, 25);
            cout << "Ouchie!";
            HP -= 10;
        }
        if (x <= 21 && x >= 19 && y <= 8 && y >= 6 && mov == 'z') {
            gotoxy(2, 25);
            printf("bonk!                                                                                      ");
        }

        if (testkill == true) {
            gotoxy(10, 7);
            printf("Z");
        }
        if (x == 10 && y == 7 && testkill == true && HP > 0) {
            gotoxy(2, 25);
            cout << "Ouchie!                                                                                    ";
            HP -= 90;
        }



        if (HP <= 0) {//Game over condition
            salir = true;
        }



    } while (!salir);

    system("cls");
    gotoxy(45, 15);//Game over screen
    cout << "GAME OVER";
    gotoxy(45, 16);
    cout << "  _____" << endl;
    gotoxy(46, 17);
    printf("/     \\");
    gotoxy(45, 18);
    cout << "| () () |";
    gotoxy(46, 19);
    cout << "\\  ^  /";
    gotoxy(47, 20);
    cout << "|||||";
    gotoxy(47, 21);
    cout << "|||||";

    int temp;
    cin >> temp;

}
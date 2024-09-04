#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void name()
{
    setlocale(LC_ALL, "Russian");
    puts("* * * * * * * * * * * * * * * * * * * * * *");
    puts("*                                         *");
    puts("* тема: Разработка консольного приложения *");
    puts("*    Выполнил Боев К.С.                   *");
    puts("*                                         *");
    puts("* * * * * * * * * * * * * * * * * * * * * *");
    getchar();
}

void date()
{
    puts(" _   _     __   __    __    _ ");
    puts("| | |_    |  | |_    |  |  |_ ");
    puts(" /  | |   |  |   |   |  |  | |");
    puts("/_  |_|   |__| __|   |__|  |_|");
    getchar();
}

void main()
{
    name();
    date();
}
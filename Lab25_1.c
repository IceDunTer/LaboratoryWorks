#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

void play() {
    char choices[3][10] = {"камень", "ножницы", "бумага"};
    int userChoice, compChoice;

    printf("Выберите: 0 - камень, 1 - ножницы, 2 - бумага: ");
    scanf_s("%i", &userChoice);

    // Проверка корректности ввода
    if (userChoice < 0 || userChoice > 2) {
        printf("Некорректный выбор. Попробуйте снова.\n");
        return;
    }

    compChoice = getRandomNumber(0, 2);

    // Вывод выборов
    printf("Ваш выбор: %s\n", choices[userChoice]);
    printf("Выбор компьютера: %s\n", choices[compChoice]);

    if (userChoice == compChoice) {
        printf("Ничья!\n");
    } else if ((userChoice == 0 && compChoice == 1) ||
               (userChoice == 1 && compChoice == 2) ||
               (userChoice == 2 && compChoice == 0)) {
        printf("Вы победили!\n");
    } else {
        printf("Компьютер победил!\n");
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    srand(time(NULL));

    play();
}

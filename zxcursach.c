#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
typedef struct {
    char resolution[MAX_LENGTH];
    double mpixNum;
    char microphone[MAX_LENGTH];
    char connectionType[MAX_LENGTH];
    int angle;
} Information;

Information database[MAX_LENGTH];
int recordCount = 0;

void addInfo();
int findInfo(int angle, const char* microphone);
void modInfo();
int printInfo();
int printSortedInfo();
void save();
void load();

int main() {
    setlocale(LC_ALL, "RUS");
    int pick = 1, flag;
    do {
        printf("\t\t// Выберите действия, написанные снизу \\\\\n");
        printf("1. Добавить информацию о камере\n");
        printf("2. Найти информацию о камере\n");
        printf("3. Изменить информацию о камере\n");
        printf("4. Вывести информацию о камере\n");
        printf("5. Отсортировать и вывести информацию о камере\n");
        printf("6. Сохранить файл\n");
        printf("7. Загрузить файл\n");
        printf("0. Завершить работу\n");
        scanf("%i", &pick);

        switch (pick) {
        case 1:
            addInfo();
            break;
        case 2: {
            int angle;
            char microphone[MAX_LENGTH];

            puts("Введите угол обзора интересующей Вас камеры:");
            scanf("%i", &angle);
            puts("Есть ли у камеры микрофон?");
            scanf("%s", microphone);
            printf("\n//Поиск информации...\\\\\n\n");
            int index = findInfo(angle, microphone);
            if (index != -1) {
                printf("\t\t//Запись найдена:\\\\\n");
                printf("\tРазрешение: %s\n", database[index].resolution);
                printf("\tЧисло мегапикселей: %i\n", database[index].mpixNum);
                printf("\tМикрофон: %s\n", database[index].microphone);
                printf("\tТип подключения: %s\n", database[index].connectionType);
                printf("\tУгол обзора: %i\n", database[index].angle);
            } else {
                printf("Запись не найдена.\n");
            }
            break;
        }
        case 3:
            modInfo();
            break;
        case 4:
            flag = printInfo();
            if (flag == -1) printf("Записей не обнаружено!\n\n");
            break;
        case 5:
            flag = printSortedInfo();
            if (flag == -1) printf("Записей не обнаружено!\n\n");
            break;
        case 6:
            save();
            break;
        case 7:
            load();
            break;
        case 0:
            pick = 0;
            printf("До свидания, Пользователь!\n\nCopyright: Боев Кирилл, бТИИ-241.");
            break;
        default:
            printf("Неправильно введено значение!\n\n");
        }
    } while (pick != 0);
}

void addInfo() {
    if (recordCount >= MAX_LENGTH) {
        printf("Превышен лимит записи в базу данных!\n\n");
        return;
    }
    Information *i = &database[recordCount];

    printf("\t\t// Запись камеры #%i \\\\\n", recordCount + 1);
    printf("Введите разрешение: ");
    scanf("%s", i->resolution);
    printf("Введите число мегапикселей: ");
    scanf("%lg", &i->mpixNum);
    printf("Введите наличие микрофона (yes/no): ");
    scanf("%s", i->microphone);
    printf("Введите тип подключения: ");
    scanf("%s", i->connectionType);
    printf("Введите угол обзора: ");
    scanf("%i", &i->angle);
    recordCount++;
}

int findInfo(int angle, const char* microphone) {
    for (int i = 0; i < recordCount; i++) {
        if (database[i].angle == angle && strcmp(database[i].microphone, microphone) == 0) {
            return i;
        }
    }
    return -1;
}

void modInfo() {
    int index;
    printf("Введите индекс записи для изменения: ");
    scanf("%i", &index);
    if (index < 0 || index >= recordCount) {
        printf("Неверный индекс!\n");
        return;
    }

    Information *i = &database[index];

    printf("\t\t// Изменение записи камеры #%i \\\\\n", index + 1);
    printf("Введите новое разрешение: ");
    scanf("%s", i->resolution);
    printf("Введите новое число мегапикселей: ");
    scanf("%lg", &i->mpixNum);
    printf("Введите наличие микрофона: ");
    scanf("%s", i->microphone);
    printf("Введите новый тип подключения: ");
    scanf("%s", i->connectionType);
    printf("Введите новый угол обзора: ");
    scanf("%i", &i->angle);
}

int printInfo() {
    if (recordCount == 0) return -1;
    for (int i = 0; i < recordCount; i++) {
        printf("\t\t//Запись #%i:\\\\\n", i + 1);
        printf("\tРазрешение: %s", database[i].resolution);
        printf("\tЧисло мегапикселей: %lg", database[i].mpixNum);
        printf("\tНаличие камеры: %s", database[i].microphone);
        printf("\tТип подключения: %s", database[i].connectionType);
        printf("\tУгол обзора: %i \n\n", database[i].angle);
    }
}

int printSortedInfo() {
    for (int i = 0; i < recordCount - 1; i++) {
        for (int j = 0; j < recordCount - i - 1; j++) {
            if (strcmp(database[j].resolution, database[j + 1].resolution) > 0) { //Узнать, можно ли поменять поле сортировки, т.к. сортировать по разрешению не очень удобно, хоть и работает.
                Information temp = database[j];
                database[j] = database[j + 1];
                database[j + 1] = temp;
            }
        }
    }
    printInfo();
}

void save() {
    FILE *file = fopen("cameras.txt", "w");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }
    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%s %lg %s %s %i\n", database[i].resolution, database[i].mpixNum, database[i].microphone, database[i].connectionType, database[i].angle);
    }
    fclose(file);
    printf("Данные сохранены в файл.\n");
}

void load() {
    FILE *file = fopen("cameras.txt", "r");
    if (file == NULL) {
        perror("Ошибка открытия файла");
        return;
    }
    recordCount = 0;
    while (fscanf(file, "%s %lg %s %s %i", database[recordCount].resolution, &database[recordCount].mpixNum, database[recordCount].microphone, database[recordCount].connectionType, &database[recordCount].angle) != EOF) {
        recordCount++;
    }
    fclose(file);
    printf("Данные загружены из файла.\n");
}

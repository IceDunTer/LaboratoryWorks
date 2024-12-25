#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000
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
int addCustomInfo();
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
        printf("6. Добавлять информацию о произвольном количестве камер\n");
        printf("7. Сохранить файл\n");
        printf("8. Загрузить файл\n");
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
            }
            else {
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
        case 7:
            save();
            break;
        case 8:
            load();
            break;
        case 6:
            addCustomInfo();
            break;
        case 0:
            pick = 0;
            printf("До свидания, Пользователь!\n\nCopyright: Боев Кирилл, бТИИ-241.");
            break;
        default:
            printf("Неправильно введено значение!\n\n");
        }
    } while (pick);
}

void addInfo() {
    int flag = 0;
    if (recordCount >= MAX_LENGTH) {
        printf("Превышен лимит записи в базу данных!\n\n");
        return;
    }
    Information* i = &database[recordCount];

    printf("Введите разрешение, число мегапикселей, наличие микрофона (yes/no), тип подключения и угол обзора через Enter:\n");
    printf("\t\t// Запись камеры #%i \\\\\n", recordCount + 1);
    scanf("%s", i->resolution);
    scanf("%lg", &i->mpixNum);
    while (!flag) {
        scanf("%s", i->microphone);
        if (strcmp(i->microphone, "yes") == 0 || strcmp(i->microphone, "no") == 0) flag = 1;
        else printf("Неправильно введено значение: Наличие микрофона. Введите (yes/no)!");
    }
    scanf("%s", i->connectionType);
    scanf("%i", &i->angle);
    recordCount++;
    return;
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
    int flag = 0;
    printf("Введите номер записи для изменения: ");
    scanf("%i", &index);
    if (index-1 < 0 || index-1 >= recordCount) {
        printf("Неверный номер!\n");
        return;
    }

    Information* i = &database[index-1];

    printf("\t\t// Изменение записи камеры #%i \\\\\n", index);
    printf("Введите новое разрешение: ");
    scanf("%s", i->resolution);
    printf("Введите новое число мегапикселей: ");
    scanf("%lg", &i->mpixNum);
    printf("Введите наличие микрофона: ");
    while (!flag) {
        scanf("%s", i->microphone);
        if (strcmp(i->microphone, "yes") == 0 || strcmp(i->microphone, "no") == 0) flag = 1;
        else printf("Неправильно введено значение: Наличие микрофона. Введите (yes/no)!");
    }
    printf("Введите новый тип подключения: ");
    scanf("%s", i->connectionType);
    printf("Введите новый угол обзора: ");
    scanf("%i", &i->angle);
    return;
}

int printInfo() {
    if (recordCount == 0) {
        printf("Записей нет!\n");
        return -1;
    }
    for (int i = 0; i < recordCount; i++) {
        printf("\t\t//Запись #%i:\\\\\n", i + 1);
        printf("\tРазрешение: %s\n", database[i].resolution);
        printf("\tЧисло мегапикселей: %lg\n", database[i].mpixNum);
        printf("\tНаличие микрофона: %s\n", database[i].microphone);
        printf("\tТип подключения: %s\n", database[i].connectionType);
        printf("\tУгол обзора: %i\n\n", database[i].angle);
    }
    return 0;
}


int printSortedInfo() {
    int flagConnectionType = 0, flagMicrophone = 0;
    puts("// Сортировать по типам подключения? (1 - да/0 - нет) \\");
    scanf("%i", &flagConnectionType);

    puts("// Сортировать по наличию микрофона? (1 - да/0 - нет) \\");
    scanf("%i", &flagMicrophone);

    if (flagConnectionType && flagMicrophone) {
        for (int i = 0; i < recordCount - 1; i++) {
            for (int j = 0; j < recordCount - i - 1; j++) {
                if ((strcmp(database[j].microphone, database[j + 1].microphone) > 0) && (strcmp(database[j].connectionType, database[j + 1].connectionType) > 0)) { //Узнать, можно ли поменять поле сортировки, т.к. сортировать по разрешению не очень удобно, хоть и работает.
                    Information temp = database[j];
                    database[j] = database[j + 1];
                    database[j + 1] = temp;
                }
            }
        }
    }

    else if (flagConnectionType) {
        for (int i = 0; i < recordCount - 1; i++) {
            for (int j = 0; j < recordCount - i - 1; j++) {
                if ((strcmp(database[j].connectionType, database[j + 1].connectionType) > 0)) {
                    Information temp = database[j];
                    database[j] = database[j + 1];
                    database[j + 1] = temp;
                }
            }
        }
    }

    else if (flagMicrophone) {
        for (int i = 0; i < recordCount - 1; i++) {
            for (int j = 0; j < recordCount - i - 1; j++) {
                if ((strcmp(database[j].microphone, database[j + 1].microphone) > 0)) { 
                    Information temp = database[j];
                    database[j] = database[j + 1];
                    database[j + 1] = temp;
                }
            }
        }
    }
    else printf("Сортировка не была произведена!");
    printInfo();
    return 0;
}

int addCustomInfo() {
    int flag = 0;
    int customCount = 0;
    puts("// Введите количество записей данных для камеры: \\\\");
    while (flag == 0) {
        scanf("%i", &customCount);
        if (recordCount+customCount < MAX_LENGTH) flag = 1;
        else printf("Ошибка! При произвольном количестве записи будет превышен лимит записи в БД!\nЗапишите новое количество записей данных: ");
    }
    for (int j = 0; j < customCount; j++) {
        addInfo();
    }
    return 0;
}

void save() {
    FILE *file = fopen("cameras.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }
    fprintf(file, "Разрешение: Мегапиксели: Микрофон: Подключение: Угол обзора:\n");
    for (int i = 0; i < recordCount; i++) {
        fprintf(file, "%s     %lg          %s        %s            %i\n", database[i].resolution, database[i].mpixNum, database[i].microphone, database[i].connectionType, database[i].angle);
    }
    fclose(file);
    printf("Данные сохранены в файл.\n\n");
}

void load() {
    FILE *file = fopen("cameras.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла");
        return;
    }
    recordCount = 0;
    char header[1000];
    fgets(header, sizeof(header), file);

    while (fscanf(file, "%s %lg %s %s %i", database[recordCount].resolution, &database[recordCount].mpixNum, database[recordCount].microphone, database[recordCount].connectionType, &database[recordCount].angle) != EOF) {
        recordCount++;
    }
    fclose(file);
    printf("Данные загружены из файла.\n\n");
}

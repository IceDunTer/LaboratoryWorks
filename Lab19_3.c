#include <stdio.h>
#include <locale.h>

struct employee {
    char family[50];
    char name[50];
    char surname[50];
    char position[50];
    int salary;
    int age;
    char date_of_birth[11]; // Формат: ДД.ММ.ГГГГ
};

int writeFile(char *fname, struct employee *emp, int size) {
    FILE *out;
    if ((out = fopen(fname, "wt")) == NULL) {
        printf("Ошибка открытия файла для записи");
        return 0;
    }

    for (int i = 0; i < size; i++) {
        fprintf(out, "%s %s %s %s %i %i %s\n",
                emp[i].family, emp[i].name, emp[i].surname, emp[i].position,
                emp[i].salary, emp[i].age, emp[i].date_of_birth);
    }

    fclose(out);
    return 1;
}

int main() {
    setlocale(LC_ALL, "RUS");
    struct employee emp[3] = {
        {"Harebin", "Anton", "Alexandrovich", "Engineer", 50000, 30, "01.01.1993"},
        {"Abakumov", "Artyom", "Sergeevich", "Manager", 60000, 40, "15.05.1983"},
        {"Boev", "Kirill", "Sergeevich", "Director", 100000, 50, "26.05.2006"}
    };

    if (writeFile("employees.txt", emp, 3)) {
        printf("Запись успешно выполнена.\n");
    } else {
        printf("Ошибка записи.\n");
    }
}

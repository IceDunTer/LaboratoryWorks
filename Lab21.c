#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

typedef struct {
    char family[50];
    char name[50];
    char surname[50];
    char position[50];
    int salary;
    int age;
    char date_of_birth[11]; // Формат: ДД.ММ.ГГГГ
} employee;

void fill_arr(employee employees[], int size) {
    srand(time(NULL));

    char families[5][50] = {"Ivanov", "Petrov", "Sidorov", "Kuznetsov", "Smirnov"};
    char names[5][50] = {"Ivan", "Petr", "Sidr", "Kuzma", "Semyon"};
    char surnames[5][50] = {"Ivanovich", "Petrovich", "Sidorovich", "Kuzmich", "Semyonovich"};
    char positions[5][50] = {"Engineer", "Manager", "Developer", "Designer", "Analyst"};
    char dates[5][11] = {"01.01.1990", "15.05.1985", "25.09.1980", "10.12.1995", "05.07.1988"};

    for (int i = 0; i < size; i++) {
        strcpy(employees[i].family, families[rand() % 5]);
        strcpy(employees[i].name, names[rand() % 5]);
        strcpy(employees[i].surname, surnames[rand() % 5]);
        strcpy(employees[i].position, positions[rand() % 5]);
        employees[i].salary = rand() % 50000 + 30000;
        employees[i].age = rand() % 30 + 20;
        strcpy(employees[i].date_of_birth, dates[rand() % 5]);
    }
}

int compare_family(const void *a, const void *b) {
    const employee *emp1 = (const employee *)a;
    const employee *emp2 = (const employee *)b;
    return strcmp(emp1->family, emp2->family);
}

int compare_name(const void *a, const void *b) {
    const employee *emp1 = (const employee *)a;
    const employee *emp2 = (const employee *)b;
    return strcmp(emp1->name, emp2->name);
}

int compare_surname(const void *a, const void *b) {
    const employee *emp1 = (const employee *)a;
    const employee *emp2 = (const employee *)b;
    return strcmp(emp1->surname, emp2->surname);
}

int compare_position(const void *a, const void *b) {
    const employee *emp1 = (const employee *)a;
    const employee *emp2 = (const employee *)b;
    return strcmp(emp1->position, emp2->position);
}

int compare_age(const void *a, const void *b) {
    const employee *emp1 = (const employee *)a;
    const employee *emp2 = (const employee *)b;
    return emp1->age - emp2->age;
}

int compare_date_of_birth(const void *a, const void *b) {
    const employee *emp1 = (const employee *)a;
    const employee *emp2 = (const employee *)b;
    return strcmp(emp1->date_of_birth, emp2->date_of_birth);
}

int compare_salary(const void *a, const void *b) {
    const employee *emp1 = (const employee *)a;
    const employee *emp2 = (const employee *)b;
    return emp1->salary - emp2->salary;
}

void printEmployee(const employee *emp) {
    printf("Фамилия: %s\n", emp->family);
    printf("Имя: %s\n", emp->name);
    printf("Отчество: %s\n", emp->surname);
    printf("Должность: %s\n", emp->position);
    printf("Зарплата: %d\n", emp->salary);
    printf("Возраст: %d\n", emp->age);
    printf("Дата рождения: %s\n", emp->date_of_birth);
}

void print_arr(employee employees[], int size) {
    for (int i = 0; i < size; i++) {
        printEmployee(&employees[i]);
        printf("\n");
    }
}

void write_to_file(const char *filename, employee employees[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Ошибка открытия файла для записи");
        return;
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%s %s %s %s %d %d %s\n", employees[i].family, employees[i].name, employees[i].surname, employees[i].position, employees[i].salary, employees[i].age, employees[i].date_of_birth);
    }
    fclose(file);
}

void read_from_file(const char *filename, employee employees[], int size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Ошибка открытия файла для чтения");
        return;
    }

    for (int i = 0; i < size; i++) {
        fscanf(file, "%49s %49s %49s %49s %d %d %10s", employees[i].family, employees[i].name, employees[i].surname, employees[i].position, &employees[i].salary, &employees[i].age, employees[i].date_of_birth);
    }
    fclose(file);
}

int main() {
    setlocale(LC_ALL, "RUS");
    int num_employees, pick;
    printf("Введите количество сотрудников (5-10): ");
    scanf("%d", &num_employees);

    if (num_employees < 5 || num_employees > 10) {
        printf("Некорректное количество сотрудников. Программа завершена.\n");
        return 1;
    }

    employee employees[num_employees];
    fill_arr(employees, num_employees);

    do {
        printf("\t\t// Выберите действие, написанные снизу \\\\\n");
        printf("1. Загрузить данные из файла\n");
        printf("2. Изменение выбранной пользователем записи\n");
        printf("3. Поиск записи в массиве по одному полю, значение которого задал пользователь\n");
        printf("4. Сортировка массива по выбранному пользователем полю\n");
        printf("5. Сохранение измененного массива записей в новый файл\n");
        printf("6. Вывести массив\n");
        printf("0. Завершить работу\n");
        scanf("%i", &pick);

        switch (pick) {
            case 1:
                read_from_file("employees.txt", employees, num_employees);
                printf("// Данные успешно прочитаны! \\\\\n");
                break;
            case 2: {
                int index;
                printf("Введите индекс записи для изменения: ");
                scanf("%i", &index);
                if (index >= 0 && index < num_employees) {
                    printf("Введите новые данные для записи:\n");
                    printf("Фамилия: ");
                    scanf("%s", employees[index].family);
                    printf("Имя: ");
                    scanf("%s", employees[index].name);
                    printf("Отчество: ");
                    scanf("%s", employees[index].surname);
                    printf("Должность: ");
                    scanf("%s", employees[index].position);
                    printf("Зарплата: ");
                    scanf("%i", &employees[index].salary);
                    printf("Возраст: ");
                    scanf("%i", &employees[index].age);
                    printf("Дата рождения: ");
                    scanf("%s", employees[index].date_of_birth);
                } else {
                    printf("Некорректный индекс.\n");
                }
                break;
            }
            case 3: {
                int field;
                char search_value[50];
                printf("Выберите поле для поиска:\n");
                printf("1. Фамилия\n");
                printf("2. Имя\n");
                printf("3. Отчество\n");
                printf("4. Должность\n");
                printf("5. Зарплата\n");
                printf("6. Возраст\n");
                printf("7. Дата рождения\n");
                scanf("%i", &field);
                printf("Введите значение для поиска: ");
                scanf("%s", search_value);

                int found = 0;
                for (int i = 0; i < num_employees; i++) {
                    switch (field) {
                        case 1:
                            if (strcmp(employees[i].family, search_value) == 0) {
                                printEmployee(&employees[i]);
                                found = 1;
                            }
                            break;
                        case 2:
                            if (strcmp(employees[i].name, search_value) == 0) {
                                printEmployee(&employees[i]);
                                found = 1;
                            }
                            break;
                        case 3:
                            if (strcmp(employees[i].surname, search_value) == 0) {
                                printEmployee(&employees[i]);
                                found = 1;
                            }
                            break;
                        case 4:
                            if (strcmp(employees[i].position, search_value) == 0) {
                                printEmployee(&employees[i]);
                                found = 1;
                            }
                            break;
                        case 5:
                            if (employees[i].salary == atoi(search_value)) {
                                printEmployee(&employees[i]);
                                found = 1;
                            }
                            break;
                        case 6:
                            if (employees[i].age == atoi(search_value)) {
                                printEmployee(&employees[i]);
                                found = 1;
                            }
                            break;
                        case 7:
                            if (strcmp(employees[i].date_of_birth, search_value) == 0) {
                                printEmployee(&employees[i]);
                                found = 1;
                            }
                            break;
                    }
                }
                if (!found) {
                    printf("Запись не найдена.\n");
                }
                break;
            }
            case 4: {
                int field;
                printf("Выберите поле для сортировки:\n");
                printf("1. Фамилия\n");
                printf("2. Имя\n");
                printf("3. Отчество\n");
                printf("4. Должность\n");
                printf("5. Зарплата\n");
                printf("6. Возраст\n");
                printf("7. Дата рождения\n");
                scanf("%i", &field);

                switch (field) {
                    case 1:
                        qsort(employees, num_employees, sizeof(employee), compare_family);
                        break;
                    case 2:
                        qsort(employees, num_employees, sizeof(employee), compare_name);
                        break;
                    case 3:
                        qsort(employees, num_employees, sizeof(employee), compare_surname);
                        break;
                    case 4:
                        qsort(employees, num_employees, sizeof(employee), compare_position);
                        break;
                    case 5:
                        qsort(employees, num_employees, sizeof(employee), compare_salary);
                        break;
                    case 6:
                        qsort(employees, num_employees, sizeof(employee), compare_age);
                        break;
                    case 7:
                        qsort(employees, num_employees, sizeof(employee), compare_date_of_birth);
                        break;
                }
                printf("\nОтсортированный массив:\n");
                print_arr(employees, num_employees);
                break;
            }
            case 5: {
                char filename[50];
                printf("Введите имя файла для сохранения: ");
                scanf("%s", filename);
                write_to_file(filename, employees, num_employees);
                printf("// Данные успешно записаны в файл %s! \\\\\n", filename);
                break;
            }
            case 6:
                print_arr(employees, num_employees);
                printf("\n\n");
                break;
            case 0:
                printf("Программа завершена.\n");
                break;
            default:
                printf("Некорректный выбор. Попробуйте снова.\n");
        }
    } while (!pick);

    return 0;
}

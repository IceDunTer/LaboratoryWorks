#include <stdio.h>
#include <string.h>
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

void input_employee(struct employee *emp) {
    printf("Введите фамилию: ");
    scanf("%s", emp->family);
    printf("Введите имя: ");
    scanf("%s", emp->name);
    printf("Введите отчество: ");
    scanf("%s", emp->surname);
    printf("Введите должность: ");
    scanf("%s", emp->position);
    printf("Введите зарплату: ");
    scanf("%d", &emp->salary);
    printf("Введите возраст: ");
    scanf("%d", &emp->age);
    printf("Введите дату рождения (ДД.ММ.ГГГГ): ");
    scanf("%s", emp->date_of_birth);
}

void print_employee(const struct employee *emp) {
    printf("Фамилия: %s\n", emp->family);
    printf("Имя: %s\n", emp->name);
    printf("Отчество: %s\n", emp->surname);
    printf("Должность: %s\n", emp->position);
    printf("Зарплата: %i\n", emp->salary);
    printf("Возраст: %i\n", emp->age);
    printf("Дата рождения: %s\n", emp->date_of_birth);
}

void find_employees(struct employee *emp, int num) {
    int total_salary = 0;

    for (int i = 0; i < num; i++) {
       total_salary += emp[i].salary;
    }
    int avg_salary = total_salary / num;

    printf("\nСотрудники, у которых зарплата выше средней и возраст менее 30-ти лет:\n");
    for (int i = 0; i < num; i++) {
       if (emp[i].salary > avg_salary && emp[i].age < 30) {
              print_employee(&emp[i]);
              printf("\n");
       }
    }
}

int main() {
    int num_employees;
    printf("Введите количество сотрудников (5-10): ");
    scanf("%d", &num_employees);

    if (num_employees < 5 || num_employees > 10) {
       printf("Некорректное количество сотрудников. Программа завершена.\n");
       return 1;
    }

    struct employee employees[num_employees];

    for (int i = 0; i < num_employees; i++) {
       printf("\nВведите данные о сотруднике %d:\n", i + 1);
       input_employee(&employees[i]);
    }

    find_employees(employees, num_employees);
}

#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_length 100

typedef struct {
	char resolution[max_length];
	char mpixNum[max_length];
	char interface[max_length];
	char connectionType[max_length];
	char angle[max_length];

} Information;

Information database[max_length];
int InfoCount = 0;

void addInfo();
void findInfo();
void modInfo();
void printInfo();
void printSortedInfo();
void save();
void load();

int main() {
	setlocale(LC_ALL, "RUS");
	int pick = 1;
	do {
		printf("// Выберите действия, написанные снизу \\\\\n");
		printf("1. Добавить информацию о камере\n");
		printf("2. Найти информацию о камере\n");
		printf("3. Изменить информацию о камере\n");
		printf("4. Вывести информацию о камере\n");
		printf("5. Вывести отсортированную информацию о камере\n");
		printf("6. Сохранить файл\n");
		printf("7. Загрузить файл\n");
		printf("0. Завершить работу\n");
		scanf("%i", &pick);

		switch (pick) {
		case 1: 
			addInfo();
			break;
		case 2: 
			findInfo();
			break;
		case 3:
			modInfo();
			break;
		case 4:
			save();
			break;
		case 5:
			load();
			break;
		default:
			printf("Неправильно введено значение!\n\n");

		} 
	} while (pick != 0);
}

void addInfo() {
	if (InfoCount > max_length) {
		printf("Превышен лимит записи в базу данных!\n\n");
		return;
	}
	Information* i = &database[InfoCount];

	printf("// Запись камеры #%i \\\\\n", InfoCount);
	


}

void findInfo() {
	printf("Поиск информации о камере...\n\n");
}

void modInfo() {
	printf("Изменение информации о камере...\n\n");
}

void printInfo(); {
	printf("Вывожу информацию о камере...\n\n");
}

void printSortedInfo(); {
	printf("Сортирую и вывожу информацию о камере...\n\n");
}

void save() {
	printf("Сохранение файла...\n\n");
}

void load() {
	printf("Загрузка файла...\n\n");
}

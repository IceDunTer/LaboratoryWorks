#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <string.h>

void print_centered(const char* message) {
    char line[81];
    int len = strlen(message);
    int padding = (80 - len) / 2;

    for (int i = 0; i < 80; i++) {
        line[i] = '*';
    }
    line[80] = '\0';
    printf("%s\n", line);

    for (int i = 0; i < padding; i++) {
        line[i] = '*';
    }
    sprintf(line + padding, "%s", message);
    for (int i = padding + len; i < 80; i++) {
        line[i] = '*';
    }
    line[80] = '\0';
    printf("%s\n", line);

    for (int i = 0; i < 80; i++) {
        line[i] = '*';
    }
    line[80] = '\0';
    printf("%s\n", line);
}

int main() {
    setlocale(LC_ALL, "RUS");
    struct tm* mytime;
    time_t t;

    t = time(NULL);
    mytime = localtime(&t);

    char* months[] = { "Января", "Февраля", "Марта", "Апреля", "Мая", "Июня",
                      "Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря" };

    char time_message[50];
    char date_message[50];

    sprintf(time_message, "Московское время: %02i:%02i:%02i",
        mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

    sprintf(date_message, "Текущая дата: %i %s %i года",
        mytime->tm_mday, months[mytime->tm_mon], mytime->tm_year + 1900);

    print_centered(time_message);
    print_centered(date_message);
}

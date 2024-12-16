#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    struct tm *mytime;
    time_t t;

    t = time(NULL);
    mytime = localtime(&t);

    char *months[] = {"Января", "Февраля", "Марта", "Апреля", "Мая", "Июня",
                      "Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря"};

    printf("Московское время: %02d:%02d:%02d\n",
           mytime->tm_hour, mytime->tm_min, mytime->tm_sec);

    printf("Текущая дата: %d %s %d года\n",
           mytime->tm_mday, months[mytime->tm_mon], mytime->tm_year + 1900);
}

#include <stdio.h>
#include <math.h>
#include <locale.h>

struct point {
    float x;
    float y;
    char name;
};

typedef struct point Point;

float dist(Point z, Point w) {
    return sqrt(pow(z.x - w.x, 2) + pow(z.y - w.y, 2));
}

Point midpoint(Point z, Point w) {
    Point mid;
    mid.x = (z.x + w.x) / 2;
    mid.y = (z.y + w.y) / 2;
    return mid;
}

int quadrant(Point z) {
    if (z.x > 0 && z.y > 0) return 1;
    if (z.x < 0 && z.y > 0) return 2;
    if (z.x < 0 && z.y < 0) return 3;
    if (z.x > 0 && z.y < 0) return 4;
    return 0; // Точка находится либо на оси oX, либо на оси oY
}

void put_point(Point z) {
    printf("Point %c (%0.1f, %0.1f)\n", z.name, z.x, z.y);
}

int main() {
    Point a, b;
    a = (Point) { 1.0f, 2.0f, 'A' };
    b.name = 'B';
    b.x = 5;
    b.y = -3;

    put_point(a);
    put_point(b);

    printf("Расстояние между A и B: %0.2f\n", dist(a, b));

    Point mid = midpoint(a, b);
    printf("Середина отрезка AB: (%0.1f, %0.1f)\n", mid.x, mid.y);

    // Определение координатной четверти точки
    printf("Точка А лежит в четверти: %i\n", quadrant(a));
    printf("Точка В лежит в четверти: %i\n", quadrant(b));

}

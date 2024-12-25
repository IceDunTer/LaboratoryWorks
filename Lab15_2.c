#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

#define ROW 7
#define COL 7

void fill_elements(int arr[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr[i][j] = rand() % 21 - 10;
        }
    }
}

void print_array(int arr[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%4i ", arr[i][j]);
        }
        printf("\n");
    }
}

void transpose_array(int arr[ROW][COL], int ts[COL][ROW]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            ts[j][i] = arr[i][j];
        }
    }
}

int nonzero_elem_in_first_row(int arr[ROW][COL]) {
    int count = 0;
    for (int j = 0; j < COL; j++) {
        if (arr[0][j] != 0) count++;
    }
    return count;
}

int pairs_in_columns(int arr[ROW][COL]) {
    int count = 0;
    for (int j = 0; j < COL; j++) {
        for (int i = 0; i < ROW - 1; i++) {
            if (arr[i][j] == arr[i + 1][j]) {
                count++;
            }
        }
    }
    return count;
}

char* max_elem(int arr[ROW][COL]) {
    int max = arr[0][0];
    int m_i = 0, m_j = 0;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
                m_i = i;
                m_j = j;
            }
        }
    }

    static char ans[20];
    sprintf(ans, "%i | %i", m_i, m_j);
    return ans;
}

int main() {
    setlocale(LC_ALL, "RUS");
    int array[ROW][COL];
    int transposed[COL][ROW];

    srand(time(NULL));

    fill_elements(array);
    printf("// Исходный массив: \\\\\n");
    print_array(array);

    transpose_array(array, transposed);
    printf("\n// Транспонированный массив: \\\\\n");
    print_array(transposed);

    printf("\nКоличество ненулевых элементов в первой строке: %i\n", nonzero_elem_in_first_row(array));
    printf("Количество пар одинаковых соседних элементов в столбцах: %i\n", pairs_in_columns(array));
    printf("Координаты максимального элемента (x | y): %s\n", max_elem(array));

    return 0;
}

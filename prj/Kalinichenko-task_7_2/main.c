#include <stdio.h>


void processNumbers() {
    double numbers[15];
    int count = 0;

    printf("Введіть 15 чисел:\n");
    for (int i = 0; i < 15; i++) {
        while (1) {
            printf("Число %d: ", i + 1);
            if (scanf("%lf", &numbers[i]) == 1) {
                break;
            } else {
                printf("Введено некоректне значення. Будь ласка, введіть число.\n");
                while(getchar() != '\n');
            }
        }
    }

    for (int i = 0; i < 15; i++) {
        if (numbers[i] > 3.50 && numbers[i] < 150.02) {
            count++;
        }
    }

    printf("\nЧисла у зворотному порядку:\n");
    for (int i = 14; i >= 0; i--) {
        printf("%.2lf ", numbers[i]);
    }

    printf("\n\nКількість чисел, більших за 3.50 і менших за 150.02: %d\n", count);
}

int main() {
    char repeat;

    do {
        processNumbers();

        printf("\nПовторити виконання програми? (Y/N): ");
        scanf(" %c", &repeat);
        repeat = (repeat == 'Y' || repeat == 'y') ? 'Y' : 'N';

    } while (repeat == 'Y' || repeat == 'y');

    printf("Програма завершена.\n");
    return 0;
}

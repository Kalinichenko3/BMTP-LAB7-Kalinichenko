#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_LEN 1000

// Функция для удаления пробелов и знаков препинания в конце строки
void trim_trailing_whitespace_and_punctuation(char *str) {
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '.' || str[len - 1] == ',' || str[len - 1] == '!')) {
        str[len - 1] = '\0';
        len--;
    }
}

int main() {
    // Устанавливаем локаль для корректного отображения украинского языка
    setlocale(LC_ALL, "uk_UA.UTF-8");

    char sentence[MAX_LEN];

    printf("Введіть речення: ");
    // Используем scanf для ввода строки
    scanf("%[^\n]", sentence);

    // Получаем длину строки
    size_t len = strlen(sentence);

    // Проверка корректного завершения предложения
    if (len >= 3 && strcmp(&sentence[len - 3], "...") == 0) {
        printf("Речення має коректне завершення.\n");
    } else if (len >= 1 && sentence[len - 1] == '.') {
        printf("Речення має коректне завершення.\n");
    } else {
        printf("Речення має некоректне завершення.\n");
    }

    // Копируем строку и очищаем её от пунктуации для поиска "масив"
    char sentence_copy[MAX_LEN];
    strcpy(sentence_copy, sentence);
    trim_trailing_whitespace_and_punctuation(sentence_copy);

    // Проверка наличия слова "масив"
    if (strstr(sentence_copy, "масив") != NULL) {
        printf("У реченні є слово 'масив'.\n");
    } else {
        printf("У реченні немає слова 'масив'.\n");
    }

    return 0;
}

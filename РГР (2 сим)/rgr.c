#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 256
#define COUNT 3

int main() {
    char *texts[COUNT] = {
        "I love dogs",
        "Programming is interesting",
        "Practice every day"
    };

    srand(time(NULL));

    int index = rand() % COUNT;
    char *text = texts[index];

    char input[MAX_LEN];

    printf("Введите следующий текст:\n");
    printf("%s\n\n", text);

    printf("Ваш ввод:\n");

    time_t start = time(NULL);

    fgets(input, MAX_LEN, stdin);

    time_t end = time(NULL);

    input[strcspn(input, "\n")] = '\0';

    int correct = 0;
    int errors = 0;

    int i = 0; 
    int j = 0;

    while (input[i] != '\0' && text[j] != '\0') {

        if (input[i] == text[j]) {
            correct++;
            i++;
            j++;
        }
        else {

            errors++;

            if (input[i + 1] == text[j]) {
                printf("Ошибка: лишний символ '%c'\n", input[i]);
                i++;
            }
            else if (input[i] == text[j + 1]) {
                printf("Ошибка: пропущен символ '%c'\n", text[j]);
                j++;
            }
            else {
                printf("Ошибка: '%c' вместо '%c'\n",
                       input[i], text[j]);
                i++;
                j++;
            }
        }
    }

    while (input[i] != '\0') {
        errors++;
        i++;
    }

    while (text[j] != '\0') {
        errors++;
        j++;
    }

    printf("\n=== Результат ===\n");
    printf("Правильно введенных символов: %d\n", correct);
    printf("Ошибочных символов: %d\n", errors);
    printf("Затраченное время: %ld секунд\n", end - start);

    if (errors == 0)
        printf("Сообщение: Текст введен без ошибок.\n");
    else
        printf("Сообщение: В тексте есть ошибки.\n");

    return 0;
}
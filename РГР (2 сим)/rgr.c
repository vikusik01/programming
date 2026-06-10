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
        "Practice every day",
    };

    char input[MAX_LEN];

    srand(time(NULL));

    int index = rand() % COUNT;
    char *text = texts[index];

    printf("Введите следующий текст:\n");
    printf("%s\n\n", text);

    printf("Ваш ввод:\n");

    time_t start = time(NULL);
    fgets(input, MAX_LEN, stdin);
    time_t end = time(NULL);

    input[strcspn(input, "\n")] = '\0';

    int correct = 0;
    int errors = 0;

    int lenText = strlen(text);
    int lenInput = strlen(input);

    int minLen = lenText < lenInput ? lenText : lenInput;

    for (int i = 0; i < minLen; i++) {
        if (input[i] == text[i])
            correct++;
        else
            errors++;
    }

    errors += abs(lenText - lenInput);

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
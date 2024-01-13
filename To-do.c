#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TaskMenager.h"

int main() {
    int choice;
    int indexInput;
    int running = 1;

    char taskInput[100];

    while (running) {
        printf("\nOpcje\n\n");
        printf("1. Dodaj nazwę zadania\n");
        printf("2. Wyświetl zadania\n");
        printf("3. Odhacz wykonane zadanie\n");
        printf("4. Edytuj zadanie\n");
        printf("5. Usuń zadanie\n");
        printf("6. Zapisz zadania\n");
        printf("7. Exit\n\n");
        printf("Wprowadź wybór: 1, 2, 3, 4, 5, 6, 7: ");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice) {
        case 1:
            printf("Wpisz zadanie do wykonania: ");
            getchar();
            fgets(taskInput, sizeof(taskInput), stdin);
            taskInput[strcspn(taskInput, "\n")] = '\0';

            addTask(taskInput);
            break;

        case 2:
            printf("Zadania do wykonania:\n\n");
            listTasks();
            break;

        case 3:
            printf("Które zadanie chcesz odhaczyć? \n");
            listTasks();
            scanf("%d", &indexInput);
            markCompleted(indexInput);
            break;

        case 4:
            printf("Wpisz które zadania chcesz edytować: \n");
            listTasks();
            scanf("%d", &indexInput);
            printf("Wpisz jakie zmiany chcesz dokonać: ");

            getchar();
            fgets(taskInput, sizeof(taskInput), stdin);
            taskInput[strcspn(taskInput, "\n")] = '\0';

            editTask(indexInput, taskInput);
            break;

        case 5:
            printf("Wpisz które zadanie chcesz usunąć: \n");
            listTasks();
            scanf("%d", &indexInput);
            deleteTask(indexInput);
            break;

        case 6:
            printf("Wpisz nazwę pliku do zapisu: ");
            getchar();
            fgets(taskInput, sizeof(taskInput), stdin);
            taskInput[strcspn(taskInput, "\n")] = '\0';
            saveTasksToFile(taskInput);
            break;

        case 7:
            running = 0;
            break;

        default:
            printf("Niepoprawny wybór\n");
            break;
        }
    }

    for (int i = 0; i < length; i++) {
        free(tasks[i].task);
    }
    free(tasks);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TaskMenager.h"
#include <time.h>



int main() {

    const char *fileName = "your_file.txt";
    readFromFile(fileName);
    int choice;
    int indexInput;
    int running = 1;
    int nazwaUzytkownikaWprowadzona = 0; 
    char taskInput[100];
  
  

    while (!nazwaUzytkownikaWprowadzona) {
        zapiszNazweUzytkownika();
        nazwaUzytkownikaWprowadzona = 1; 
    }
    
  
    while (running) {
        printf("\n");
      printf("<=============To-Do==============>\n\n");
        timer();
        printf("\nOpcje\n\n");
        printf("1. Dodaj nazwę zadania\n");
        printf("2. Wyświetl zadania\n");
        printf("3. Odhacz wykonane zadanie\n");
        printf("4. Edytuj zadanie\n");
        printf("5. Usuń zadanie\n");
        printf("6. Zapisz zadania\n");
        printf("7. Czas zadania\n");
        printf("8. Kalendarz\n");
        printf("9. Wczytaj plik\n\n");
        printf("10. Exit\n\n");
        printf("<===============================>\n");
        printf("Wprowadź wybór: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10: ");
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
          printf("Wprowadź numer zadania (1-%d), aby rozpocząć śledzenie czasu: ",                         length);
          scanf("%d", &indexInput);
          startTaskTimer(indexInput);
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
                      printf("Które zadanie chcesz sprawdzić czas? \n");{
                      listTasks();
                      printf("Wprowadź numer zadania (1-%d), aby sprawdzić czas: ", length);
                      scanf("%d", &indexInput);
                      displayTimeSpent(indexInput);
                      break;
          }


          case 8:
          calendar();
          break;
        
          case 9:
          readFromFile(fileName);
          break;
          
          case 10:
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







        

        

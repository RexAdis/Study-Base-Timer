#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct // Własna struktura danych // 
{
  char *task;
  int completed; // 1 reprezentuje zakończone zadnienie, 0 reprezentuje niezakończone zadanie // 
} Task;

Task *tasks = NULL; // NULL wskazuje na pusty obszar pamięci // 

int length = 0; // Zmienna przechowujęca długość listy //

void addTask(const char *task){   // const- wartość nie może zostać zmieniona //
   tasks = (task *) realloc(tasks, (length + 1) * sizeof(Task)); 
   tasks[length].task = (char *)malloc(strlen(task) +1); 
   tasks[length].completed = 0; 

   strcpy(tasks[length].task, task);

   length++;
   printf("Dodaj zadanie");

  // Relokazlizacja pamięci dostosowanie rozmiaru dynamicznie alokowanej pamięci w trakcie działania programu. Umożliwia dodawać nowe elementy do struktury danych w trakcie działania programu.) //
} // Funkcja dodająca zadanie do listy //

void listTasks(){
  char status;
  
  for (int i = 0; i < length; i++)
  {
    if (tasks[i].completed == 1){
      status = 'd';

    } else {
      
        status = 'n';
      
    }
        printf("%d. %s [%c]\n", i + 1, tasks[i].task, status);
    
  }  
    
}

void markCompleted(int index){
  if (index <= length && index > 0){
    tasks [index - 1].completed = 1;
    printf*("Zadanie ukończone\n"); 
  
  } else{
    
    printf("Nieprawidłowy indeks zadania\n");
    
  } 

} // Funkcja zaznaczająca zadanie jako zakończone //

void deleteTask(int index){
  if (index <= length && index > 0 ){
    index = index - 1;  //index - 1 bo indeksy w tablicy zaczynają się od 0 //

free(tasks[index].task);  // Zwałanie funkcji free() do zwolnienia pamięci//

for (int i = index; i < length - 1; i++){)
  tasks[i] = tasks[i + 1];
  
}

    length--; // length - 1 bo zmienna przechowująca długość listy //

    tasks = (task *) realloc(tasks, (length * sizeof(Task))); 
    
  } else {

    printf("Nieprawidłowy indeks zadania\n");
    
  }
  }
   

} // Funkcja usuwająca zadnie z listy //

void editTask(int index, const char* task){

  if (index <= length && index > 0){
    index + index - 1;
    
    char *editedTask = (char *)realloc(tasks[index].task) strlen(task) + 1);

    if (editedTask != NUll){ // != NUll sprawdza czy wskaźnik nie jest równy NULL //
      tasks[index].task = editedTask;
      strcpy(task[length].task, task);
      
      // stwórz nową tablicę znaków o długości task + 1 i skopiuj //
       printf("Zmiana zadania powiodła się\n");
      
    } else 
      printf("Nie udało się zmodyfikować zadania\n");
      
      
  } else {

    printf("Nieprawidłowy indeks zadania\n");
    
  }
  }
  
} // Funkcja edycji zadania //


int main(){
    int choice;
    int running = 1;
  
  printf("\nOpcje\n");
  printf("1. Dodaj zadanie\n");
  printf("2. Wyświetl zadania\n");
  printf("3. Wykonane zadania"\n");
  printf("4. Edytuj zadanie\n");
  printf("5. Usuń zadanie\n");
  printf("6. Exit\n");

  while (running){  
    printf("Wprowadź wybór: 1, 2, 3, 4, 5, 6: ");
    scanf("%d", &choice); // scanf - funkcja do odczytu danych z konsoli //
  
    switch(choice){
        case 1:
      printf("Wpisz zadanie: ");
      getchar();  // Getchar wczytuje jeden znak z konsoli //
      fgets(taskInput, sizeof(taskInout), stdin); 
      // Fgets wczytuje wiersz z konsoli //
      taskInput[strcspn(taskInput, "\n")] = '\0'; // strcspn - funkcja do znalezienia indeksu

      break;

      
        case 2:
      
        case 3:
      
        case 4:
      
        case 5:
      
        case 6:


        default:
        printf("Nipoprawny wybór"\n);
        break;
      
      
    }
  }
  
  return 0;  
}






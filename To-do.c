#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct // Własna struktura danych // 
{
  char *task;
  int completed; // 1 reprezentuje zakończone zadnienie, 0 reprezentuje niezakończone zadanie // 
} Task;

Task *tasks = NULL; // NULL wskazuje na pusty obszar pamięci // 

int lenght = 0; // Zmienna przechowujęca długość listy //

void addTask(const char *task){   // const- wartość nie może zostać zmieniona //
   tasks = (task *) realloc(tasks, (lenght + 1) * sizeof(Task)); 
   tasks[lenght].task = (char *)malloc(strlen(task) +1); 
   tasks[lenght].completed = 0; 

   strcpy(tasks[lenght].task, task);

   lenght++;
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
        print("%d. %s [%c]\n", i + 1, tasks[i].taks, status);
    
  }  
    
}

void markCompleted(int index){
  if (index <= lenght && index > 0){
    tasks [index - 1].completed = 1;
    printf*("Zadanie ukończone\n"); 
  
  } else{
    
    printf("Nieprawidłowy indeks zadania\n");
    
  } 

} // Funkcja zaznaczająca zadanie jako zakończone //

void deleteTask(int index){
  if (index <= lenght && index > 0 ){
    index = index - 1;  //index - 1 bo indeksy w tablicy zaczynają się od 0 //

free(tasks[index].task);  // Zwałanie funkcji free() do zwolnienia pamięci//

for (int i = index; i < length - 1; i++){)
  tasks[i] = tasks[i + 1];
  
}

    length--; // lenght - 1 bo zmienna przechowująca długość listy //

    tasks = (task *) realloc(tasks, (lenght * sizeof(Task))); 
    
  } else {

    printf("Nieprawidłowy indeks zadania\n");
    
  }
  }
   

} // Funkcja usuwająca zadnie z listy //

void editTask(int index, const char* task){

  if (index <= lenght && index > 0){
    index + index - 1;
    
    char *editTask = (char *)realloc(tasks[index].task) strlen(task) + 1);

    if (editTask != NUll){ // != NUll sprawdza czy wskaźnik nie jest równy NULL //
      tasks[index].task = editTask;
      
    } else 
      printf("Nie udało się zmodyfikować zadania\n");
      
      
  } else {

    printf("Nieprawidłowy indeks zadania\n");
    
  }
  }
  
} // Funkcja edycji zadania //


int main(){
  
}






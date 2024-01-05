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
   tasks = (task *) realloc(tasks, (lenght + 1) * sizeof(Task)); // Relokazlizacja pamięci dostosowanie rozmiaru dynamicznie alokowanej pamięci w trakcie działania programu. Umożliwia dodawać nowe elementy do struktury danych w trakcie działania programu.) //
} // Funkcja dodająca zadanie do listy //

void markCompleted(){
  
} // Funkcja zaznaczająca zadanie jako zakończone //

void deleteTask(){

} // Funkcja usuwająca zadnie z listy //

void editTask(){
  
} // Funkcja edycji zadania //







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




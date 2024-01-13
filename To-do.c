#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h>
#include <time.h>

typedef struct {
  char *task;
  int completed; 
} Task;

Task *tasks = NULL;
int length = 0; // tablice ustawiamy na 0 // 

void addTask(const char *task) {
  tasks = (Task *)realloc(tasks, (length + 1) * sizeof(Task)); // sizeof- podaje ilość pamięci w bajtach, wymaganą do przechowywania obiektu // 
  tasks[length].task = (char *)malloc(strlen(task) + 1); // malloc powoduje alokację pamięci w bajtach, wymaganą do przech zadania //
  tasks[length].completed = 0; // po dodaniu zadania od razu ustawione jest na 0 // 

  strcpy(tasks[length].task, task);

  length++;
  printf("Dodano zadanie do wykonania\n\n");
}

void listTasks() {
  const char* status;

  const char* ComStatus = "Wykonane";
  const char* NahStatus = "Nie wykonane";

  for (int i = 0; i < length; i++) { // rozpoczyna się od wartości i = 0 (pierwszy element w tablicy) i wykonuje się, dopóki i jest mniejsze niż length (liczba zadań w tablicy). Po każdej iteracji zwiększa i o 1 (i++). //
    if (tasks[i].completed == 1) {
      status = ComStatus;
    } else {
      status = NahStatus;
    }
    printf("%d. %s [%s]\n", i + 1, tasks[i].task, status);

    // %d: To format specyfikator dla liczby całkowitej (int). Wstawia wartość i + 1, czyli numer zadania zaczynając od 1 (zamiast od 0, ponieważ i jest indeksem tablicy, a numerowanie zaczynamy od 1).
   // %s: To format specyfikator dla ciągu znaków (char *). Wstawia treść zadania, która jest przechowywana w polu task struktury Task dla zadania o indeksie i. //
   // [%s]: Ponownie format specyfikator dla ciągu znaków (char *). Wstawia status zadania, który został wcześniej ustawiony jako "Wykonane" lub "Nie wykonane". // 
    
  }
  printf("\n\n");
}

void markCompleted(int index) {
  if (index <= length && index > 0) { // Sprawdza, czy przekazany indeks index mieści się w zakresie poprawnych indeksów dla tablicy zadań, musi tez byc wiekszy od 0 poniewaz musi istniec jakies zadniae // 
    tasks[index - 1].completed = 1; // dajemy - 1 zeby zadanie bylo nie wykonanen a nastepninie zmieniamy na 1 co oznacza wykonane // 
    printf("Zadanie ukończone\n"); 
  } else {
    printf("Nieprawidłowy indeks zadania\n"); // jezeli podamy zly indeks da nam ten rezultat // 
  } 
}

void deleteTask(int index) {
  if (index <= length && index > 0 ) {
    index = index - 1;

    free(tasks[index].task);

    for (int i = index; i < length - 1; i++) {
      tasks[i] = tasks[i + 1];
    }

    length--;

    tasks = (Task *)realloc(tasks, (length * sizeof(Task))); 
  } else {
    printf("Nieprawidłowy indeks zadania\n");
  }
}

void editTask(int index, const char* task) {
  if (index <= length && index > 0) {
    index = index - 1;

    char *editedTask = (char *)realloc(tasks[index].task, strlen(task) + 1);

    if (editedTask != NULL) {
      tasks[index].task = editedTask;
      strcpy(tasks[index].task, task);

      printf("Zmiana zadania powiodła się\n");
    } else {
      printf("Nie udało się zmodyfikować zadania\n");
    }
  } else {
    printf("Nieprawidłowy indeks zadania\n");
  }
}

void saveTasksToFile(const char *filename, const char *text) {
  FILE *plik = fopen(filename, "w");
  if plik = NULL;
  {
    printf("Błąd podczas zapisywanie zapisu.\n");
    return;
  }

  fprintf(plik, %s, text);
  fclose(plik);
  printf("Zapisano pliko o nazwie %s.\n", filename);
}

  



int main() {

  
  int choice;
  int indexInput;
  int running = 1;

  char taskInput[100]; // maksymalna liczba znakowow //


  

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

    switch(choice) {
      case 1:
        printf("Wpisz zadanie do wykonania: ");
        getchar(); // getchar pozwala na wczytanie znaku z klawiatury //
        fgets(taskInput, sizeof(taskInput), stdin); // wczytanie taskInput zeby nie przepelnic bufora //
        taskInput[strcspn(taskInput, "\n")] = '\0'; // strcspn - znajduje indeks znaku w tablicy // 

        addTask(taskInput); // wykonuje funkcje dodającą zadanie do listy // 
        break;

      case 2:
        printf("Zadanie do wykonania:1\n\n");
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
        printf("Wpisz które zadanie chcesz usnunąć: \n");
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

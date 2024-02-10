#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TaskMenager.h"
#include <time.h>


int get_1st_weekday(int year) {
    int d;
    d = ((year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year) / 400 + 1) % 7;
    return d;
}

void calendar() {
    int year, month, day, daysInMonth, weekDay = 0, startingDay;
    printf("\nWybierz rok: ");
    scanf("%d", &year);

    char *months[] = {"styczen", "luty", "marzec", "kwiecien", "maj", "czerwiec", "lipiec", "wrzesien", "pazdziernik", "listopad", "grudzien"};
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDay[1] = 29;

    startingDay = get_1st_weekday(year);

    for (month = 0; month < 12; month++) {
        daysInMonth = monthDay[month];
        printf("\n\n--------------%s--------------\n", months[month]);
        printf("\n  Pon  Wt  Sr  Czw  Pt  Sob  Niedz");

        for (weekDay = 0; weekDay < startingDay; weekDay++) {
            printf("\n\n   ");
        }

        for (day = 1; day <= daysInMonth; day++) {
            printf("%4d", day);

            if (++weekDay > 6) {
                printf("\n");
                weekDay = 0;
            }
        }

        startingDay = weekDay;
    }
}

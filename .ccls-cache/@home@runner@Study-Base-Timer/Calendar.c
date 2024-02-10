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

    for (month = 0; month < 12; month++) {
        daysInMonth = monthDay[month];
        printf("\n\n--------------%s--------------\n", months[month]);
        printf("\n  Pon  Wt  Śr  Czw  Pt  Sob  Niedz");

        // Calculate spacing based on month name length
        int monthNameLength = strlen(months[month]);
        int spacing = (28 - monthNameLength) / 2;

        for (weekDay = 0; weekDay < spacing; weekDay++) {
            printf("    ");
        }

        for (day = 1; day <= daysInMonth; day++) {
            printf("%5d", day);

            if (++weekDay > 6) {
                printf("\n");
                weekDay = 0;
            }
        }

        printf("\n");
    }
}

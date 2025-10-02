#include <stdio.h>

/*
 *  A week has 7 * 24 * 60 * 60 = 604800 seconds.
 *  650 sekunder er 0 uger, 0 dage, 0 timer, 10 minutter og 50 sekunder
 */


int aflevering1(void) {
    char escape = 'N';
    int seconds;
    int sec, min, hours, days, week;

    while (escape != 'Y' && escape != 'y') {
        printf("Please enter a number: ");
        scanf("%d", &seconds);

        /*
         * calculation
         */
        sec = seconds % 60;
        min = (seconds / 60) % 60;
        hours = (seconds / 3600) % 24;
        days  = (seconds / 86400) % 7;
        week  = seconds / 604800;        // full weeks
        printf("*******************************\n");
        printf("%d seconds is: %d:%d:%d:%d:%d \n", seconds, week, days, hours, min, sec);
        printf("*******************************\n");

        printf("want to escape? (Y / N): ");
        scanf(" %c", &escape);
    }
    return 0;
}
